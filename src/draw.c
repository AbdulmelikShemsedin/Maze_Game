#include "../include/header.h"

/**
 * drawRect - draw a rectangle
 * @x: x coordinate
 * @y: y coordinate
 * @width: rectangle width
 * @height: rectangle height
 * @color: pixel color
*/
void drawRect(int x, int y, int width, int height, color_s color)
{

    SDL_SetRenderDrawColor(renderer, color.r, color.g, color.b, color.a);


    SDL_Rect rect = {x, y, width, height};


    SDL_RenderFillRect(renderer, &rect);
}
