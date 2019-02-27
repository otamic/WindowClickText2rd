//
// Created by 冯彦澄 on 2019-02-04.
//

#ifndef WINDOWCLICKTEXT2RD_PAINTER_WC_H
#define WINDOWCLICKTEXT2RD_PAINTER_WC_H

/*
 * 在paper上的（与OpenGL无关的）绘制
 */

#include "paper_wc.h"
#include "button_wc.h"

void setPixel (const Paper & pap, int x, int y);
//void lineDDA (Paper & pap, int xs, int ys, int xe, int ye);
void lineBres (Paper & pap, const Button & but);
void roudBres (Paper & pap, const Button & but);
void rect (Paper & pap, const Button & but);

#endif //WINDOWCLICKTEXT2RD_PAINTER_WC_H
