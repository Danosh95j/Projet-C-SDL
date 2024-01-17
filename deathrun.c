#include <SDL2/SDL.h>
#include <stdio.h>
#include <SDL2/SDL_image.h>
#include "const.h"
#include "game.h"

#include <SDL2/SDL.h>
#include <stdio.h>
#include <SDL2/SDL_image.h>
#include "const.h"
#include "game.h"

void deathrun(SDL_Window* window, SDL_Renderer* renderer) {
    
    SDL_Surface *finn[BAS+1] = {NULL};
    SDL_Texture *finnTexture[BAS+1] = {NULL};
    SDL_Rect positionJoueur = {3 * TAILLE_BLOC, 3 * TAILLE_BLOC, TAILLE_BLOC, TAILLE_BLOC};
    SDL_Event event;
    int continuer = 2;
    int direction = BAS; 

   
    for (int i = 0; i < 4; i++) {
        char filename[50];
        sprintf(filename, "images/tile00%d.png", i);
        finn[i] = IMG_Load(filename);
        if (finn[i] == NULL) {
            fprintf(stderr, "Erreur lors du chargement de finn[%d] : %s\n", i, SDL_GetError());
            for (int j = 0; j < i; j++) {
                SDL_FreeSurface(finn[j]);
            }
            SDL_DestroyRenderer(renderer);
            SDL_DestroyWindow(window);
            SDL_Quit();
            return;
        }

        finnTexture[i] = SDL_CreateTextureFromSurface(renderer, finn[i]);
        SDL_FreeSurface(finn[i]);  
    }
    while (continuer) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                continuer = 0;
            } else if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.sym) {
                    case SDLK_ESCAPE:
                        continuer = 0;
                        break;
                    case SDLK_UP:
                        positionJoueur.y -= TAILLE_BLOC; 
                        direction = HAUT;  
                        break;
                }
            }
        }

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);
        
        SDL_RenderCopy(renderer, finnTexture[direction], NULL, &positionJoueur);

    
        SDL_RenderPresent(renderer);

        SDL_Delay(16);
    }

    for (int i = 0; i <= BAS; i++) {
        SDL_DestroyTexture(finnTexture[i]);
    }
}

