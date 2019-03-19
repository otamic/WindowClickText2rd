//
// Created by 冯彦澄 on 2019-02-04.
//

#ifndef WINDOWCLICKTEXT2RD_PAINTER_WC_H
#define WINDOWCLICKTEXT2RD_PAINTER_WC_H

/************************************
 * paint on the Paper (without the OpenGL framework)
 ************************************/
#include "paper_wc.h"
#include "button_wc.h"

/************************************
 * Elemental function
 ************************************/
void setPixel (const Paper & pap, int x, int y, Color_wc col);

/************************************
 * Expand function
 ************************************/
//void lineDDA (Paper & pap, int xs, int ys, int xe, int ye);
void lineBres (Paper & pap, const MFButton & but, Color_wc col);
void roudBres (Paper & pap, const MFButton & but, Color_wc col);
void rect (Paper & pap, const MFButton & but, Color_wc col);

#endif //WINDOWCLICKTEXT2RD_PAINTER_WC_H
