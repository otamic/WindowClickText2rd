//
// Created by 冯彦澄 on 2019-02-16.
//

#ifndef WINDOWCLICKTEXT2RD_PICELEM_WC_H
#define WINDOWCLICKTEXT2RD_PICELEM_WC_H

/************************************
 * general algorithm for the graphic element
 * line
 * rectangle
 * round
 ************************************/

#include "paper_wc.h"
#include "button_wc.h"

/************************************
 * Expand function
 ************************************/
static void circlePlotPoints (const Paper & pap, int xc, int yc, int x, int y, void (const Paper &, int x, int y, Color_wc), Color_wc col);
void lineBresenham (const Paper & pap, const MFButton & but, void setPixel (const Paper &, int, int, Color_wc), Color_wc col);
void rectanglePic (const Paper & pap, const MFButton & but, void setPixel (const Paper &, int, int, Color_wc), Color_wc col);
void circleMidpoint (const Paper & pap, const MFButton & but, void setPixel (const Paper &, int, int, Color_wc), Color_wc col);


#endif //WINDOWCLICKTEXT2RD_PICELEM_WC_H
