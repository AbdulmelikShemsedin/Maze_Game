#include "../include/header.h"

void render_floor(void)
{
    int x, y, wall_bottom_pixel, wall_strip_height;
    float projected_distance;
    color_t grass_green = 0x228B22;

    for (x = 0; x < SCREEN_WIDTH; x++)
    {
        /* Calculate wall bottom pixel dynamically */
        projected_distance = rays[x].distance * cos(rays[x].ray_angle - player.rotation_angle);
        wall_strip_height = (TILE_SIZE / projected_distance) * PROJ_PLANE;
        wall_bottom_pixel = (SCREEN_HEIGHT / 2) + (wall_strip_height / 2);

        if (wall_bottom_pixel > SCREEN_HEIGHT)
            wall_bottom_pixel = SCREEN_HEIGHT;

        /* Draw floor starting from wall bottom */
        for (y = wall_bottom_pixel; y < SCREEN_HEIGHT; y++)
        {
            set_pixel_color(x, y, grass_green);
        }
    }
}





/**
 * renderCeil - Renders the ceiling projection above the walls.
 *
 * This function calculates the ceiling pixels above the wall, from the
 * top of the screen to the top of the wall, using raycasting data and
 * the player's position. The ceiling is drawn as a solid color (e.g.,
 * sky blue).
 *
 * No parameters are required as it uses global variables like player
 * position and raycasting data.
 *
 * Return: None. Directly modifies the screen buffer by drawing pixels.
 */
void renderCeil(void)
{
    int x, y, wall_top_pixel, wall_strip_height;
    float distance, ratio;
    color_t ceil_color = 0xEED202;

    for (x = 0; x < SCREEN_WIDTH; x++)
    {
        
        ratio = player.height / (rays[x].distance);
        distance = (ratio * PROJ_PLANE) / cos(rays[x].ray_angle - player.rotation_angle);

        wall_strip_height = (int)(TILE_SIZE / distance);

        
        wall_top_pixel = (SCREEN_HEIGHT / 2) - (wall_strip_height / 2);
        if (wall_top_pixel < 0)
            wall_top_pixel = 0;

        
        for (y = 0; y < wall_top_pixel; y++)
        {
            set_pixel_color(x, y, ceil_color); 
        }
    }
}

