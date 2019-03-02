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
const Color_wc REC_WC   = { 127, 0  , 0   };
const Color_wc GREEN_WC = { 0  , 127, 0   };
const Color_wc BLUT_WC  = { 0  , 0  , 127 };

enum Tag { line_wc = 0, rectangle_wc, round_wc, painting_wc, none_wc };

#endif //WINDOWCLICKTEXT2RD_EVALELEM_WC_H
