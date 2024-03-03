#include "game.h"
#include "define.h"
#include "terminal.h"

namespace gm
{
    bool running;
    int row,col;

    Tetromino cur;
    void init()
    {
        running = true;
        row = 2;
        col = 15;
        cur = S;
    }
    void quit(){
        running = false;
    }
    void rotate()
    {
        cur = rotate(cur);
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
