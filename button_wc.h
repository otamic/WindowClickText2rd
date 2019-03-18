//
// Created by 冯彦澄 on 2019-02-03.
//

#ifndef WINDOWCLICKTEXT2RD_BUTTON_WC_H
#define WINDOWCLICKTEXT2RD_BUTTON_WC_H

/*
 * 按钮组件
 */

#include "evalElem_wc.h"

const int BUTTONWIDTH = 50, BUTTONHEIGHT = 20;
const int PANELWIDTH = 100, PANELHEIGHT = 700;
const char buttonS[10][10] = { { 'l', 'i', 'n', 'e', '\0' },
                               { 'r', 'e', 'c', 't', '\0' },
                               { 'r', 'o', 'n', 'd', '\0' }};
const int MAX_BUTTON_NUM = 100;

struct Button {

    Tag tag;
    int buttonWidth, buttonHeight;
    int poX, poY;                                               // The top left corner relative to the window

    int xs, ys;                                                 // 携带两组（start，end）坐标，用于绘图
    int xe, ye;

};

struct ButtonEnvr {                                             // 按钮集

    Button buttons[MAX_BUTTON_NUM];
    int buttonNum;

};

struct Panel {

    int panelWidth, panelHeight;
    int poX, poY;

};

void ini_button(Button & but, Tag tag, int poX, int poY);       // 在指定位置创建一个按钮
void ini_buttonEnvr(ButtonEnvr & butEnvr);
Tag checkButton(const ButtonEnvr & butEnvr, int poX, int poY);  // 在poX和poY上是何种按钮
void addButton(ButtonEnvr & butEnvr, Button & but);
void changeButtonPos(Button &but, const Pos pos, bool tag);     // 改变坐标

void ini_panel (Panel & pal, int poX, int poY);
PanelTag checkPanel (const Panel & pal, int poX, int poY);
Color_wc changeColor (PanelTag pTag);






#endif //WINDOWCLICKTEXT2RD_BUTTON_WC_H
