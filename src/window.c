#include "../include/header.h"

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;

/**
 * initializeWindow - Initializes the game window and renderer.
 *
 * This function sets up the SDL window and renderer needed for the game.
 * It ensures that SDL is properly initialized before the game starts.
 *
 * Return: 1 if initialization is successful, 0 if an error occurs.
 */
int initializeWindow(void)
{
        if (SDL_Init(SDL_INIT_VIDEO) != 0)
        {
                printf("SDL Initialization Failed: %s\n", SDL_GetError());
                return 0;
        }

        window = SDL_CreateWindow("Maze Game", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
        if (!window)
        {
                printf("Window Creation Failed: %s\n", SDL_GetError());
                SDL_Quit();
                return 0;
        }

        renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
        if (!renderer)
        {
                printf("Renderer Creation Failed: %s\n", SDL_GetError());
                SDL_Quit();
                return 0;
        }

        if (IMG_Init(IMG_INIT_PNG) != IMG_INIT_PNG)
	{
		printf("Failed to initialize SDL_image.\n", SDL_GetError());
		return (0);
	}

        return 1;
}
/**
 * destroyWindow - Cleans up and frees all allocated resources for the game window.
 *
 * This function is responsible for properly shutting down the SDL window,
 * renderer, and any other initialized resources. It ensures that memory
 * leaks are prevented and the game exits cleanly.
 */
void destroyWindow(void)
{
        SDL_DestroyRenderer(renderer);
        SDL_DestroyWindow(window);
        SDL_Quit();
}
