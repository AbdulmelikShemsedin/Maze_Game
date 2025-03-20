CC = gcc
CFLAGS = -Wall -Wextra -g `sdl2-config --cflags`
LDFLAGS = `sdl2-config --libs` -lm
SRC = src/main.c src/input.c src/window.c src/player.c src/draw.c src/map.c src/ray.c src/ray_aux.c src/wall.c
OBJ = $(SRC:.c=.o)
TARGET = maze_game

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ) $(LDFLAGS)

clean:
	rm -f $(OBJ) $(TARGET)

