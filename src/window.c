#include "../include/header.h"

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;

/*
 * initializeWindow - Initialize window to display the maze
 *
 * Return: true in case of success, false if it fails
 */
int initializeWindow(void)
{
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		printf("SDL Initialization Failed: %s\n", SDL_GetError());
		return 0;
	}

	window = SDL_CreateWindow(NULL, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	if (!window)
	{
		printf("Window Creation Failed: %s\n", SDL_GetError());
		return 0;
	}

	renderer = SDL_CreateRenderer(window, -1, 1);
	if (!renderer)
	{
		printf("Renderer Creation Failed: %s\n", SDL_GetError());
		return 0;
	}

	return 1;
}

/*
 * clearColorBuffer - clear buffer for every frame
 * @color: color buffer
 *
 */
void destroyWindow(void)
{
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

