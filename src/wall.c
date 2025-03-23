#include "../include/header.h"

/**
 * render_wall - Renders walls using simple shading instead of textures.
 * This function calculates the correct height and position for each
 * vertical wall slice based on the ray distances.
 */
void render_wall(void)
{
        int x, y, wall_bottom_pixel, wall_strip_height, wall_top_pixel;
        float perp_distance, projected_wall_height;
        color_t wall_color;

        for (x = 0; x < NUM_RAYS; x++)
        {
                perp_distance = rays[x].distance * cos(rays[x].ray_angle - player.rotation_angle);


                projected_wall_height = (TILE_SIZE / perp_distance) * PROJ_PLANE;
                wall_strip_height = (int)projected_wall_height;


                wall_top_pixel = (SCREEN_HEIGHT / 2) - (wall_strip_height / 2);

                if (wall_top_pixel < 0)
                        wall_top_pixel = 0;

                wall_bottom_pixel = (SCREEN_HEIGHT / 2) + (wall_strip_height / 2);
                if (wall_bottom_pixel > SCREEN_HEIGHT)
                        wall_bottom_pixel = SCREEN_HEIGHT;

			
                if (rays[x].was_hit_vertical)
			wall_color = 0xAAAAAA;
		else
			wall_color = 0xCCCCCC;




                for (y = wall_top_pixel; y < wall_bottom_pixel; y++)
                {


                        set_pixel_color(x, y, wall_color);
                }
        }
}
