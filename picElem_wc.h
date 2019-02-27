//
// Created by 冯彦澄 on 2019-02-16.
//

#ifndef WINDOWCLICKTEXT2RD_PICELEM_WC_H
#define WINDOWCLICKTEXT2RD_PICELEM_WC_H

/*
 * 通用的图元算法
 */

#include "paper_wc.h"
#include "button_wc.h"

void lineBresenham (const Paper & pap, const Button & but, void setPixel (const Paper &, int, int));
void rectanglePic (const Paper & pap, const Button & but, void setPixel (const Paper &, int, int));
static void circlePlotPoints (const Paper & pap, int xc, int yc, int x, int y, void (const Paper &, int x, int y));
void circleMidpoint (const Paper & pap, const Button & but, void setPixel (const Paper &, int , int ));

#endif //WINDOWCLICKTEXT2RD_PICELEM_WC_H
