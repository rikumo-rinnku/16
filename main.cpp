#include <iostream>
#include <thread>
#include <chrono>
#include "terminal.h"
#include "utils.h"
#include "draw.h"
using namespace std::chrono_literals;



void init(){//初始化
    tc::clean_screen();
    tc::hide_cursor();
    dw::window(1,1,9,6,"Hlod");
    dw::window(1,10,12,22,"Tetriz");
    dw::window(7,1,9,16,"Status");
    dw::window(19,22,8,4,"Info");
    dw::window(1,22,8,18,"Next");

}

void loop(){//主循环
    int i = 1;
    while(true){
        
        //帧率显示
        tc::move_to(10,4);
        std::cout<<"FPS:"<<ut::fps();

        tc::move_to(5,10);
        tc::set_back_color(15);
        std::cout<<"  ";
        tc::reset_color();
        std::cout<<std::flush;
        std::this_thread::sleep_for(16ms);//600帧
    }
}

void exit(){//退出
    tc::show_cursor();
    tc::reset_color();
}


int main() {

    init();
    loop();
    exit();

    return 0;
}