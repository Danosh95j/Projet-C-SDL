#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <stdio.h>
#include <ctype.h>
#include "mysql/include/mysql.h"   

TTF_Font *font;
SDL_Rect inputRect;
SDL_Event event;
int continuer = 1;
MYSQL *conn;

int loadFont() {

    if (TTF_Init() == -1) {
        fprintf(stderr, "Erreur lors de l'initialisation de SDL_ttf : %s\n", TTF_GetError());
        return 0;
    }

    font = TTF_OpenFont("font/PressStart2P-Regular.ttf", 28);
    if (font == NULL) {
        fprintf(stderr, "Erreur lors du chargement de la police : %s\n", TTF_GetError());
        return 0;
    }

    inputRect.x = 100;
    inputRect.y = 100;
    inputRect.w = 400;
    inputRect.h = 100;

    conn = mysql_init(NULL);
    if (conn == NULL) {
        fprintf(stderr, "Erreur lors de l'initialisation de mysql: %s\n", mysql_error(conn));
        return 0;
    }

    if (mysql_real_connect(conn, "localhost", "root", "root", "esgisim", 0, NULL, 0) == NULL) {
        fprintf(stderr, "Erreur lors de la connexion avec la base de données: %s\n", mysql_error(conn));
        return 0;
    }


    return 1;
}

void insertPlayer(const char *nickname) {
    char insertSQL[256];
    snprintf(insertSQL, sizeof(insertSQL), "INSERT INTO player (nickname) VALUES ('%s');", nickname);

    if (mysql_query(conn, insertSQL)) {
        fprintf(stderr, "Erreur de syntaxe sql: %s\n", mysql_error(conn));
    }
}

void renderText(const char *text, SDL_Renderer *renderer, TTF_Font *font, int x, int y){
    SDL_Color textColor = {255, 253, 252};

    SDL_Surface *textSurface = TTF_RenderText_Solid(font, text, textColor);
    SDL_Texture *textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);

    SDL_Rect textPosition = {x * BLOC_SIZE, y * BLOC_SIZE, textSurface->w, textSurface->h};

    // printf("\nRendu : %s", text);
    SDL_RenderCopy(renderer, textTexture, NULL, &textPosition);

    SDL_FreeSurface(textSurface);
    SDL_DestroyTexture(textTexture);
}

void login(SDL_Window *window, SDL_Renderer *renderer) {
    if (!loadFont()) {
        return;
    }

    char inputText[11] = "";
    int textLimit = 0;

while (continuer) {
        while (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) {
                continuer = 0;
            } else if (event.type == SDL_TEXTINPUT && !textLimit) {
                for (int i = 0; event.text.text[i] != '\0'; i++) {
                    if (isalpha(event.text.text[i])) {
                        if (strlen(inputText) + 1 <= 10) {
                            strcat(inputText, event.text.text + i);
                        } else {
                            textLimit = 1;
                            break;
                        }
                    }
                }
            } else if (event.type == SDL_KEYDOWN) {
                if (event.key.keysym.sym == SDLK_RETURN) {
                    printf("Texte saisi par player : %s\n", inputText);
                    insertPlayer(inputText); 
                    inputText[0] = '\0';
                    textLimit = 0; 
                } else if (event.key.keysym.sym == SDLK_BACKSPACE) {
                    if (strlen(inputText) > 0) {
                        inputText[strlen(inputText) - 1] = '\0';
                        textLimit = 0; 
                }
            }
        }


        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);
        SDL_Surface *usernameSurface = TTF_RenderText_Solid(font, "Username: ", (SDL_Color){0, 0, 0, 255});
        SDL_Texture *usernameTexture = SDL_CreateTextureFromSurface(renderer, usernameSurface);

        SDL_Surface *textSurface = TTF_RenderText_Solid(font, inputText, (SDL_Color){0, 0, 0, 255});
        SDL_Texture *textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
        SDL_RenderCopy(renderer, textTexture, NULL, &inputRect);
        SDL_FreeSurface(textSurface);
        SDL_DestroyTexture(textTexture);

        SDL_RenderPresent(renderer);
    }


}
}
