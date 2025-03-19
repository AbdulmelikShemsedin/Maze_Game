#include "../include/header.h"


ray_t rays[NUM_RAYS];
static bool found_horz_wall_hit;
static bool found_vert_wall_hit;
static float horz_wall_hit_x;
static float horz_wall_hit_y;
static float vert_wall_hit_x;
static float vert_wall_hit_y;
static int horz_wall_content;
static int vert_wall_content;

/**
 * horz_intersection - Finds the horizontal intersection with a wall.
 * @ray_angle: The current ray angle.
 */
void horz_intersection(float ray_angle)
{
	float next_horz_touch_x, next_horz_touch_y, x_intercept, y_intercept, x_step, y_step;
	
	found_horz_wall_hit = false;
	horz_wall_hit_x = horz_wall_hit_y = horz_wall_content = 0;
	
	y_intercept = floor(player.y / TILE_SIZE) * TILE_SIZE;
	y_intercept += is_ray_facing_down(ray_angle) ? TILE_SIZE : 0;
	
	x_intercept = player.x + (y_intercept - player.y) / tan(ray_angle);
	y_step = TILE_SIZE;
	y_step *= is_ray_facing_up(ray_angle) ? -1 : 1;
	
	x_step = TILE_SIZE / tan(ray_angle);
	x_step *= (is_ray_facing_left(ray_angle) && x_step > 0) ? -1 : 1;
	x_step *= (is_ray_facing_right(ray_angle) && x_step < 0) ? -1 : 1;
	next_horz_touch_x = x_intercept;
	next_horz_touch_y = y_intercept;
	
	while (is_inside_map(next_horz_touch_x, next_horz_touch_y))
	{
		float x_to_check = next_horz_touch_x;
		float y_to_check = next_horz_touch_y + (is_ray_facing_up(ray_angle) ? -1 : 0);

		if (detect_collision(x_to_check, y_to_check))
		{
			horz_wall_hit_x = next_horz_touch_x;
			horz_wall_hit_y = next_horz_touch_y;
			horz_wall_content = get_map_value(
					(int)floor(y_to_check / TILE_SIZE),
					(int)floor(x_to_check / TILE_SIZE)
					);
			found_horz_wall_hit = true;
			break;
		}
		next_horz_touch_x += x_step;
		next_horz_touch_y += y_step;
	}
}
/**
 * vert_intersection - Finds the vertical intersection with a wall.
 * @ray_angle: The current ray angle.
 */
void vert_intersection(float ray_angle)
{
	float next_vert_touch_x, next_vert_touch_y;
	float x_intercept, y_intercept, x_step, y_step;

	found_vert_wall_hit = false;
	vert_wall_hit_x = 0;
	vert_wall_hit_y = 0;
	vert_wall_content = 0;

	x_intercept = floor(player.x / TILE_SIZE) * TILE_SIZE;
	x_intercept += is_ray_facing_right(ray_angle) ? TILE_SIZE : 0;
	y_intercept = player.y + (x_intercept - player.x) * tan(ray_angle);

	x_step = TILE_SIZE;
	x_step *= is_ray_facing_left(ray_angle) ? -1 : 1;
	y_step = TILE_SIZE * tan(ray_angle);
	y_step *= (is_ray_facing_up(ray_angle) && y_step > 0) ? -1 : 1;
	y_step *= (is_ray_facing_down(ray_angle) && y_step < 0) ? -1 : 1;

	next_vert_touch_x = x_intercept;
	next_vert_touch_y = y_intercept;

	while (is_inside_map(next_vert_touch_x, next_vert_touch_y))
	{
		float x_to_check = next_vert_touch_x + (is_ray_facing_left(ray_angle) ? -1 : 0);
		float y_to_check = next_vert_touch_y;
		
		if (detect_collision(x_to_check, y_to_check))
		{
			vert_wall_hit_x = next_vert_touch_x;
			vert_wall_hit_y = next_vert_touch_y;
			vert_wall_content = get_map_value(
					(int)floor(y_to_check / TILE_SIZE),
					(int)floor(x_to_check / TILE_SIZE)
					);
			found_vert_wall_hit = true;
			break;
		}

		next_vert_touch_x += x_step;
		next_vert_touch_y += y_step;
		}
}

/**
 * cast_ray - Cast a ray at a given angle and store the results.
 * @ray_angle: The angle at which the ray is cast.
 * @strip_id: The ID of the strip (ray index).
 */
void cast_ray(float ray_angle, int strip_id)
{
	float horz_hit_distance, vert_hit_distance;

	ray_angle = remainder(ray_angle, TWO_PI);
	if (ray_angle < 0)
		ray_angle = TWO_PI + ray_angle;

	horz_intersection(ray_angle);
	vert_intersection(ray_angle);
	
	horz_hit_distance = found_horz_wall_hit
		? distance_between_points(player.x, player.y, horz_wall_hit_x, horz_wall_hit_y)
		: FLT_MAX;

	vert_hit_distance = found_vert_wall_hit
		? distance_between_points(player.x, player.y, vert_wall_hit_x, vert_wall_hit_y)
		: FLT_MAX;

	if (vert_hit_distance < horz_hit_distance)
	{
		rays[strip_id].distance = vert_hit_distance;
		rays[strip_id].wall_hit_x = vert_wall_hit_x;
		rays[strip_id].wall_hit_y = vert_wall_hit_y;
		rays[strip_id].wall_hit_content = vert_wall_content;
		rays[strip_id].was_hit_vertical = true;
		rays[strip_id].ray_angle = ray_angle;
	}
	else
	{
		rays[strip_id].distance = horz_hit_distance;
		rays[strip_id].wall_hit_x = horz_wall_hit_x;
		rays[strip_id].wall_hit_y = horz_wall_hit_y;
		rays[strip_id].wall_hit_content = horz_wall_content;
		rays[strip_id].was_hit_vertical = false;
		rays[strip_id].ray_angle = ray_angle;
	}
}


/**
 * cast_all_rays - Cast all rays for the player's field of view.
 */
void cast_all_rays(void)
{
	int col;

	for (col = 0; col < NUM_RAYS; col++)
	{
		float ray_angle = player.rotation_angle +
			atan((col - NUM_RAYS / 2) / PROJ_PLANE);
		cast_ray(ray_angle, col);
	}
}



/**
 * renderRays - draw all the rays
 *
 */

void render_rays(void)
{
	int i;

	for (i = 0; i < NUM_RAYS; i += 50)
	{
		draw_line(
			player.x,
			player.y,
			rays[i].wall_hit_x,
			rays[i].wall_hit_y,
			0xFF0000FF
		);
	}
}
