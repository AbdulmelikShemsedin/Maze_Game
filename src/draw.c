#include "../include/header.h"



/**
 * set_pixel_color - Sets the color of a specific pixel on the screen.
 * @x: The x-coordinate of the pixel.
 * @y: The y-coordinate of the pixel.
 * @c: The color to set for the pixel.
 *
 * This function calculates the index of the pixel in the color buffer
 * using the formula (SCREEN_WIDTH * y) + x and assigns the given color
 * to that pixel.
 */
void set_pixel_color(int x, int y, color_t c)
{
	color_buffer[(SCREEN_WIDTH * y) + x] = c;
}

/**
 * drawRect - draw a rectangle
 * @x: x coordinate
 * @y: y coordinate
 * @width: rectangle width
 * @height: rectangle height
 * @color: pixel color
*/

void draw_rect(int x, int y, int width, int height, color_t color)
{
	int i, j;
	for (i = x; i <= (x + width); i++)
		for (j = y; j <= (y + height); j++)
			set_pixel_color(i, j, color);
}

/**
 * draw_line - Draws a line between two points on the screen.
 * @x0: The x-coordinate of the starting point.
 * @y0: The y-coordinate of the starting point.
 * @x1: The x-coordinate of the ending point.
 * @y1: The y-coordinate of the ending point.
 * @c: The color of the line.
 *
 * This function uses a linear interpolation algorithm to draw a line
 * between the points (x0, y0) and (x1, y1). It calculates the increments
 * for x and y based on the longer side of the rectangle formed by the
 * two points and draw the pixels along the line.
 */
void draw_line(int x0, int y0, int x1, int y1, color_t c)
{
	float x_inc, y_inc, current_x, current_y;
	int i, longest_side, dx, dy;

	dx = x1 - x0;
	dy = y1 - y0;

	longest_side = (abs(dx) >= abs(dy)) ? abs(dx) : abs(dy);
	
	x_inc = dx / (float)longest_side;
	y_inc = dy / (float)longest_side;

	current_x = x0;
	current_y = y0;

	for (i = 0; i <= longest_side; i++)
	{
		set_pixel_color(round(current_x), round(current_y), c);
		current_x += x_inc;
		current_y += y_inc;
	}
}
