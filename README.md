# The MazeGame
###         Dive headfirst into the world of 3D mazes. Clone the repository, follow the getting started guide, and embark on your journey !
![textured_1](https://github.com/G-omar-H/3D-Maze-Game/blob/main/screenshots/textured_1.png)
-----

### How to Compile and Run

#### Requirements
  [SDL2](https://www.libsdl.org/download-2.0.php) and [SDL2_image](https://www.libsdl.org/projects/SDL_image/) are required to compile and use this program

#### Instructions
- `git clone https://github.com/G-omar-H/3D-Maze-Game.git`
- `cd 3D-Maze-Game`
- `make -f Makefile`
-  Run the MazeGame : `./TheMaze`
-  Enjoy!

#### Bonus
Custom maps can be created by editing the text files in the `maps` directory. The map files are parsed by the program and used to draw the maze.
To run the maze with a custom map:
- `./TheMaze maps/<map_name>` 

#### Option
- Disable textures: `./TheMaze no_tex` or `./TheMaze maps/<map_name> no_tex`

-----

### Synopsis
This 3D maze uses raycasting to draw the maze walls, utilizing [LodeV's](http://lodev.org/cgtutor/raycasting.html) method of using vectors to calculate ray length. By default the maze uses textures but textures can be disabled on execution.

#### Controls
- `W` : move forward
- `S` : move backward
- `A` : rotate camera left
- `D` : rotate camera right
- `Q` : strafe left
- `E` : strafe right
- `F` : toggle fullscreen
- `ESC` : quit

![textured_3](https://github.com/G-omar-H/3D-Maze-Game/blob/main/screenshots/tectured_2.png)

#### Maps
The maps are defined in 2D arrays in text files, which are parsed when passed as an argument to the maze executable. `0` represents open space, all other integers are drawn as different wall's types.

Example:
```
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1
1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1
1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1
1 0 0 0 0 0 2 2 2 2 2 0 0 0 0 3 0 3 0 3 0 0 0 1
1 0 0 0 0 0 2 0 0 0 2 0 0 0 0 0 0 0 0 0 0 0 0 1
1 0 0 0 0 0 2 0 0 0 2 0 0 0 0 3 0 0 0 3 0 0 0 1
1 0 0 0 0 0 2 0 0 0 2 0 0 0 0 0 0 0 0 0 0 0 0 1
1 0 0 0 0 0 2 2 0 2 2 0 0 0 0 3 0 3 0 3 0 0 0 1
1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1
1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1
1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1
1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1
1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1
1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1
1 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1
1 4 4 4 4 4 4 4 4 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1
1 4 0 4 0 0 0 0 4 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1
1 4 0 0 0 0 5 0 4 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1
1 4 0 4 0 0 0 0 4 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1
1 4 0 4 4 4 4 4 4 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1
1 4 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1
1 4 4 4 4 4 4 4 4 0 0 0 0 0 0 0 0 0 0 0 0 0 0 1
1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1
```

### To-Do
- Improved map parser
- Better error handling
- More textures
- Enemies / obstacles / objects
- Maze goal that loads next map
- Rain

### Resources
- [SDL2 API](https://wiki.libsdl.org/CategoryAPI)
- [LazyFoo Beginning Game Programming](http://lazyfoo.net/tutorials/SDL/index.php)
- [Ray-Casting Tutorial For Game Development And Other Purposes by F. Permadi](http://permadi.com/1996/05/ray-casting-tutorial-table-of-contents/)
- [LodeV Raycasting Tutorial](http://lodev.org/cgtutor/raycasting.html)
- [Game Engine Black Book](https://www.amazon.com/Game-Engine-Black-Book-Wolfenstein/dp/1539692876)

### Contact
Feel free to contact me at [Oghazi@proton.me](mailto:Oghazi@proton.me) with any questions or suggestions. 

### License
This project is licensed under the MIT License - see the [LICENSE](https://github.com/G-omar-H/3D-Maze-Game/blob/main/LICENSE.md) file for details!