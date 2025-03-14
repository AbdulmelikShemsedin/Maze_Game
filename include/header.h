#ifndef HEADER_H
#define HEADER_H

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdbool.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

extern SDL_Window *window;
extern SDL_Renderer *renderer;
extern bool GameRunning;
int initializeWindow(void);
void userInput(void);
void destroyWindow(void);

#endif

