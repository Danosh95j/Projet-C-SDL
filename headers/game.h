#ifndef GAME_H
#define GAME_H

void start(SDL_Window *window, SDL_Renderer *renderer, SDL_Texture *menuTexture);

void updateMap(SDL_Rect positionWall, SDL_Rect positionWood, SDL_Rect positionRock, SDL_Rect positionGrass, SDL_Texture *wallTexture, SDL_Texture *woodTexture, SDL_Texture *rockTexture, SDL_Texture *grassTexture, SDL_Renderer *renderer, int map[][36], int answer);
int isPlayerInZone(SDL_Rect playerPos);
void placeMapTiles(SDL_Rect positionWall, SDL_Rect positionWood, SDL_Rect positionRock, SDL_Rect positionGrass, SDL_Texture *wallTexture, SDL_Texture *woodTexture, SDL_Texture *rockTexture, SDL_Texture *grassTexture, int map[][36], SDL_Renderer *renderer);
int isRectangleGrass(int startRow, int endRow, int startCol, int endCol, int map[][36]);
void initRectangles(int map[][36], int row1, int col1, int row2, int col2);
char *showQuestion();
void showAnswers(int questionId, char answers[4][256]);
void renderText(const char *text, SDL_Renderer *renderer, TTF_Font *font, int x, int y);
void renderWelcomeScreen(SDL_Renderer *renderer, TTF_Font *font);
char *int_to_str(int num);
int getAnswers(char *questionText);
void formatQuestion(char* formattedQuestion, const char* text, int questionIndex);
void formatAnswer(char formattedAnswer[4][256], char text[4][256]);
int isRectangleGrass(int startRow, int endRow, int startCol, int endCol, int map[][36]);
int getRectangle();
int checkAnswer(char answers[256]);
void formatScore(int score, char *formattedString, int maxSize);
int loadFont();
void renderText2(const char *text, SDL_Renderer *renderer, TTF_Font *font, int x, int y);

struct Player {
    char nickname[11];
    int posPlayer_x;
    int posPlayer_y;
    int score;
};

typedef struct Player Player;

void game(SDL_Window *window, SDL_Renderer *renderer, Player *player);
void registering(SDL_Window *window, SDL_Renderer *renderer);
void login(SDL_Window *window, SDL_Renderer *renderer);
void insertPlayer(const char *nickname, Player *player, SDL_Window *window, SDL_Renderer *renderer);


void deathrun(SDL_Window* window, SDL_Renderer* renderer, Player *player);
void revive(SDL_Window *window, SDL_Renderer *renderer, Player *player);
void over(SDL_Window *window, SDL_Renderer *renderer, Player *player);



void movePlayer(int map[][36], SDL_Rect *pos, int direction, Player *player);
void savePosition(Player *player);
void saveScore(int score, Player *player);

void checkPlayer(const char *nickname, Player *player, SDL_Window *window, SDL_Renderer *renderer);
void deadPlayer(Player *player);
#endif