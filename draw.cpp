#include "draw.h"
#include "terminal.h"
#include <iostream>
#include "utils.h"

/*
        0	1	2	3	4	5	6	7	8	9	A	B	C	D	E	F
U+250x	─	━	│	┃	┄	┅	┆	┇	┈	┉	┊	┋	┌	┍	┎	┏
U+251x	┐	┑	┒	┓	└	┕	┖	┗	┘	┙	┚	┛	├	┝	┞	┟
U+252x	┠	┡	┢	┣	┤	┥	┦	┧	┨	┩	┪	┫	┬	┭	┮	┯
U+253x	┰	┱	┲	┳	┴	┵	┶	┷	┸	┹	┺	┻	┼	┽	┾	┿
U+254x	╀	╁	╂	╃	╄	╅	╆	╇	╈	╉	╊	╋	╌	╍	╎	╏
U+255x	═	║	╒	╓	╔	╕	╖	╗	╘	╙	╚	╛	╜	╝	╞	╟
U+256x	╠	╡	╢	╣	╤	╥	╦	╧	╨	╩	╪	╫	╬	╭	╮	╯
U+257x	╰	╱	╲	╳	╴	╵	╶	╷	╸	╹	╺	╻	╼	╽	╾	╿
*/
namespace dw
{
    //
    const std::u32string style1 = U" ┌┐└┘│─";
    const std::u32string style2 = U" ╔╗╚╝║═";
    const std::u32string style3 = U" ┏┓┗┛┃━";
    const std::u32string style4 = U" ╭╮╰╯│─";
    const std::u32string cur_style = style4;

    

    void window(int top, int left, int width, int height, std::string title)
    {

        for (int row = 0; row < height; row++)
        {
            tc::move_to(top + row, ut::block2col(left));
            for (int column = 0; column < width; column++)
            {
                if (row == 0) // 第一行
                {
                    if (column == 0) // 第一列
                    {
                        std::cout << ut::utf32_to_utf8({cur_style[0],cur_style[1]});
                    }
                    else if (column == width - 1) // 最后一列
                    {
                        std::cout << ut::utf32_to_utf8({cur_style[2],cur_style[0]});
                    }
                    else // 中间
                    {
                        std::cout << ut::utf32_to_utf8({cur_style[6],cur_style[6]});
                    }
                }
                else if (row == height - 1) // 最后一行
                {
                    if (column == 0) // 第一列
                    {
                        std::cout << ut::utf32_to_utf8({cur_style[0],cur_style[3]});
                    }
                    else if (column == width - 1) // 最后一列
                    {
                        std::cout << ut::utf32_to_utf8({cur_style[4],cur_style[0]});
                    }
                    else // 中间
                    {
                        std::cout << ut::utf32_to_utf8({cur_style[6],cur_style[6]});
                    }
                }
                else // 中间
                {
                    if (column == 0) // 第一列
                    {
                        std::cout << ut::utf32_to_utf8({cur_style[0],cur_style[5]});
                    }
                    else if (column == width - 1) // 最后一列
                    {
                        std::cout << ut::utf32_to_utf8({cur_style[5],cur_style[0]});
                    }
                    else // 中间
                    {
                        std::cout << ut::utf32_to_utf8({cur_style[0],cur_style[0]});
                    }
                }
            }
        }
        // title
        tc::move_to(top, ut::block2col(left) + (width * 2 - title.length()) / 2);
        std::cout << title;
    }

} // namespace dw
