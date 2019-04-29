// @Description: A structure representing the maze
// @Author: Derek Lai
// @Date: 2019/4/28

#include "maze.h"
#include <opencv2/opencv.hpp>

// ----------------- public function -----------------
Maze::Maze(int h, int w)
{
    height = h;
    width = w;
    maze_matrix = new MazeState[h * w]{};
}

Maze::~Maze()
{
    delete[] maze_matrix;
}

// Interact with the maze image. You can click on the block
//to change its state and press key `s` to save the maze to
//file, and key `c` to output the maze on the console, key
//`q` to quit the interaction mode.
Maze::RtKey Maze::interact()
{
    // define the size of each block
    using namespace cv;
    const int blkSize = 25;
    auto img_height = height * blkSize;
    auto img_width = width * blkSize;

    // prepare pieces and init image
    Mat piece_on(blkSize, blkSize, CV_8UC3, Scalar(0, 200, 100));
    Mat piece_off(blkSize, blkSize, CV_8UC3, Scalar(255, 255, 255));
    rectangle(piece_on, Rect(0, 0, blkSize, blkSize), Scalar(0, 0, 0), 2);
    rectangle(piece_off, Rect(0, 0, blkSize, blkSize), Scalar(0, 0, 0), 2);
    //
    Mat img(img_height, img_width, CV_8UC3, Scalar(255, 255, 255));
    for (int w = 0; w < width; w++)
    {
        for (int h = 0; h < height; h++)
        {
            if (this->at(w,h) == ON)
                piece_on.copyTo(img(Rect(w * blkSize, h * blkSize, blkSize, blkSize)));
            else
                piece_off.copyTo(img(Rect(w * blkSize, h * blkSize, blkSize, blkSize)));
        }
    }

    // TODO: mouse handler...

    imshow("show", img);
    waitKey(0);
}

// ----------------- private function -----------------

// Return the reference of the mate state of coordinate (x, y),
//you can read or modify the value.
// @param x: the x of the maze
// @param y: the y of the maze
// @return: the reference of the state at (x, y).
Maze::MazeState& Maze::at(int x, int y)
{
    int index = y * width + x;
    return maze_matrix[index];
}
