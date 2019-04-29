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
    enum RtKey
    {
        KEY_SAVE,
        KEY_OUTPUT_CONSOLE
    };
    int height = 0;
    int width = 0;

    Maze(int h, int w); // height and width
    ~Maze();

    // Interact with the maze image. You can click on the block
    //to change its state and press key `s` to save the maze to
    //file, and key `c` to output the maze on the console, key
    //`q` to quit the interaction mode.
    RtKey interact();

    void showMazeOnConsole() const;
    void saveMaze(const char *path) const;
    void loadMaze(const char *path);

private:
    MazeState *maze_matrix;

    // Return the reference of the mate state of coordinate (x, y),
    //you can read or modify the value.
    // @param x: the x of the maze
    // @param y: the y of the maze
    // @return: the reference of the state at (x, y).
    MazeState& at(int x, int y);

    // mouse call back function, use to handle the mouse event.
    //Called by opencv.
    void onMouseCallBack(int event, int x, int y, int flags, void *data);
};

#endif
