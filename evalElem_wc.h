//
// Created by 冯彦澄 on 2019-02-16.
//

#ifndef WINDOWCLICKTEXT2RD_EVALELEM_WC_H
#define WINDOWCLICKTEXT2RD_EVALELEM_WC_H

/*
 * 一些全局用的自定义参数、变量
 */

#include <OpenGL/gltypes.h>

struct Pos {
    int x, y;
};

struct Color_wc {

    GLbyte red;
    GLbyte green;
    GLbyte blue;

};

const Color_wc BLANK_WC = { 0  , 0  , 0   };
const Color_wc WHITE_WC = { 127, 127, 127 };
const Color_wc RED_WC   = { 127, 0  , 0   };
const Color_wc GREEN_WC = { 0  , 127, 0   };
const Color_wc BLUE_WC  = { 0  , 0  , 127 };
const Color_wc GREY_WC  = { 100, 100, 100 };

enum Tag { line_wc = 0, rectangle_wc, round_wc, painting_wc, none_wc };
enum PanelTag { blank_wc = 0, white_wc, red_wc, green_wc, blue_wc, back_wc, nothing_wc };

#endif //WINDOWCLICKTEXT2RD_EVALELEM_WC_H
