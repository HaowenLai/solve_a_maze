// @Description: A structure representing the maze
// @Author: Derek Lai
// @Date: 2019/4/28

#include "maze.h"
#include <assert.h>
// ----------------- public function -----------------
Maze::Maze(int h, int w)
{
    height = h;
    width = w;
    maze_matrix = new MazeState[h * w];
}

Maze::~Maze()
{
    delete[] maze_matrix;
}

Maze::MazeState& Maze::at(int x, int y)
{
    int index = y * width + x;
    return maze_matrix[index];
}
