#include "../include/header.h"

raindrop_t raindrops[MAX_RAINDROPS];
/*
 * init_rain - Initializes the raindrop array with random positions, speeds,
 *             lengths, and colors.
 *
 * This function initializes the raindrops array by assigning random x and y
 * coordinates, varying speeds, lengths, and a brightness effect for depth.
 */
void init_rain(void) {
	int i;
	for ( i = 0; i < MAX_RAINDROPS; i++)
	{
		raindrops[i].x = rand() % SCREEN_WIDTH;
		raindrops[i].y = rand() % SCREEN_HEIGHT;
		raindrops[i].speed = 5.0f + (rand() % 5);
		raindrops[i].length = 4 + (rand() % 6);
		
		int brightness = 180 + (rand() % 76);
		raindrops[i].color = (brightness << 24) | 0xFFFFDD; 
    }
}

/*
 * render_rain - Renders the raindrops on the screen.
 *
 * This function iterates through the raindrops array and calls draw_line()
 * to render each raindrop. It applies a small wind shift effect.
 */

void render_rain(void) {
	int i, wind_shift;

	for ( i = 0; i < MAX_RAINDROPS; i++)
	{
		wind_shift = (rand() % 3) - 1;

		draw_line(
				(int)raindrops[i].x + wind_shift, (int)raindrops[i].y,
				(int)raindrops[i].x + wind_shift, (int)(raindrops[i].y + raindrops[i].length),
				raindrops[i].color
				);
	}
}

/*
 * update_rain - Updates the raindrop positions, applying wind and resetting
 *               them when they reach the bottom.
 *
 * This function moves each raindrop downward based on its speed, applies a small
 * horizontal wind effect, and resets raindrops that reach the bottom. A splash
 * effect is created when a raindrop hits the ground.
 */

void update_rain(void) {
	int i;
	
	for (i = 0; i < MAX_RAINDROPS; i++)
	{
		raindrops[i].y += raindrops[i].speed;
		raindrops[i].x += (rand() % 3) - 1;

		if (raindrops[i].y >= SCREEN_HEIGHT)
		{
			raindrops[i].x = rand() % SCREEN_WIDTH;
			raindrops[i].y = 0;
			raindrops[i].speed = 2.0f + (rand() % 5);
			raindrops[i].length = 4 + (rand() % 6);
		}
		if (raindrops[i].y >= SCREEN_HEIGHT)
		{
			draw_rect(raindrops[i].x, SCREEN_HEIGHT - 2, 3, 2, 0xAAAAFF);
			raindrops[i].x = rand() % SCREEN_WIDTH;
			raindrops[i].y = 0;
		}
	}
}
