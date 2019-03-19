//
// Created by 冯彦澄 on 2019-02-03.
//

#ifndef WINDOWCLICKTEXT2RD_PAINT_WC_H
#define WINDOWCLICKTEXT2RD_PAINT_WC_H

/************************************
 * OpenGL framework needed
 * be called in the display function
 ************************************/

#include "paper_wc.h"
#include "button_wc.h"
/************************************
 * Elemental function
 ************************************/
void drawString(const char * s, int poX, int poY);                          // draw a string at a specific place
void drawString(const char * s);
void drawNum(int num, int poX, int poY);                                    // draw a number at a specific place
void drawNum(int num);

/************************************
 * Expand function
 ************************************/
void setPoint(const Paper & pap, int x, int y, Color_wc col);               // draw a pixel in the paper
static void drawButton(const Button & but);
static void drawMFButton (const MFButton & but);
void drawPaper(const Paper & pap, bool hasLines);                           // draw the Paper with or without lines
void drawButtons(const ButtonEnvr & butEnvr);
void drawPanel (const Panel pal);
void drawMFButtons (const MFButtonSet & buttonSet);

/************************************
 * Specific function
 ************************************/
void text_draw_info(Tag tag);                                               // draw the tips for function
void text_draw_info (PanelTag tag);
void text_draw_keyInfo (bool isDraw);                                       // draw the tips for button
void text_draw_other();                                                     // draw the frame
//void text_lineDDA(const Paper & pap, const Button & but);

void text_lineBres (Paper & pap, const MFButton & but, Color_wc col);       // buffered line
void text_roudBres (Paper & pap, const MFButton & but, Color_wc col);       // buffered round
void text_rect (Paper & pap, const MFButton & but, Color_wc col);

#endif //WINDOWCLICKTEXT2RD_PAINT_WC_H
