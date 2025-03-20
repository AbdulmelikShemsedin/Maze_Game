#include "../include/header.h"

bool game_running = false;
int ticks_last_frame;
player_t player;


/**
 * setup_game - initialize player variables and load wall textures
 *
*/

void setup_game(void)
{

	player.x = SCREEN_WIDTH / 2;
	player.y = SCREEN_HEIGHT / 2;
	player.width = 10;
	player.height = 30;
	player.walk_direction = 0;
	player.walk_speed = 70;
	player.turn_direction = 0;
	player.turn_speed = 45 * (PI / 180);
	player.rotation_angle = PI ;
}


/**
 * update_game - Updates the game state, including delta time, player movement, and ray casting.
 */
void update_game(void)
{
	float delta_time;
	int time_to_wait = FRAME_TIME_LENGTH - (SDL_GetTicks() - ticks_last_frame);

	if (time_to_wait > 0 && time_to_wait <= FRAME_TIME_LENGTH)
	{
		SDL_Delay(time_to_wait);
	}

	delta_time = (SDL_GetTicks() - ticks_last_frame) / 1000.0f;
	ticks_last_frame = SDL_GetTicks();

	move_player(delta_time);
	cast_all_rays();
}


/**
 * main - Entry point of the program.
 *
 * Return: 0 on successful execution.
 */
int main(void)
{
	game_running = initialize_window();

	setup_game();

	while (game_running)
	{
		user_input();
		update_game();
		clear_color_buffer(0xFF000000);
		render_wall();
		if (show_map)
		{
			render_map();
			render_rays();
			render_player();
		}
		
		
		render_color_buffer();
	}
	destroy_window();
	return (0);
}
