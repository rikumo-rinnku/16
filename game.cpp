#include "game.h"
#include "define.h"

namespace gm
{
    bool running;
    int row,col;
    void init()
    {
        running = true;
        row = 2;
        col = 15;
    }
    void quit(){
        running = false;
    }
    void rotate()
    {
        row--;
    }
    void left()
    {
        col--;
    }
    void reight()
    {   
        col++;
    }
    void down()
    {
        row++;
    }
} // namespace gm
