#include "define.h"
#include "control.h"
#include "game.h"

namespace gm
{

    char command;

    std::map<char,std::function<void()>> comm_func{
        {KEY_Q,command_quit},
        {KEY_W,command_rotate},
        {KEY_S,command_down},
        {KEY_A,command_left},
        {KEY_D,command_reight},
    };
    // 做一个不缓存、不回显的输入
    char getch()
    {
        char c;
        struct termios old, cur;
        tcgetattr(0, &cur);
        old = cur;
        cfmakeraw(&cur);
        tcsetattr(0, 0, &cur);
        c = getchar();
        tcsetattr(0, 0, &old);
        return c;
    }

    void key_event()
    {

        while (running)
        {
            command = getch();
            comm_func[command]();
                
        }
    }

    void start_listener()
    {
        std::thread t(key_event);//一个新的线程t运行key_event函数
        t.detach();
    }

    void command_quit()
    {
        quit();
    }

    void command_rotate()
    {
        rotate();
    }

    void command_left()
    {
        left();
    }

    void command_reight()
    {
        reight();
    }

    void command_down()
    {
        down();
    }

} // namespace gm