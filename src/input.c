#include "../include/header.h"
/*
 * userInput - process input from the keyboard
 *
 */
void userInput(void)
{
	SDL_Event event;

	SDL_PollEvent(&event);

	if (event.type == SDL_QUIT)
		GameRunning = false;
}
