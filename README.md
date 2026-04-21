*This project has been created as part of the 42 curriculum by alebarbo, lseabra-.*

# cub3D

## Description
**cub3D** is a project designed to improve our graphics understanding using the **MiniLibX** library. The objective is to create a first-person closed-maze game, parse a map, show textures on the screen and compute the player's movement.

The map parsing is done by verifying the order of instructions inside the map file. The first set of instructions must contain a relative path to a texture file for each lateral face of a cube (North, South, East and West) and 2 sets of **RGB** colors for the ceiling and floor.

The second set is the map itself, where the only information allowed are whitespaces, the player spawn point represented by the first letter of any of the four cardinal directions, **0**'s representing empty cubes where the player can walk and **1**'s representing cubes that will act as walls.

To identify and calibrate the image shown on the screen, a raycaster must be used. Our project uses a **digital differential analyzer** (DDA) algorithm to implement the raycaster, which consists of a series of rays emitted from the player position in the direction the player is facing.

The raycaster then checks if a wall is hit, and the distance it travelled before hitting the wall indicates how far to the wall the player is. After that, our texturizer draws the textures, scaling them accordingly to the information acquired by the raycaster.

The player's movement are done by simple linear transformations, checking if the player is on an empty cube or not and setting the new position. If the player is turning, the transformations are based on angles and use **sin** and **cos** to make the player face a new direction.

## Instructions
**Installation**
* Run `make` on the root folder of the project.
* For bonus functionalities, run `make bonus` on the root folder of the project.

**Execution**
* Run `./cub3D` on the root folder of the project after installation.
* For bonus functionalities, run `./cub3D_bonus` on the root folder of the project after installation.

The program accepts 1 argument, the path to a configuration file:
* The file extension must be `.cub`.
* The file must contain 4 elements representing the textures for each lateral face of the cube, in the following format:
<pre><b>NO ./path_to_texture
SO ./path_to_texture
EA ./path_to_texture
WE ./path_to_texture</b></pre>
* The file must contain 2 elements representing the ceiling and floor RGB colors in range [0,255], in the following format (the values are just an example):
<pre><b>C  0,255,255
F  255,0,50</b></pre>
* The file must contain as its last element a map, with the labyrinth surrounded by walls (**1**), and the player spawn position (indicated by the letters **N, S, E, W**) must be inside the labyrinth:

*Example 1*
<pre><b>111111
100101
101001
1100N1
111111</b></pre>

*Example 2*
<pre><b>        1111111111111111111111111
        1000000000110000000000001
        1011000001110000000000001
        1001000000000000000000001
111111111011000001110000000000001
100000000011000001110111111111111
11110111111111011100000010001
11110111111111011101010010001
11000000110101011100000010001
10000000000000001100000010001
10000000000000001101010010001
11000001110101011111011110N0111
11110111 1110101 101111010001
11111111 1111111 111111111111</b></pre>

* If any misconfiguration of any kind is encountered in the file, the program will exit, returning a message expliciting the error.

**Player Controls**
* Move Forward - W
* Move Backwards - S
* Move Left - A
* Move Right - D
* Turn Left - ←
* Turn Right - →
* Turn Character - Mouse movement
* Pause Game - P
* Exit Game - ESC

## Resources
[Lode's Computer Graphics Tutorial](https://lodev.org/cgtutor/raycasting.html)  
[Harm Smith's MiniLibX Docs](https://harm-smits.github.io/42docs/libs/minilibx)  
[Aurelien Brabant's Pixel drawing with MiniLibX](https://aurelienbrabant.fr/blog/pixel-drawing-with-the-minilibx)  
[DeepWiki 42paris/minilibx-linux - Direct Pixel Access](https://deepwiki.com/42paris/minilibx-linux/6.2-direct-pixel-access)  
[Jun Han Ng's cub3d guide](https://hackmd.io/@nszl/H1LXByIE2)
