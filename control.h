#pragma once

namespace gm
{
    extern char command;
    char getch(); // 做一个不缓存、不回显的输入
    void key_event();// 接受键盘输入并运行对应功能
    void start_listener();// 创建一个新的线程与主线程分离

    //键盘命令函数
    void command_quit();
    void command_rotate();
    void command_left();
    void command_reight();
    void command_down();
} // namespace gm
