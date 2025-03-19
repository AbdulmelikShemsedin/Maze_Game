#include "../include/header.h"


/**
 * move_player - Update the player's position based on movement input.
 * @delta_time: Time elapsed since the last frame.
 */
void move_player(float delta_time)
{
	float move_step, new_player_x, new_player_y;

	player.rotation_angle += player.turn_direction * player.turn_speed * delta_time;
	move_step = player.walk_direction * player.walk_speed * delta_time;

	new_player_x = player.x + cos(player.rotation_angle) * move_step;
	new_player_y = player.y + sin(player.rotation_angle) * move_step;

	if (!detect_collision(new_player_x, new_player_y))
	{
		player.x = new_player_x;
		player.y = new_player_y;
	}
}

/**
 * renderPlayer - render the player on the screen
 *
*/

void render_player(void)
{
	draw_rect(
		player.x ,
		player.y ,
		player.width,
		player.height,
		0xFFFFFFFF
	);
}
