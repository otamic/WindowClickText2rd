//
// Created by 冯彦澄 on 2019-02-03.
//

#ifndef WINDOWCLICKTEXT2RD_PAINT_WC_H
#define WINDOWCLICKTEXT2RD_PAINT_WC_H

/*
 * OpenGL中需要display的内容
 */

#include "paper_wc.h"
#include "button_wc.h"

void setPoint(const Paper & pap, int x, int y);                 // 绘制paper中的一个像素
void drawPaper(const Paper & pap, bool hasLines);               // 绘制paper（是否加线条）
void drawString(const char * s, int poX, int poY);              // 绘制（在指定位置）字符
void drawString(const char * s);
void drawNum(int num, int poX, int poY);                        // 绘制（在指定位置）数字
void drawNum(int num);
static void drawButton(const Button & but);
void drawButtons(const ButtonEnvr & butEnvr);                   // 绘制所有按钮

void text_draw_info(Tag tag);                                   // 绘制功能提示
void text_draw_keyInfo (bool isDraw);                           // 绘制按键提示
void text_draw_other();                                         // 绘制边框
//void text_lineDDA(const Paper & pap, const Button & but);
void text_lineBres (Paper & pap, const Button & but);           // 缓存的画线
void text_roudBres (Paper & pap, const Button & but);           // （缓存的）画圆
void text_rect (Paper & pap, const Button & but);               // （缓存的）画矩形

#endif //WINDOWCLICKTEXT2RD_PAINT_WC_H
