#include "../include/header.h"


bool GameRunning = true;

/*
 * main - main function
 *
 * Return: 0
 */

int main(void)
{
	if (!initializeWindow())
		return 1;

	while (GameRunning)
	{
		userInput();
	}
	destroyWindow();
	return 0;
}

