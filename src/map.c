#include "../include/header.h"

static const int map[MAP_NUM_ROWS][MAP_NUM_COLS] = {
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 0, 1, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 1},
	{1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1},
	{1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1},
	{1, 1, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 1},
	{1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 1},
	{1, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 1},
	{1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1},
	{1, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 0, 1, 0, 1, 0, 1},
	{1, 0, 0, 0, 1, 0, 1, 0, 1, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1},
	{1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 0, 0, 1, 0, 1},
	{1, 0, 0, 0, 0, 0, 0, 0, 1, 1, 0, 0, 0, 0, 1, 1, 0, 0, 0, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};


/**
 * detect_collision - Checks if there could be a collision with a wall
 *                   at the next player position.
 * @x: The next x-coordinate of the player.
 * @y: The next y-coordinate of the player.
 *
 * Return: true if a collision is detected, false otherwise.
 */
bool detect_collision(float x, float y)
{
	int map_x, map_y;

	if (!is_inside_map(x, y))
		return (true);

	map_x = (int)(x / TILE_SIZE);
	map_y = (int)(y / TILE_SIZE);

	return (map[map_y][map_x] != 0);
}

/**
 * is_inside_map - Check if the given coordinates are within the map boundaries.
 * @x: The x-coordinate to check.
 * @y: The y-coordinate to check.
 *
 * Return: true if the coordinates are within the map, false otherwise.
 */
bool is_inside_map(float x, float y)
{
	return (x >= 0 && x < MAP_NUM_COLS * TILE_SIZE &&
			y >= 0 && y < MAP_NUM_ROWS * TILE_SIZE);
}
/**
 * get_map_value - Retrieve the value at a specific position in the map.
 * @row: The row index in the map.
 * @col: The column index in the map.
 *
 * Return: The value at the specified map position.(0 for empty space, 1 for wall, etc.)
 */

int get_map_value(int row, int col)
{
	if (row < 0 || row >= MAP_NUM_ROWS || col < 0 || col >= MAP_NUM_COLS)
		return (-1);

	return (map[row][col]);

}

/**
 * render_map - Renders the map with walls and open spaces.
 *
*/

void render_map(void)
{
	int row, col, tile_x, tile_y;
	color_t tile_color;

	for (row = 0; row < MAP_NUM_ROWS; row++)
	{
		for (col = 0; col < MAP_NUM_COLS; col++)
		{
			tile_x = col * TILE_SIZE * SCALE_FACTOR;
			tile_y = row * TILE_SIZE * SCALE_FACTOR;
			tile_color = map[row][col] != 0 ? 0xFFFFFFFF : 0x00000000;

			draw_rect(
				tile_x ,
				tile_y,
				TILE_SIZE * SCALE_FACTOR,
				TILE_SIZE * SCALE_FACTOR,
				tile_color
			);
		}
	}
}
