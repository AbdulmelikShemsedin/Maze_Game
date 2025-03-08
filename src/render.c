#include "render.h"

void render(void)
{
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255); /* Set background to black */
    SDL_RenderClear(renderer); /* Clear screen */

    /* Draw a red rectangle (a placeholder for a player or object) */
    SDL_Rect rect = {SCREEN_WIDTH / 2 - 25, SCREEN_HEIGHT / 2 - 25, 50, 50};
    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderFillRect(renderer, &rect);

    SDL_RenderPresent(renderer); /* Update screen */
}

