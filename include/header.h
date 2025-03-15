#ifndef HEADER_H
#define HEADER_H

#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdbool.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600
#define PI 3.14159265

typedef struct player_s
{
	float x;
	float y;
	float width;
	float height;
	int walkDirection;
	float walkSpeed;
} player_s;

typedef struct color_s {
    Uint8 r, g, b, a;
} color_s;

extern player_s player;
extern SDL_Window *window;
extern SDL_Renderer *renderer;
extern bool GameRunning;

int initializeWindow(void);
void getPlayerInput(void);
void destroyWindow(void);
void renderPlayer(void);
void movePlayer();
float calculateDeltaTime(void);
void clearColorBuffer(color_s color);

#endif
