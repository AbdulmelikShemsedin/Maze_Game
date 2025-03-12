#include "../include/render.h"

void render(void) {
    SDL_Rect rect;

    rect.x = SCREEN_WIDTH / 2 - 25;
    rect.y = SCREEN_HEIGHT / 2 - 25;
    rect.w = 50;
    rect.h = 50;

    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
    SDL_RenderFillRect(renderer, &rect);
    SDL_RenderPresent(renderer);
}

