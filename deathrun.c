#include "headers/includes.h"


void deathrun(SDL_Window *window, SDL_Renderer *renderer, Player *player) {
    SDL_Surface *finn[4] = {NULL};
    SDL_Texture *finnTexture[4] = {NULL};
    SDL_Rect positionWall, positionWood, playerPosition, obstaclePosition;
    SDL_Event event;

    SDL_Surface *wall;
    SDL_Texture *wallTexture;

    SDL_Surface *wood;
    SDL_Texture *woodTexture;

    int startTime = SDL_GetTicks();
    int endTime;
    int continueGame = 2;
    int direction = UP;
    // int frameI = 0;
    // int frameD = 100;
    // int frameL = SDL_GetTicks();


    int map[21][36] = {
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
    };

    playerPosition.x = 17 * BLOC_SIZE;
    playerPosition.y = 17 * BLOC_SIZE;
    playerPosition.w = BLOC_SIZE;  // gen entre 12 et 22
    playerPosition.h = BLOC_SIZE;
    obstaclePosition.w = BLOC_SIZE;
    obstaclePosition.h = BLOC_SIZE;

    for (int i = 0; i < 5; i++) {
        char filename[50];
        sprintf(filename, "images/anim%d.bmp", i);
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

    wall = IMG_Load("images/wall.bmp");
    if (wall == NULL) {
        fprintf(stderr, "Erreur lors du chargement de l'image du mur : %s\n", SDL_GetError());
        for (int i = 0; i < 1; i++) {
            SDL_DestroyTexture(finnTexture[i]);
        }
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return;
    }
    wallTexture = SDL_CreateTextureFromSurface(renderer, wall);
    SDL_FreeSurface(wall);

    wood = IMG_Load("images/wood.bmp");
    if (wood == NULL) {
        fprintf(stderr, "Erreur lors du chargement de l'image du bois : %s\n", SDL_GetError());
        SDL_DestroyTexture(wallTexture);
        for (int i = 0; i < 4; i++) {
            SDL_DestroyTexture(finnTexture[i]);
        }
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return;
    }
    woodTexture = SDL_CreateTextureFromSurface(renderer, wood);
    SDL_FreeSurface(wood);

    srand(time(NULL));
    obstaclePosition.x = rand() % (22 - 13) * BLOC_SIZE + 13 * BLOC_SIZE; 
    obstaclePosition.y = -BLOC_SIZE;

    while (continueGame) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                continueGame = 0;
            } else if (event.type == SDL_KEYDOWN) {
                switch (event.key.keysym.sym) {
                    case SDLK_ESCAPE:
                        continueGame = 0;
                        break;
                    case SDLK_LEFT:
                        movePlayer(map, &playerPosition, LEFT, player);
                        direction = UP;
                        break;
                    case SDLK_RIGHT:
                        movePlayer(map, &playerPosition, RIGHT, player);
                        direction = UP;
                        break;
                    
                    default:
                        break;
                
                }
            }
        }

        obstaclePosition.y += 1;

        endTime = SDL_GetTicks() - startTime;

        if (obstaclePosition.y > 35*21) {
            obstaclePosition.y = -BLOC_SIZE;
            obstaclePosition.x = rand() % (22 - 13) * BLOC_SIZE + 13 * BLOC_SIZE; 
        }

         if (obstaclePosition.y > playerPosition.x && obstaclePosition.x == playerPosition.x) {
            deadPlayer(player);
            over(window, renderer, player);
            continueGame = 3; 
        }

        if(endTime >= 15000){
            revive(window, renderer, player);
            continueGame = 4;
        }


        SDL_SetRenderDrawColor(renderer, 255, 255, 200, 200);
        SDL_RenderClear(renderer);

        for (int i = 0; i < 21; i++) {
            for (int j = 0; j < 36; j++) {
                switch (map[i][j]) {
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

        int currentTime = SDL_GetTicks();
        int frameIndex = (currentTime / 100) % 5;
        SDL_RenderCopy(renderer, wallTexture, NULL, &obstaclePosition);
        
        SDL_RenderCopy(renderer, finnTexture[frameIndex], NULL, &playerPosition);
        SDL_RenderPresent(renderer);
    }
}

void deadPlayer(Player *player){
    MYSQL_RES *res;
    MYSQL *conn;

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
    snprintf(selectQuery, sizeof(selectQuery), "UPDATE player SET score = '%d', position_x = '%d', position_y = '%d' WHERE nickname = '%s'", 0, 18 * BLOC_SIZE, 14 * BLOC_SIZE, player->nickname);
    if (mysql_query(conn, selectQuery)) {
        fprintf(stderr, "Erreur de syntaxe SQL: %s\n", mysql_error(conn));
        mysql_close(conn);
        return;
    }

    printf("Joueur bien mise a jour");
    player->score = 0;
    player->posPlayer_x = 18 * BLOC_SIZE;
    player->posPlayer_y = 14 * BLOC_SIZE;


    mysql_close(conn);
    return;

}