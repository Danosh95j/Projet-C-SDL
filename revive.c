#include "headers/includes.h"


void revive(SDL_Window *window, SDL_Renderer *renderer, Player *player) {
    SDL_Event event;
    int continueGame = 4;

    SDL_Surface *menu = IMG_Load("images/revive.png");
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
                start(window, renderer, menuTexture);
                break;
            } else if (event.type == SDL_KEYDOWN && event.key.keysym.sym == SDLK_1) {
                continueGame = 1;               
                game(window, renderer, player);
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