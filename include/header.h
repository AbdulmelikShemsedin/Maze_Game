#ifndef HEADER_H
#define HEADER_H

#include <SDL2/SDL.h>
#include <stdint.h>
#include <math.h>
#include <limits.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

/* Constants */
#define PI 3.14159265
#define TWO_PI 6.28318530
#define TILE_SIZE 64
#define SCREEN_WIDTH (MAP_NUM_COLS * TILE_SIZE)
#define SCREEN_HEIGHT (MAP_NUM_ROWS * TILE_SIZE)
#define FOV_ANGLE (60 * PI / 180)
#define NUM_RAYS SCREEN_WIDTH
#define PROJ_PLANE ((SCREEN_WIDTH / 2) / tan(FOV_ANGLE / 2))
#define FPS 30
#define FRAME_TIME_LENGTH (1000 / FPS)
#define MAP_NUM_ROWS 15
#define MAP_NUM_COLS 20
#define SCALE_FACTOR 0.2

typedef uint32_t color_t;

extern bool game_running;
extern bool show_map;
void user_input(void);
bool initialize_window(void);
void destroy_window(void);
void clear_color_buffer(color_t color);
void render_color_buffer(void);
void set_pixel_color(int x, int y, color_t color);
void draw_rect(int x, int y, int width, int height, color_t color);
void draw_line(int x0, int y0, int x1, int y1, color_t color);


bool detect_collision(float x, float y);
bool is_inside_map(float x, float y);
void render_map(void);
int get_map_value(int row, int col);

/* Structs and Functions for Player */

/**
 * struct player_s - Represents the player's state.
 * @x: The x-coordinate of the player.
 * @y: The y-coordinate of the player.
 * @width: The width of the player.
 * @height: The height of the player.
 * @turn_direction: The direction the player is turning (-1 for left, 1 for right).
 * @walk_direction: The direction the player is walking (-1 for back, 1 for forward).
 * @rotation_angle: The player's rotation angle in radians.
 * @walk_speed: The player's walking speed.
 * @turn_speed: The player's turning speed.
 */
typedef struct player_s
{
    float x;
    float y;
    float width;
    float height;
    int turn_direction;
    int walk_direction;
    float rotation_angle;
    float walk_speed;
    float turn_speed;
} player_t;

extern player_t player;

void move_player(float delta_time);
void render_player(void);

/* Structs and Functions for Ray Casting */

/**
 * struct ray_s - Represents a ray cast by the player.
 * @ray_angle: The angle of the ray.
 * @wall_hit_x: The x-coordinate where the ray hits a wall.
 * @wall_hit_y: The y-coordinate where the ray hits a wall.
 * @distance: The distance from the player to the wall hit.
 * @was_hit_vertical: Whether the wall hit was vertical.
 * @wall_hit_content: The content of the wall hit.
 */
typedef struct ray_s
{
    float ray_angle;
    float wall_hit_x;
    float wall_hit_y;
    float distance;
    bool was_hit_vertical;
    int wall_hit_content;
} ray_t;
extern color_t *color_buffer;
extern ray_t rays[NUM_RAYS];

float distance_between_points(float x1, float y1, float x2, float y2);
bool is_ray_facing_up(float angle);
bool is_ray_facing_down(float angle);
bool is_ray_facing_left(float angle);
bool is_ray_facing_right(float angle);
void cast_all_rays(void);
void cast_ray(float ray_angle, int strip_id);
void render_rays(void);
void horz_intersection(float ray_angle);
void vert_intersection(float ray_angle);

void renderCeil(void);
void render_floor(void);
void render_wall(void);
#endif

