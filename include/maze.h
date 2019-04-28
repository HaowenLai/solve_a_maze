// @Description: A structure representing the maze
// @Author: Derek Lai
// @Date: 2019/4/28

#ifndef __MAZE_H__
#define __MAZE_H__

class Maze
{
public:
    enum MazeState
    {
        OFF = 0,
        ON = 1
    };
    int height = 0;
    int width = 0;

    Maze(int h, int w); // height and width
    ~Maze();

    // Return the reference of the mate state of coordinate (x, y),
    //you can read or modify the value.
    // @param x: the x of the maze
    // @param y: the y of the maze
    // @return: the reference of the state at (x, y).
    MazeState& at(int x, int y);

private:
    MazeState *maze_matrix;
};

#endif
