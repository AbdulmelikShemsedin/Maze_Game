#include "../include/game.h"

SDL_Window *window = NULL;
SDL_Renderer *renderer = NULL;
int isRunning = 1;

int initSDL(void)
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
        return 0;
    }

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
    if (!renderer)
    {
        printf("Renderer Creation Failed: %s\n", SDL_GetError());
        return 0;
    }

    return 1;
}

void gameLoop(void)
{
    SDL_Event event;

    while (isRunning)
    {
        while (SDL_PollEvent(&event))
        {
            if (event.type == SDL_QUIT)
                isRunning = 0;
        }

        render();  /* Call render function */
    }
}

void cleanup(void)
{
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}

