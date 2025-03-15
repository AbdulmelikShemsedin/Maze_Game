#include "../include/header.h"
/*
 * getPlayerInput - process input from the keyboard
 *
 */
extern player_s player;

void getPlayerInput(void)
{
    SDL_Event event;

	SDL_PollEvent(&event);

        if (event.type == SDL_QUIT)
        {
            GameRunning = 0;
        }
        else if (event.type == SDL_KEYDOWN) 
        {
            switch (event.key.keysym.sym)
            {
                case SDLK_LEFT:
                    player.x -= 5;
                    break;
                case SDLK_RIGHT:
                    player.x += 5;
                    break;
                case SDLK_UP:
                    player.y -= 5;
                    break;
                case SDLK_DOWN:
                    player.y += 5;
                    break;
                case SDLK_ESCAPE:
                    GameRunning = 0;
                    break;
                default:
                    break;
            }
        }
}
