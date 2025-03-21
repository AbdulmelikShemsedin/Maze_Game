#include "../include/header.h"

/**
 * renderer - The SDL renderer used to draw graphics.
 */
static SDL_Renderer *renderer;

color_t *color_buffer;

/**
 * window - The SDL window used to display the application.
 */
static SDL_Window *window;

/**
 * color_buffer_texture - The SDL texture used to display the color buffer.
 */
static SDL_Texture *color_buffer_texture;

/**
 * initialize_window - Initializes the SDL window and related resources.
 *
 * This function initializes the SDL library, creates a borderless window
 * covering the full screen, sets up a renderer, allocates memory for the
 * color buffer, and creates a texture to display the color buffer.
 *
 * Return: true on success, false on failure.
 */
bool initialize_window(void)
{
	SDL_DisplayMode display_mode;
	int full_screen_width, full_screen_height;

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0)
	{
		fprintf(stderr, "Error initializing SDL.\n");
		return (false);
	}

	SDL_GetCurrentDisplayMode(0, &display_mode);
	full_screen_width = display_mode.w;
	full_screen_height = display_mode.h;

	window = SDL_CreateWindow(
			NULL,
			SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED,
			full_screen_width,
			full_screen_height,
			SDL_WINDOW_BORDERLESS
			);
	
	if (!window)
	{
		fprintf(stderr, "Error creating SDL window.\n");
		return (false);
	}

	renderer = SDL_CreateRenderer(window, -1, 1);
	if (!renderer)
	{
		fprintf(stderr, "Error creating SDL renderer.\n");
		return (false);
	}
	SDL_SetRenderDrawBlendMode(renderer, SDL_BLENDMODE_BLEND);
	color_buffer = malloc(sizeof(color_t) * SCREEN_WIDTH * SCREEN_HEIGHT);
	if (!color_buffer)
	{
		fprintf(stderr, "Error allocating memory for color buffer.\n");
		return (false);
	}
	
	
	color_buffer_texture = SDL_CreateTexture(
			renderer,
			SDL_PIXELFORMAT_RGBA32,
			SDL_TEXTUREACCESS_STREAMING,
			SCREEN_WIDTH,
			SCREEN_HEIGHT
			);
	if (!color_buffer_texture)
	{
		fprintf(stderr, "Error creating SDL texture.\n");
		return (false);
	}

	return (true);
}
/*
 * destroy_window - Cleans up resources and shuts down the SDL window.
 *
 * This function frees the color buffer, destroys the SDL renderer and window,
 * and shuts down the SDL subsystem. It should be called before exiting the program
 * to ensure proper cleanup of resources.
 */

void destroy_window(void)
{
	free(color_buffer);
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}


/*
 * clear_color_buffer - Fills the color buffer with a specified color.
 * @color: The color to fill the buffer with.
 *
 * This function iterates over the entire color buffer and sets each pixel
 * to the specified color, effectively clearing the screen to that color.
 */

void clear_color_buffer(color_t color)
{
	int i;

	for (i = 0; i < SCREEN_WIDTH * SCREEN_HEIGHT; i++)
		color_buffer[i] = color;
}

/**
 * render_color_buffer - Updates the screen with the contents of the color buffer.
 *
 * This function updates the SDL texture with the current color buffer data,
 * copies the texture to the renderer, and presents the renderer to display
 * the updated frame on the screen.
 */
void render_color_buffer(void)
{
	SDL_UpdateTexture(
			color_buffer_texture,
			NULL,
			color_buffer,
			(int)(SCREEN_WIDTH * sizeof(color_t))
			);
	SDL_RenderCopy(renderer, color_buffer_texture, NULL, NULL);
	SDL_RenderPresent(renderer);
}
