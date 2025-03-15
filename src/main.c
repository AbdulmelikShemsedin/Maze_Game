#include "../include/header.h"


bool GameRunning = true;
void setup_game(void)
{

	player.x = SCREEN_WIDTH / 2;
	player.y = SCREEN_HEIGHT / 2;
	player.width = 10;
	player.height = 30;
	player.walkDirection = 0;
	player.walkSpeed = 100;
}


/*
 * main - main function
 *
 * Return: 0
 */

int main(void)
{
	if (!initializeWindow())
		return 1;
	setup_game();

	while (GameRunning)
	{
		getPlayerInput();
		movePlayer();

		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
		SDL_RenderClear(renderer);

		renderPlayer();
		SDL_RenderPresent(renderer);
	}
	destroyWindow();
	return 0;
}

