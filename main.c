#include <SDL2/SDL.h>
#include <stdio.h>
#include <SDL2/SDL_image.h>
#include "mysql/include/mysql.h"   
#include <SDL2/SDL_ttf.h>

void renderWelcomeScreen(SDL_Renderer *renderer, TTF_Font *font);
void game(SDL_Window* window, SDL_Renderer* renderer);
void deathrun(SDL_Window* window, SDL_Renderer* renderer);
void revive(SDL_Window *window, SDL_Renderer *renderer);
void over(SDL_Window *window, SDL_Renderer *renderer);
void login(SDL_Window *window, SDL_Renderer *renderer);
void renderText(const char *text, SDL_Renderer *renderer, TTF_Font *font, int x, int y);
    int continueGame = 1;

int main(int argc, char* argv[]) {
    SDL_Window* window = NULL;
    SDL_Renderer* renderer = NULL;
    SDL_Event event;

    if (TTF_Init() != 0) {
        fprintf(stderr, "Erreur lors de l'initialisation de SDL_ttf : %s\n", TTF_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    TTF_Font *font = TTF_OpenFont("font/PressStart2P-Regular.ttf", 24);
    if (font == NULL) {
        fprintf(stderr, "Erreur lors du chargement de la police : %s\n", TTF_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        TTF_Quit();
        SDL_Quit();
        return 1;
    }

    if (SDL_Init(SDL_INIT_VIDEO) != 0) {
        printf("Erreur lors de l'initialisation de SDL : %s\n", SDL_GetError());
        return 1;
    }

    window = SDL_CreateWindow("ESGI SIMULATOR",
                              SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
                              1224, 714, SDL_WINDOW_SHOWN);
    if (window == NULL) {
        printf("Erreur lors de la création de la fenêtre : %s\n", SDL_GetError());
        SDL_Quit();
        return 1;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (renderer == NULL) {
        printf("Erreur lors de la création du renderer : %s\n", SDL_GetError());
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    SDL_Surface *menu = IMG_Load("images/esgi-sim.png");
    if (menu == NULL) {
        printf("Erreur lors du chargement du menu : %s\n", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

    SDL_Texture *menuTexture = SDL_CreateTextureFromSurface(renderer, menu);
    SDL_FreeSurface(menu);
    if (menuTexture == NULL) {
        printf("Erreur lors de la création de la texture : %s\n", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return 1;
    }

 while (continueGame) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT || (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)) {
                continueGame = 0;
            } else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_1) {
                renderWelcomeScreen(renderer, font);
                game(window, renderer);
                continueGame =1;
                break;
            }
        }

        SDL_RenderClear(renderer);
        SDL_RenderCopy(renderer, menuTexture, NULL, NULL);
        SDL_RenderPresent(renderer);
    }

    SDL_DestroyTexture(menuTexture);
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}

void renderWelcomeScreen(SDL_Renderer *renderer, TTF_Font *font) {
    int welcome = 0;
    do {
        SDL_Event welcomeEvent;
        while (SDL_PollEvent(&welcomeEvent)) {
            if (welcomeEvent.type == SDL_QUIT) {
                continueGame = 1;
            } else if (welcomeEvent.type == SDL_KEYDOWN && welcomeEvent.key.keysym.sym == SDLK_SPACE) {
                welcome =  1;
            }
        }

        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0);
        SDL_RenderClear(renderer);

        renderText("Bienvenue dans le Quiz de l'ESGI !", renderer, font, 2, 7);
        renderText("3 Fautes et vous verrez ...", renderer, font, 2, 8);
        renderText("Appuyez sur la touche ESPACE pour continuer ...", renderer, font, 2, 9);

        SDL_RenderPresent(renderer);
        SDL_Delay(16);
    } while (welcome == 0);
}