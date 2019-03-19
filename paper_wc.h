//
// Created by 冯彦澄 on 2019-02-03.
//

#ifndef WINDOWCLICKTEXT2RD_PAPER_WC_H
#define WINDOWCLICKTEXT2RD_PAPER_WC_H

/*
 * 纸组件
 */

#include "evalElem_wc.h"

struct Paper {
    int squreSize;                                              // 纸上一个像素宽
    int paperWidth, paperHeight;
    Color_wc ** paper;                                          // 储存画面的二维矩阵
    int abX, abY;                                               // The top left corner relative to the window (is descried as Cartesian coordinates)
};

void setPaperSize (Paper & pap, int newSize);                   // 设置纸在窗口上的大小
void setPaperFront (Paper & pap, int newWidth, int newHeight);  // 设置纸的分辨率
void locatePaper(Paper & pap, int poX, int poY);                // 设置纸在窗口上的位置
void loadIn(Paper & pap);                                       // 导入存在Pic.txt的矩阵
void loadOut(Paper & pap);                                      // 导出矩阵
void ini_paper(Paper & pap);
void destroy_paper (Paper & pap);
Pos getPoint(Paper & pap, int poX, int poY);        // 窗口的位置对应纸的像素

void ini_paper (Paper & pap, int poX, int poY);                 // Create a new Paper in a window

#endif //WINDOWCLICKTEXT2RD_PAPER_WC_H
