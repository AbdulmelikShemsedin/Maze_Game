#include <stdio.h>
#include <SDL2/SDL.h>
#include "game.h"

int main(void)
{
    if (!initSDL())  /* Initialize SDL */
        return 1;

    gameLoop();  /* Run the game loop */

    cleanup();  /* Clean up resources */
    return 0;
}

