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
	int grid_x, grid_y;

	if (x < 0 || x >= MAP_NUM_COLS * TILE_SIZE ||
			y < 0 || y >= MAP_NUM_ROWS * TILE_SIZE)
	{
		return (true);
	}

	grid_x = floor(x / TILE_SIZE);
	grid_y = floor(y / TILE_SIZE);
	return (map[grid_y][grid_x] != 0);
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
	return (x >= 0 && x <= MAP_NUM_COLS * TILE_SIZE &&
			y >= 0 && y <= MAP_NUM_ROWS * TILE_SIZE);
}
/**
 * get_map_value - Retrieve the value at a specific position in the map.
 * @row: The row index in the map.
 * @col: The column index in the map.
 *
 * Return: The value at the specified map position.
 */

int get_map_value(int row, int col)
{

	return (map[row][col]);

}

/**
 * renderMap - render the map grid.
 *
*/

void render_map(void)
{
	int i, j, tile_x, tile_y;
	color_t tile_color;

	for (i = 0; i < MAP_NUM_ROWS; i++)
	{
		for (j = 0; j < MAP_NUM_COLS; j++)
		{
			tile_x = j * TILE_SIZE;
			tile_y = i * TILE_SIZE;
			tile_color = map[i][j] != 0 ? 0xFFFFFFFF : 0x00000000;

			draw_rect(
				tile_x ,
				tile_y,
				TILE_SIZE,
				TILE_SIZE,
				tile_color
			);
		}
	}
}
