#include "headers/includes.h"

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
//9                  |||||||||||||||||||                                            ||||||||||||||||||| 
        {1, 3, 3, 3, 5, 5, 5, 5, 5, 5, 5, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 5, 5, 5, 5, 5, 5, 5, 3, 3, 3, 1},
        {1, 3, 3, 3, 5, 5, 5, 5, 5, 5, 5, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 5, 5, 5, 5, 5, 5, 5, 3, 3, 3, 1},
        {1, 3, 3, 3, 5, 5, 5, 5, 5, 5, 5, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 5, 5, 5, 5, 5, 5, 5, 3, 3, 3, 1},
        {1, 3, 3, 3, 5, 5, 5, 5, 5, 5, 5, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 5, 5, 5, 5, 5, 5, 5, 3, 3, 3, 1},
//13                 |||||||||||||||||||                                            |||||||||||||||||||     
        {1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1},
        {1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1},
//15                 |||||||||||||||||||                                            ||||||||||||||||||| 
        {1, 3, 3, 3, 5, 5, 5, 5, 5, 5, 5, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 5, 5, 5, 5, 5, 5, 5, 3, 3, 3, 1},
        {1, 3, 3, 3, 5, 5, 5, 5, 5, 5, 5, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 5, 5, 5, 5, 5, 5, 5, 3, 3, 3, 1},
        {1, 3, 3, 3, 5, 5, 5, 5, 5, 5, 5, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 5, 5, 5, 5, 5, 5, 5, 3, 3, 3, 1},
        {1, 3, 3, 3, 5, 5, 5, 5, 5, 5, 5, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 5, 5, 5, 5, 5, 5, 5, 3, 3, 3, 1},
// 19                |||||||||||||||||||                                            ||||||||||||||||||| 
        {1, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 3, 1},
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};

void game(SDL_Window *window, SDL_Renderer *renderer, Player *player) {
    SDL_Surface *finn[DOWN + 1] = {NULL};
    SDL_Texture *finnTexture[DOWN + 1] = {NULL};
    SDL_Rect positionWall, positionWood, positionRock, positionGrass;
    SDL_Rect playerPosition = {18 * BLOC_SIZE, 14 * BLOC_SIZE, BLOC_SIZE, BLOC_SIZE};
    SDL_Event event;

    SDL_Surface *wall;
    SDL_Texture *wallTexture;

    SDL_Surface *wood;
    SDL_Texture *woodTexture;

    SDL_Surface *rock;
    SDL_Texture *rockTexture;

    SDL_Surface *grass;
    SDL_Texture *grassTexture;
    int continueGame = 1;
    int questionIndex = 1;
    int direction = DOWN;
    int score = 0;
    int wrong = 0;

    if (TTF_Init() != 0) {
        fprintf(stderr, "Erreur lors de l'initialisation de SDL_ttf : %s\n", TTF_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return;
    }

    if (TTF_Init() != 0) {
        fprintf(stderr, "Erreur lors de l'initialisation de SDL_ttf : %s\n", TTF_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return ;
    }

    TTF_Font *font = TTF_OpenFont("font/PressStart2P-Regular.ttf", 24);
    if (font == NULL) {
        fprintf(stderr, "Erreur lors du chargement de la police : %s\n", TTF_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        TTF_Quit();
        SDL_Quit();
        return ;
    }
    TTF_Font *questionFont = TTF_OpenFont("font/PressStart2P-Regular.ttf", 14);
    if (questionFont == NULL) {
        fprintf(stderr, "Erreur lors du chargement de la police : %s\n", TTF_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        TTF_Quit();
        SDL_Quit();
        return;
    }

    TTF_Font *answerFont = TTF_OpenFont("font/PressStart2P-Regular.ttf", 11);
    if (questionFont == NULL) {
        fprintf(stderr, "Erreur lors du chargement de la police : %s\n", TTF_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        TTF_Quit();
        SDL_Quit();
        return;
    }



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

            for (int i = 0; i < 21; i++) {
                for (int j = 0; j < 36; j++) {
                    printf("%d ", map[i][j]);
                }
                printf("\n");
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
// WOOD _______________________________________________________________________________________________
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

// rock ____________________________________________________________________________________________
    rock = IMG_Load("images/rock.bmp");
    if (rock == NULL) {
        printf("Erreur lors du chargement de l'image de herbe : %s\n", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return;
    }
    printf("Image de l'herbe chargée avec succès.\n");
    rockTexture = SDL_CreateTextureFromSurface(renderer, rock);
    if (rockTexture == NULL) {
        printf("Erreur lors de la création de la texture pour l'image de validation : %s\n", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return;
    }
    printf("Texture dde l'herbe chargée avec succès.\n");
    SDL_FreeSurface(rock);

// grass ____________________________________________________________________________________________
    grass = IMG_Load("images/grass.bmp");
    if (grass == NULL) {
        printf("Erreur lors du chargement de l'image de herbe : %s\n", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return;
    }
    // printf("Image de l'herbe chargée avec succès.\n");
    grassTexture = SDL_CreateTextureFromSurface(renderer, grass);
    if (grassTexture == NULL) {
        printf("Erreur lors de la création de la texture pour l'image de validation : %s\n", SDL_GetError());
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
        return;
    }
    // printf("Texture dde l'herbe chargée avec succès.\n");
    SDL_FreeSurface(grass);

    // for(int i = 0; i < 21; i++){
    //     printf("\n");
    //     for(int j = 0; j < 36; j++)
    //         printf("%d",map[i][j]);
    // }

    char formattedQuestion[256];
    char *question = showQuestion();
    formatQuestion(formattedQuestion, question, questionIndex);
    printf("\n%s\n", formattedQuestion);
    printf("\n%s", player->nickname);


    int questionId = getAnswers(question);
    char answers[4][256];
    char formattedAnswer[4][256];
    showAnswers(questionId, answers);
    formatAnswer(formattedAnswer, answers);
    checkAnswer(answers[0]);
    checkAnswer(answers[1]);
    checkAnswer(answers[2]);
    checkAnswer(answers[3]);
    while (continueGame) {
        while (SDL_PollEvent(&event)) {
            if (event.type == SDL_QUIT) {
                continueGame = 0;
            } else if (event.type == SDL_KEYDOWN) {
                printf("Evenement capturé dans le jeu\n");
                printf("\n%d", isPlayerInZone(playerPosition));
                switch (event.key.keysym.sym) {
                    case SDLK_ESCAPE:
                        continueGame = 0;
                        break;
                    case SDLK_UP:
                    case SDLK_z:
                        movePlayer(map, &playerPosition, UP);
                        direction = UP;  
                        break;
                    case SDLK_DOWN:
                    case SDLK_s:
                        movePlayer(map, &playerPosition, DOWN);
                        direction = DOWN;
                            break;
                    case SDLK_LEFT:
                    case SDLK_q:
                        movePlayer(map, &playerPosition, LEFT);
                        direction = LEFT;
                        break;
                    case SDLK_RIGHT:
                    case SDLK_d:
                        movePlayer(map, &playerPosition, RIGHT);
                        direction = RIGHT;
                        break;
                    case SDLK_RETURN:{
                            int zoneNumber = isPlayerInZone(playerPosition);
                            if (zoneNumber > 0 && zoneNumber <= 4) {
                                updateMap(positionWall, positionWood, positionRock, positionGrass, wallTexture, woodTexture, rockTexture, grassTexture, renderer, map, zoneNumber);
                                placeMapTiles(positionWall, positionWood, positionRock, positionGrass, wallTexture, woodTexture, rockTexture, grassTexture, map, renderer);
                            }
                    }
                    break;
                    case SDLK_v:
                        if(isRectangleGrass(9,12,4,10,map) == 1 || 
                        isRectangleGrass(9,12,25,31,map) == 1 ||
                        isRectangleGrass(15,18,4,10,map) == 1 ||
                        isRectangleGrass(15,18,25,31,map) == 1)
                        {
                            int answerNumber = getRectangle();
                            printf("\nAnswer Number = %d",answerNumber);
                            printf("\nAnswer = %s", answers[answerNumber]);
                            
                            checkAnswer(answers[answerNumber -1]);

                            question = showQuestion();
                            formatQuestion(formattedQuestion, question, ++questionIndex);
                            questionId = getAnswers(question);
                            showAnswers(questionId, answers);
                            formatAnswer(formattedAnswer, answers);
                            if (question == NULL) {
                                printf("Erreur lors de l'obtention de la question.\n");
                                continueGame = 0;
                            }
                            initRectangles(map, 9, 4, 13, 11);
                            initRectangles(map, 9, 25, 13, 32);
                            initRectangles(map, 15, 4, 19, 11);
                            initRectangles(map, 15, 25, 19, 32);
                        }
                        break;
                    default:
                        break;
                }
            }
        }

        SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
        SDL_RenderClear(renderer);

        placeMapTiles(positionWall, positionWood, positionRock, positionGrass, wallTexture, woodTexture, rockTexture, grassTexture, map, renderer);
        
        renderText(formattedQuestion, renderer, questionFont, 2, 3);        
        renderText(formattedAnswer[0], renderer, answerFont, 2, 4);
        renderText(formattedAnswer[1], renderer, answerFont, 2, 5);
        renderText(formattedAnswer[2], renderer, answerFont, 2, 6);
        renderText(formattedAnswer[3], renderer, answerFont, 2, 7);


        renderText("A", renderer, font, 6, 10);
        renderText("B", renderer, font, 27, 10);
        renderText("C", renderer, font, 6, 16);
        renderText("D", renderer, font, 27, 16);

        SDL_RenderCopy(renderer, finnTexture[direction], NULL, &playerPosition);
        SDL_RenderPresent(renderer);

        SDL_Delay(16);
    
    }
    
    SDL_DestroyTexture(grassTexture);
    SDL_DestroyTexture(rockTexture);
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

void placeMapTiles(SDL_Rect positionWall, SDL_Rect positionWood, SDL_Rect positionRock, SDL_Rect positionGrass, SDL_Texture *wallTexture, SDL_Texture *woodTexture, SDL_Texture *rockTexture, SDL_Texture *grassTexture, int map[][36], SDL_Renderer *renderer){

    for (int i = 0; i < 21; i++) {
        for (int j = 0; j < 36; j++) {
            switch (map[i][j])
            {
            case WALL:
                positionWall.x = j * BLOC_SIZE;
                positionWall.y = i * BLOC_SIZE;
                positionWall.w = BLOC_SIZE;
                positionWall.h = BLOC_SIZE;
                SDL_RenderCopy(renderer, wallTexture, NULL, &positionWall);
                break;
            case WOOD:
                positionWood.x = j * BLOC_SIZE;
                positionWood.y = i * BLOC_SIZE;
                positionWood.w = BLOC_SIZE;
                positionWood.h = BLOC_SIZE;
                SDL_RenderCopy(renderer, woodTexture, NULL, &positionWood);
                break;
            case ROCK:
                positionRock.x = j * BLOC_SIZE;
                positionRock.y = i * BLOC_SIZE;
                positionRock.w = BLOC_SIZE;
                positionRock.h = BLOC_SIZE;
                SDL_RenderCopy(renderer, rockTexture, NULL, &positionRock);
                break;
            case GRASS:
                positionGrass.x = j * BLOC_SIZE;
                positionGrass.y = i * BLOC_SIZE;
                positionGrass.w = BLOC_SIZE;
                positionGrass.h = BLOC_SIZE;
                SDL_RenderCopy(renderer, grassTexture, NULL, &positionGrass);
                break;
            default:
                break;
            }
        }
    }
}

void updateMap(SDL_Rect positionWall, SDL_Rect positionWood, SDL_Rect positionRock, SDL_Rect positionGrass, SDL_Texture *wallTexture, SDL_Texture *woodTexture, SDL_Texture *rockTexture, SDL_Texture *grassTexture, SDL_Renderer *renderer, int map[][36], int answer){   
    if (answer == 1) {
        initRectangles(map, 9, 25, 13, 32);
        initRectangles(map, 15, 4, 19, 11);
        initRectangles(map, 15, 25, 19, 32);

        printf("map[9][4] = %d\n", map[9][4]);
        printf("map[9][10] = %d\n", map[9][10]);
        printf("map[13][4] = %d\n", map[12][4]);
        printf("map[13][10] = %d\n", map[12][10]);
        if (map[9][4] == 5 && map[9][10] == 5 && map[12][4] == 5 && map[12][10] == 5) {
            for (int i = 9; i <= 13; i++) {
                for (int j = 4; j <= 10; j++) {
                    if (map[i][j] == 5) {
                        map[i][j] = 4;
                    }
                }
            }
            printf("map[9][4] = %d\n", map[9][4]);
            printf("map[9][10] = %d\n", map[9][10]);
            printf("map[13][4] = %d\n", map[12][4]);
            printf("map[13][10] = %d\n", map[12][10]);
        }
    }

    if(answer == 2){
        initRectangles(map, 9, 4, 13, 11);
        initRectangles(map, 15, 4, 19, 11);
        initRectangles(map, 15, 25, 19, 32);

        if (map[9][25] == 5 && map[9][31] == 5 && map[12][25] == 5 && map[12][31] == 5) {
            for (int i = 9; i <= 12; i++) {
                for (int j = 25; j <= 31; j++) {
                    if (map[i][j] == 5) {
                        map[i][j] = 4;
                    }
                }
            }
        }
    }
    if(answer == 3){
        initRectangles(map, 9, 4, 13, 11);
        initRectangles(map, 9, 25, 13, 32);
        initRectangles(map, 15, 25, 19, 32);

        if (map[15][4] == 5 && map[15][10] == 5 && map[18][4] == 5 && map[18][10] == 5) {
            for (int i = 15; i <= 18; i++) {
                for (int j = 4; j <= 10; j++) {
                    if (map[i][j] == 5) {
                        map[i][j] = 4;
                    }
                }
            }
        }
    }
    if(answer == 4){
        initRectangles(map, 9, 4, 13, 11);
        initRectangles(map, 9, 25, 13, 32);
        initRectangles(map, 15, 4, 19, 11);

        if (map[15][25] == 5 && map[15][31] == 5 && map[18][25] == 5 && map[18][31] == 5) {
            for (int i = 15; i <= 18; i++) {
                for (int j = 25; j <= 31; j++) {
                    if (map[i][j] == 5) {
                        map[i][j] = 4;
                    }
                }
            }
        }
    }
}

int isPlayerInZone(SDL_Rect playerPos) {
    if(playerPos.x >= 4 * BLOC_SIZE && playerPos.x < 11 * BLOC_SIZE && playerPos.y >= 9 * BLOC_SIZE && playerPos.y < 13 * BLOC_SIZE)
            return 1;
    if(playerPos.x >= 25 * BLOC_SIZE && playerPos.x < 32 * BLOC_SIZE && playerPos.y >= 9 * BLOC_SIZE && playerPos.y < 13 * BLOC_SIZE)
            return 2;
    if(playerPos.x >= 4 * BLOC_SIZE && playerPos.x < 11 * BLOC_SIZE && playerPos.y >= 15 * BLOC_SIZE && playerPos.y < 19 * BLOC_SIZE)
            return 3;
    if(playerPos.x >= 25 * BLOC_SIZE && playerPos.x < 32 * BLOC_SIZE && playerPos.y >= 15 * BLOC_SIZE && playerPos.y < 19 * BLOC_SIZE)
            return 4;
}

void initRectangles(int map[][36], int row1, int col1, int row2, int col2){
    for(int i = row1; i< row2; i++){
        for(int j = col1; j < col2; j++){
            map[i][j] = 5;
        }
    }
}

void showAnswers(int questionId, char answers[4][256]) {
    MYSQL *conn;
    MYSQL_RES *res;
    MYSQL_ROW row;

    conn = mysql_init(NULL);

    if (conn == NULL) {
        fprintf(stderr, "mysql_init() failed\n");
        return;
    }

    if (mysql_real_connect(conn, "localhost", "root", "root", "esgisim", 0, NULL, 0) == NULL) {
        fprintf(stderr, "mysql_real_connect() failed\n");
        printf("mysql_real_connect() failed\n");
        mysql_close(conn);
        return;
    }

    char query_answers[100];
    snprintf(query_answers, sizeof(query_answers), "SELECT answer_text FROM answers WHERE question_id = %d", questionId);

    if (mysql_query(conn, query_answers)) {
        fprintf(stderr, "SELECT answer_text FROM answers WHERE question_id = %d failed: %s\n", questionId, mysql_error(conn));
        mysql_close(conn);
        return;
    }

    res = mysql_store_result(conn);

    if (res == NULL) {
        fprintf(stderr, "mysql_store_result() failed\n");
        printf("mysql_store_result() failed\n");
        mysql_close(conn);
        return;
    }

    int num_columns = mysql_num_fields(res);

    for (int i = 0; i < 4 && (row = mysql_fetch_row(res)) != NULL; i++) {
        strcpy(answers[i], row[0]);
    }

    mysql_free_result(res);
    mysql_close(conn);
}

char* showQuestion() {
        static int questionDisplayed = 0;
        MYSQL *conn;
        MYSQL_RES *res;
        MYSQL_ROW row;
        int rpast = 0;


        int questionNumber = rand() % 79 + 1;
        if(questionNumber == rpast){
            do{
                questionNumber = rand() % 79 + 1;
            }while(rpast == questionNumber);
        }
        rpast = questionNumber;


        conn = mysql_init(NULL);

        if (conn == NULL) {
            fprintf(stderr, "mysql_init() failed\n");
            return NULL;
        }

        if (mysql_real_connect(conn, "localhost", "root", "root", "esgisim", 0, NULL, 0) == NULL) {
            fprintf(stderr, "mysql_real_connect() failed\n");
            printf("mysql_real_connect() failed\n");
            mysql_close(conn);
            return NULL;
        }

        char query[100];
        snprintf(query, sizeof(query), "SELECT question_id, question_text FROM questions WHERE question_id = %d", questionNumber);

        if (mysql_query(conn, query)) {
            fprintf(stderr, "SELECT question_id, question_text FROM questions WHERE question_id = %d failed: %s\n", questionNumber, mysql_error(conn));
            printf("SELECT question_id, question_text FROM questions WHERE question_text = 1 failed: %s\n", mysql_error(conn));
            mysql_close(conn);
            return NULL;
        }


        res = mysql_store_result(conn);

        if (res == NULL) {
            fprintf(stderr, "mysql_store_result() failed\n");
            printf("mysql_store_result() failed\n");
            mysql_close(conn);
            return NULL;
        }

        row = mysql_fetch_row(res);

        static char question[256];
        if (!questionDisplayed) {
            questionDisplayed = 1;

            if (row != NULL) {
                strcpy(question, row[1]);
            } else {
                fprintf(stderr, "Erreur : Aucune ligne retournée par la requête SQL.\n");
                question[0] = '\0';
            }
        }
        printf("\n%s",question);

        mysql_free_result(res);
        mysql_close(conn);
        questionDisplayed = 0;
        return question;
}

int getAnswers(char *questionText) {
    MYSQL *conn;
    MYSQL_RES *res;
    MYSQL_ROW row;

    conn = mysql_init(NULL);

    if (conn == NULL) {
        fprintf(stderr, "mysql_init() failed\n");
        return -1;
    }

    if (mysql_real_connect(conn, "localhost", "root", "root", "esgisim", 0, NULL, 0) == NULL) {
        fprintf(stderr, "mysql_real_connect() failed\n");
        printf("mysql_real_connect() failed\n");
        mysql_close(conn);
        return -1;
    }

    char escapedQuestionText[2 * strlen(questionText) + 1];
    mysql_real_escape_string(conn, escapedQuestionText, questionText, strlen(questionText));

    char query_question_id[256];
    snprintf(query_question_id, sizeof(query_question_id), "SELECT question_id FROM questions WHERE question_text = '%s'", escapedQuestionText);

    if (mysql_query(conn, query_question_id)) {
        fprintf(stderr, "SELECT question_id FROM questions WHERE question_text = '%s' failed: %s\n", questionText, mysql_error(conn));
        mysql_close(conn);
        return -1;
    }

    res = mysql_store_result(conn);

    if (res == NULL) {
        fprintf(stderr, "mysql_store_result() failed\n");
        printf("mysql_store_result() failed\n");
        mysql_close(conn);
        return -1;
    }

    row = mysql_fetch_row(res);

    if (row == NULL) {
        fprintf(stderr, "La question n'a pas été trouvée\n");
        mysql_free_result(res);
        mysql_close(conn);
        return -1;
    }

    int question_id = atoi(row[0]);

    printf("Question ID = %d\n", question_id);


    mysql_free_result(res);
    mysql_close(conn);
    return question_id;
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

char *int_to_str(int num) {
    int size = snprintf(NULL, 0, "%d", num);
    char *str = (char *)malloc(size + 1);
    snprintf(str, size + 1, "%d", num);
    return str;
}

void formatQuestion(char* formattedQuestion, const char* text, int questionIndex){
    snprintf(formattedQuestion, 256, "%d) %s", questionIndex, text);
}

void formatAnswer(char formattedAnswer[4][256], char text[4][256]){
    char letter = 'A';
    for (int i = 0; i < 4; i++)
    {
        snprintf(formattedAnswer[i], 256, "%c) %s", letter, text[i]);
        ++letter;
    }
}

int isRectangleGrass(int startRow, int endRow, int startCol, int endCol, int map[][36]) {
    for (int i = startRow; i <= endRow; i++) {
        for (int j = startCol; j <= endCol; j++) {
            if (map[i][j] != GRASS) {
                return 0;
            }
        }
    }
    return 1;
}

int getRectangle(){
    if(isRectangleGrass(9,12,4,10,map) == 1)
        return 1;
    if(isRectangleGrass(9,12,25,31,map)  == 1)
        return 2;
    if(isRectangleGrass(15,18,4,10,map)  == 1)
        return 3;
    if(isRectangleGrass(15,18,25,31,map)  == 1)
        return 4;
}

void checkAnswer(char answers[256]) {
    MYSQL *conn;
    MYSQL_RES *res;
    MYSQL_ROW row;

    conn = mysql_init(NULL);

    if (conn == NULL) {
        fprintf(stderr, "mysql_init() failed\n");
        return;
    }

    if (mysql_real_connect(conn, "localhost", "root", "root", "esgisim", 0, NULL, 0) == NULL) {
        fprintf(stderr, "mysql_real_connect() failed\n");
        printf("mysql_real_connect() failed\n");
        mysql_close(conn);
        return;
    }

    char is_correct[256];
    snprintf(is_correct, sizeof(is_correct), "SELECT is_correct FROM answers WHERE answer_text = '%s'", answers);

    if (mysql_query(conn, is_correct)) {
        fprintf(stderr, "SELECT is_correct FROM answers WHERE answer_text = '%s' failed: %s\n", answers, mysql_error(conn));
        mysql_close(conn);
        return;
    }

    res = mysql_store_result(conn);

    if (res == NULL) {
        fprintf(stderr, "mysql_store_result() failed\n");
        printf("mysql_store_result() failed\n");
        mysql_close(conn);
        return;
    }

    row = mysql_fetch_row(res);

    if (row == NULL) {
        fprintf(stderr, "La réponse n'a pas été trouvée\n");
        mysql_free_result(res);
        mysql_close(conn);
        return;
    }

    int isCorrect = atoi(row[0]);

    mysql_free_result(res);
    mysql_close(conn);

    if (isCorrect == 1) {
        printf("La réponse est correcte !\n");
    } else {
        printf("La réponse n'est pas correcte.\n");
    }
}
