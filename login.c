#include "headers/includes.h"

TTF_Font *font;
SDL_Rect inputRect;
SDL_Event event;
MYSQL *conn;


void login(SDL_Window *window, SDL_Renderer *renderer, Player player) {
    if (!loadFont()) {
        return;
    }

    char inputText[11] = "";
    int textLimit = 0;
    int continueGame = 1;

    while (continueGame) {
        while (SDL_PollEvent(&event) != 0) {
            if (event.type == SDL_QUIT) {
                continueGame = 0;
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
                    insertPlayer(inputText, &player); 
                    inputText[0] = '\0';
                    textLimit = 0;
                    renderWelcomeScreen(renderer, font);
                    game(window, renderer, &player);
                } else if (event.key.keysym.sym == SDLK_BACKSPACE) {
                    if (strlen(inputText) > 0) {
                        inputText[strlen(inputText) - 1] = '\0';
                        textLimit = 0; 
                    }
                }
            }

            
            SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
            SDL_RenderClear(renderer);
            // SDL_Surface *usernameSurface = TTF_RenderText_Solid(font, "Username: ", (SDL_Color){0, 0, 0, 255});
            // SDL_Texture *usernameTexture = SDL_CreateTextureFromSurface(renderer, usernameSurface);
            renderText2("Username :", renderer, font, 1, 1);
            SDL_Surface *textSurface = TTF_RenderText_Solid(font, inputText, (SDL_Color){0, 0, 0, 255});
            SDL_Texture *textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);
            SDL_RenderCopy(renderer, textTexture, NULL, &inputRect);
            SDL_FreeSurface(textSurface);
            SDL_DestroyTexture(textTexture);

            SDL_RenderPresent(renderer);
        }


    }
}

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
        fprintf(stderr, "Erreur lors de la connexion avec la base de donnÃ©es: %s\n", mysql_error(conn));
        return 0;
    }


    return 1;
}

void insertPlayer(const char *nickname, Player *player) {
    MYSQL_RES *res;

    conn = mysql_init(NULL);
    if (conn == NULL) {
        fprintf(stderr, "Erreur lors de l'initialisation de mysql: %s\n", mysql_error(conn));
        return;
    }

    if (mysql_real_connect(conn, "localhost", "root", "root", "esgisim", 0, NULL, 0) == NULL) {
        fprintf(stderr, "Erreur lors de la connexion avec la base de données: %s\n", mysql_error(conn));
        mysql_close(conn);
        return;
    }

    char selectQuery[256];
    snprintf(selectQuery, sizeof(selectQuery), "SELECT * FROM player WHERE nickname = '%s'", nickname);
    if (mysql_query(conn, selectQuery)) {
        fprintf(stderr, "Erreur de syntaxe SQL: %s\n", mysql_error(conn));
        mysql_close(conn);
        return;
    }

    res = mysql_store_result(conn);

    if (res == NULL) {
        fprintf(stderr, "mysql_store_result() failed\n");
        printf("Erreur lors de la vérification du pseudo existant !\n");
        mysql_close(conn);
        return;
    }

    if (mysql_num_rows(res) > 0) {
        printf("Ce pseudo existe déjà !\n");
        mysql_free_result(res);
        mysql_close(conn);
        return;
    }

    mysql_free_result(res);

    char insertSQL[256];
    snprintf(insertSQL, sizeof(insertSQL), "INSERT INTO player (nickname) VALUES ('%s');", nickname);

    if (mysql_query(conn, insertSQL)) {
        fprintf(stderr, "Erreur de syntaxe SQL: %s\n", mysql_error(conn));
        mysql_close(conn);
        return;
    }

    printf("Joueur ajouté avec succès !\n");

    mysql_close(conn);
    strncpy(player->nickname, nickname, sizeof(player->nickname) - 1);
}

void renderText2(const char *text, SDL_Renderer *renderer, TTF_Font *font, int x, int y){
    SDL_Color textColor = {0, 0, 0};

    SDL_Surface *textSurface = TTF_RenderText_Solid(font, text, textColor);
    SDL_Texture *textTexture = SDL_CreateTextureFromSurface(renderer, textSurface);

    SDL_Rect textPosition = {x * BLOC_SIZE, y * BLOC_SIZE, textSurface->w, textSurface->h};

    // printf("\nRendu : %s", text);
    SDL_RenderCopy(renderer, textTexture, NULL, &textPosition);

    SDL_FreeSurface(textSurface);
    SDL_DestroyTexture(textTexture);
}