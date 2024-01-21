#include <SDL2/SDL.h>
#include <stdio.h>
#include <SDL2/SDL_image.h>
#include "mysql/include/mysql.h"   

void game(SDL_Window* window, SDL_Renderer* renderer);
void deathrun(SDL_Window* window, SDL_Renderer* renderer);


void over(SDL_Window *window, SDL_Renderer *renderer) {
    SDL_Event event;
    int continueGame = 3;

    SDL_Surface *menu = IMG_Load("images/game-over.png");
    if (menu == NULL) {
        printf("Erreur lors du chargement du menu : %s\n", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }

    SDL_Texture *menuTexture = SDL_CreateTextureFromSurface(renderer, menu);
    SDL_FreeSurface(menu);
    if (menuTexture == NULL) {
        printf("Erreur lors de la création de la texture : %s\n", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
    }
 while (continueGame) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT || (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_ESCAPE)) {
                continueGame = 0;
            } else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_1) {
                deathrun(window, renderer);
                continueGame =0;
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
}