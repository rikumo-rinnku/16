#include "define.h"
#include "utils.h"

using namespace std::chrono_literals;

namespace ut
{

    int fps()
    {
        static auto start = std::chrono::steady_clock::now(); //开始时间
        auto end = start;//当前时间
        static int frame_count = 0; // 帧数记录
        static int fps = 0;         // 帧率

        end = std::chrono::steady_clock::now();//获取当前时间
        frame_count++;
        if (end - start > 1s)//如果间隔1s就计算帧数fps
        {
            fps = frame_count;

            frame_count = 0;
            start = end;
        }
        return fps;
    }

    std::string utf32_to_utf8(std::u32string str)
    {
        static std::wstring_convert<std::codecvt_utf8<char32_t>, char32_t> convert;
        return convert.to_bytes(str);
    }


} // namespace name