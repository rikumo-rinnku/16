#pragma once
#include <string>
namespace dw
{
    void window(int top,int left,int width,int height,std::string title);
} // namespace dw
/*
这是绘制窗口部分，我们设定每一个格子占据两个光标，正好显示一格就是一个正方形
传入的函数参数是窗口顶端位置、长宽高、标题名
因为一个格子占据两个光标，所以宽度要记得*2，绘制时候用空格对齐
*/