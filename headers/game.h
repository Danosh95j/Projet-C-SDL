#ifndef GAME_H
#define GAME_H


void movePlayer(int map[][36], SDL_Rect *pos, int direction);
void updateMap(SDL_Rect positionWall, SDL_Rect positionWood, SDL_Rect positionRock, SDL_Rect positionGrass, SDL_Texture *wallTexture, SDL_Texture *woodTexture, SDL_Texture *rockTexture, SDL_Texture *grassTexture, SDL_Renderer *renderer, int map[][36], int answer);
int isPlayerInZone(SDL_Rect playerPos);
void placeMapTiles(SDL_Rect positionWall, SDL_Rect positionWood, SDL_Rect positionRock, SDL_Rect positionGrass, SDL_Texture *wallTexture, SDL_Texture *woodTexture, SDL_Texture *rockTexture, SDL_Texture *grassTexture, int map[][36], SDL_Renderer *renderer);
int isRectangleGrass(int startRow, int endRow, int startCol, int endCol, int map[][36]);
void initRectangles(int map[][36], int row1, int col1, int row2, int col2);
char *showQuestion();
void showAnswers(int questionId, char answers[4][256]);
void renderText(const char *text, SDL_Renderer *renderer, TTF_Font *font, int x, int y);
int renderWelcomeScreen(SDL_Renderer *renderer, TTF_Font *font);
char *int_to_str(int num);
int getAnswers(char *questionText);
void formatQuestion(char* formattedQuestion, const char* text, int questionIndex);
void formatAnswer(char formattedAnswer[4][256], char text[4][256]);
int isRectangleGrass(int startRow, int endRow, int startCol, int endCol, int map[][36]);
int getRectangle();
void checkAnswer();
char * printTime();
void get_zqsd();

int zqsd = 0;



#endif