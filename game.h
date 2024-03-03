#pragma once
#include "tetromino.h"
namespace gm
{
    extern bool running;//判断游戏是否在运行
    void init();//游戏开始初始化，选定方格位置

    void quit();//游戏退出
    void rotate();//旋转
    void left();
    void reight();
    void down();

    //记录光标位置
    extern int row,col;

    extern Tetromino cur;
} // namespace gm
