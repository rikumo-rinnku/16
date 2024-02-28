#include <iostream>
#include <thread>
#include <chrono>
#include "terminal.h"
#include "utils.h"

using namespace std::chrono_literals;



void init(){//初始化
    tc::hide_cursor();


}

void loop(){//主循环
    int i = 1;
    while(true){
        tc::clean_screen();
        //帧率显示
        tc::move_to(1,1);
        std::cout<<"FPS:"<<ut::fps();

        tc::move_to(i++%20,10);
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