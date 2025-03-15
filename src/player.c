#include "../include/header.h"

player_s player;
/**
 * movePlayer - set the next position of the player
 * 
*/

void movePlayer()
{
	float frameTime = calculateDeltaTime();
	float moveStep, newPlayerX, newPlayerY;

	moveStep = player.walkDirection * player.walkSpeed * frameTime;

	newPlayerX = player.x +  moveStep;
	newPlayerY = player.y + moveStep;
	player.x = newPlayerX;
	player.y = newPlayerY;	
}

/*
 * calculateDeltaTime - Calculates the time elapsed since the last frame.
 *
 * This function computes the delta time (Δt) in seconds by measuring
 * the difference between the current frame time and the previous frame time.
 * Delta time is used to ensure smooth, frame-rate independent movement.
 *
 *
 * Return: The elapsed time (Δt) in seconds as a float.
 */
float calculateDeltaTime(void)
{
    static Uint32 lastFrameTime = 0;
    Uint32 currentFrameTime = SDL_GetTicks();
    float deltaTime = (currentFrameTime - lastFrameTime) / 1000.0f;
    lastFrameTime = currentFrameTime;
    return deltaTime;
}

/**
 * renderPlayer - render the player
 *
*/


void renderPlayer(void) {

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);

    SDL_Rect playerRect = {
        (int)player.x,
        (int)player.y,
	(int)player.width,
        (int)player.height
    };

    SDL_RenderFillRect(renderer, &playerRect);
}
