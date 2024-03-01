#include "define.h"

#include "terminal.h"
#include "utils.h"
#include "draw.h"
#include "control.h"
#include "game.h"

using namespace std::chrono_literals;


void init()
{ // 初始化
    tc::clean_screen();
    gm::start_listener();//运行另外一个线程，接受键盘输入
    //游戏初始化
    gm::init();
}

void loop()
{ // 主循环
    int i = 1;
    while (gm::running)
    {
        //绘制窗口
        tc::clean_screen();
        tc::hide_cursor();
        dw::window(1, 1, 9, 6, "Hlod");
        dw::window(1, 10, 12, 22, "Tetriz");
        dw::window(7, 1, 9, 16, "Status");
        dw::window(19, 22, 8, 4, "Info");
        dw::window(1, 22, 8, 18, "Next");
        //帧率显示
        tc::move_to(10, 4);
        std::cout << "FPS:" << ut::fps();
        //移动控制
        tc::move_to(gm::row, ut::block2col(gm::col));
        //方块显示
        tc::set_back_color(15);
        std::cout << "  ";
        tc::reset_color();
        std::cout << std::flush;//用于刷新输出缓冲区，使得cout立即输出缓冲区中的内容而不需要等到缓冲区满了

        std::this_thread::sleep_for(32ms); // 600帧
    }
}

void exit()
{ // 退出
    tc::show_cursor();
    tc::reset_color();
    tc::clean_screen();

    tc::move_to(1,1);
    tc::set_fore_color(9);
    std::cout<<"Byel"<<std::endl;
    tc::reset_color();
}

int main()
{

    init();
    loop();
    exit();

    return 0;
}