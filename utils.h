#pragma once
#include <iostream>
#include <string>

namespace ut{
    //帧率计算
    int fps();
    //utf32编码转为utf8编码
    std::string utf32_to_utf8(std::u32string);
    //因为一个格子占据两个光标，所以宽度要记得*2，绘制时候用空格对齐
    inline int block2col(int b)
    {
        return 2 * b - 1;
    }
}

