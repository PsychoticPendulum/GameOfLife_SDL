# GameOfLife_SDL
An implementation of John Conway's Game of Life in C using the SDL Librarry

Use the makefile or
```
gcc src/*.c -o GameOfLife -Wall -std=c99 -lm -lSDL2 -lSDL2_ttf
```
## Conways Game of Life
Rules:
<ul>
   <li>Any live cell with fewer than two live neighbours dies, as if by underpopulation.</li>
   <li>Any live cell with two or three live neighbours lives on to the next generation.</li>   
   <li>Any live cell with more than three live neighbours dies, as if by overpopulation.</li>
   <li>Any dead cell with exactly three live neighbours becomes a live cell, as if by reproduction.</li>
</ul>
<a href="https://en.wikipedia.org/wiki/Conway%27s_Game_of_Life">Wikipedia<a>

## Video Demo
   [![IMAGE ALT TEXT HERE](https://img.youtube.com/vi/jChg_saUa6I/0.jpg)](https://www.youtube.com/watch?v=jChg_saUa6I)
