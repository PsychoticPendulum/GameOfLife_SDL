# GameOfLife_SDL
An implementation of John Conway's Game of Life in C using the SDL Librarry

Use the makefile or
```
gcc src/*.c -o GameOfLife -Wall -std=c99 -lm -lSDL2 -lSDL2_ttf
```
## Conways Game of Life
Rules:
    *Any live cell with fewer than two live neighbours dies, as if by underpopulation.
    *Any live cell with two or three live neighbours lives on to the next generation.
    *Any live cell with more than three live neighbours dies, as if by overpopulation.
    *Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.
<a href="https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life">About<a>
