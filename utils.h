#pragma once
#include <iostream>
#include <string>

namespace ut{
    //帧率计算
    int fps();
    //utf32编码转为utf8编码
    std::string utf32_to_utf8(std::u32string);
}

