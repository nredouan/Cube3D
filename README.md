*This project has been created as part of the 42 curriculum by nredouan, scegla.*

## Description

Cub3D is a project inspired by the Wolfenstein 3D rendering engine. It is a mini-FPS in first-person view, developed in C with the macrolibx, using the raycasting technique to generate a 3D environment from a 2D map. We receive the map as an argument in the format .cub. The main objective of Cub3D is to create a simplified 3D rendering engine using raycasting. This project allows users to:

- Understand the basics of 3D rendering without using an advanced graphics engine.
- Manipulating mathematical concepts such as vectors, angles, and projections.
- Manage user input for player movement and rotation.
- Implement robust parsing to read and validate configuration files.

#### Key Features :

- 3D rendering via raycasting: simulation of ray projection to determine the distance to walls and display a 3D perspective.
- Texture management: applying textures to walls, floors and ceilings for a realistic rendering.
- Smooth movement: handling of forward/backward movements and left/right rotations with collision detection.
- Map parsing: reading .cub files containing map configuration, textures, and colors.
- Minimap: displays a 2D map to visualize the player's position and the environment.
- Optimizations: correction of "fish-eye" distortion and improvement of rendering performance.

## Instructions

The project is compiled using a Makefile with the flags : "-Wall -Wextra -Werror". The Makefile includes the following rules:
$(NAME), all, clean, fclean, and re.

- To compile the program, run: "make"
- To execute the program, run: "./cub3D [the name of your map in .cub format]"
- To exit the window you can click on the cross or the esc key

## Resources

- https://lodev.org/cgtutor/raycasting.html (to understand raycasting);
- https://www.youtube.com/watch?v=gYRrGTC7GtA (also to understand raycasting);
- https://macrolibx-legacy.kbz8.me/guides/getting_started/ (to understand macrolibx function);
- https://github.com/Mehdo0/cube3d/blob/main/README.md (A good README.md that inspired this one);
- Claude helped the project by explaining basic concept and the spelling of the README;