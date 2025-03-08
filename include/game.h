#ifndef GAME_H
#define GAME_H

#include <SDL2/SDL.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

extern SDL_Window *window;
extern SDL_Renderer *renderer;
extern int isRunning;

int initSDL(void);
void gameLoop(void);
void cleanup(void);
void render(void);

#endif /* GAME_H */

