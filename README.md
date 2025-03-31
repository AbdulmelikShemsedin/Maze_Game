## Maze_Game
 The Maze is a 3D Maze game that uses ray casting to render a 2D map into a 3D navigable world!
# About SDL2
Simple DirectMedia Layer is a cross-platform development library designed to provide low level access to audio, keyboard, mouse, joystick, and graphics hardware via OpenGL and Direct3D. It is used by video playback software, emulators, and popular games including Valve's award winning catalog and many Humble Bundle games. for more information on SDL2
# Requirements to Play
Linux/ubuntu or Macos<br>
SDL2 and its sdl_image
# Installation
Sdl2 installation download the installation script install_SDL2.sh and run it in your ubuntu Terminal as follows:<br>
 root@h:cd ~/Downloads$ ls install_SDL2.sh root@h:cd ~/Downloads$chmod 755 install_SDL2.sh root@h:cd ~/Downloads$sudo ./install_SDL2.sh
# Play the game
clone the <a href="https://github.com/AbdulmelikShemsedin/Maze_Game">github repository</a><br>
Compile all .c files in the maze directory:<br>
<code>gcc -Wall -Werror -Wextra -pedantic ./src/*.c -lm $(sdl2-config --cflags --libs) -lSDL_image -o maze</code><br>
Execute ./mazea and play game.
Use up and down arrow keys to move forward and backward (keys w and s serve the same function)
Use right and left arrow keys to turn the camera arround (keys d and a serve the same function)
# Controls
W or up arrow key - Moving forward S or down arrow - Moving backward left arrow key - to rotate the player in counter clock wise direction right arrow key - to rotate the player in clock wise direction

# project Demo
3D Maze

# Authors
Natan Sahlu (https://github.com/nati-sahlu)<br>
Abdulmelik Shemsedin (https://github.com/AbdulmelikShemsedin)
