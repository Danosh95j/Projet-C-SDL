#include <SDL2/SDL.h>
#include <stdio.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_ttf.h>
#include "headers/const.h"
#include "headers/game.h"

void movePlayer(int map[][36], SDL_Rect *pos, int direction);

void game(SDL_Window *window, SDL_Renderer *renderer) {
    SDL_Surface *finn[DOWN + 1] = {NULL};
    SDL_Texture *finnTexture[DOWN + 1] = {NULL};
    SDL_Rect positionWall, positionWood;
    SDL_Rect playerPosition = {3 * BLOC_SIZE, 3 * BLOC_SIZE, BLOC_SIZE, BLOC_SIZE};
    SDL_Event event;

    SDL_Surface *wall;
    SDL_Texture *wallTexture;

    SDL_Surface *wood;
    SDL_Texture *woodTexture;


    int continueGame = 1;
    int direction = DOWN;

    int map[21][36] = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1},
        {1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1},
        {1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1},
        {1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1},
        {1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1},
        {1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1},
        {1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1},
        {1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1},
        {1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1},
        {1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1},
        {1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1},
        {1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1},
        {1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1},
        {1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1},
        {1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1},
        {1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1},
        {1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1},
        {1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1},
        {1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
    };
    for (int i = 0; i < 4; i++) {
        char filename[50];
        sprintf(filename, "images/tile00%d.bmp", i);
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

    // WALL ___________________________________________________________________________________________
    wall = IMG_Load("images/wall.bmp");
    if (wall == NULL) {
        printf("Erreur lors du chargement de l'image du mur : %s\n", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return;
    }
    wallTexture = SDL_CreateTextureFromSurface(renderer, wall);
    if (wallTexture == NULL) {
        printf("Erreur lors de la création de la texture pour l'image du mur : %s\n", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return;
    }
    SDL_FreeSurface(wall);

    wood = IMG_Load("images/wood.bmp");
    if (wood == NULL) {
        printf("Erreur lors du chargement de l'image du bois : %s\n", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return;
    }
    printf("Image du bois chargée avec succès.\n");
    woodTexture = SDL_CreateTextureFromSurface(renderer, wood);
    if (woodTexture == NULL) {
        printf("Erreur lors de la création de la texture pour l'image du bois : %s\n", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return;
    }
    printf("Texture pour l'image du bois créée avec succès.\n");
    SDL_FreeSurface(wood);

    for(int i = 0; i < 21; i++){
        printf("\n");
        for(int j = 0; j < 36; j++)
            printf("%d",map[i][j]);
    }

    printf("\nEntree dans la boucle\n");
    while (continueGame) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                continueGame = 0;
            } else if (event.type == SDL_KEYDOWN) {
                printf("Evenement capturé dans le jeu\n");
                switch (event.key.keysym.sym) {
                    case SDLK_ESCAPE:
                        continueGame = 0;
                        break;
                    case SDLK_UP:
                        movePlayer(map, &playerPosition, UP);
                        direction = UP;  
                        break;
                    case SDLK_DOWN:
                        movePlayer(map, &playerPosition, DOWN);
                        direction = DOWN;
                            break;
                    case SDLK_LEFT:
                        movePlayer(map, &playerPosition, LEFT);
                        direction = LEFT;
                        break;
                    case SDLK_RIGHT:
                        movePlayer(map, &playerPosition, RIGHT);
                        direction = RIGHT;
                        break;
                    default:
                        break;
                }
            }
        }

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);


        for (int i = 0; i < 21; i++) {
            for (int j = 0; j < 36; j++) {
                switch (map[i][j])
                {
                case 1:
                    positionWall.x = j * BLOC_SIZE;
                    positionWall.y = i * BLOC_SIZE;
                    positionWall.w = BLOC_SIZE;
                    positionWall.h = BLOC_SIZE;
                    SDL_RenderCopy(renderer, wallTexture, NULL, &positionWall);
                    break;
                case 3:
                    positionWood.x = j * BLOC_SIZE;
                    positionWood.y = i * BLOC_SIZE;
                    positionWood.w = BLOC_SIZE;
                    positionWood.h = BLOC_SIZE;
                    SDL_RenderCopy(renderer, woodTexture, NULL, &positionWood);
                    break;
                default:
                    break;
                }
            }
        }
        SDL_RenderCopy(renderer, finnTexture[direction], NULL, &playerPosition);
        SDL_RenderPresent(renderer);

        SDL_Delay(16);
    }


    SDL_DestroyTexture(wallTexture);
    SDL_DestroyTexture(woodTexture);
    for (int i = 0; i <= RIGHT; i++) {
        SDL_DestroyTexture(finnTexture[i]);
    }
}

void movePlayer(int map[][36], SDL_Rect *pos, int direction) {
    int new_x = pos->x / BLOC_SIZE;
    int new_y = pos->y / BLOC_SIZE;

    switch (direction) {
        case UP:
            new_y--;
            break;

        case DOWN:
            new_y++;
            break;

        case RIGHT:
            new_x++;
            break;

        case LEFT:
            new_x--;
            break;

        default:
            break;
    }

    if (map[new_y][new_x] != WALL) {
        pos->x = new_x * BLOC_SIZE;
        pos->y = new_y * BLOC_SIZE;
    }

}
