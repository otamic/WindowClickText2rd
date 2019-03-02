//
// Created by 冯彦澄 on 2019-02-03.
//

#include "button_wc.h"

void ini_button(Button & but, Tag tag, int poX, int poY) {

    but.tag = tag;
    but.buttonHeight = BUTTONHEIGHT;
    but.buttonWidth = BUTTONWIDTH;
    but.poX = poX;
    but.poY = poY;

}

void ini_buttonEnvr(ButtonEnvr & butEnvr) {
    butEnvr.buttonNum = 0;
}

Tag checkButton(const ButtonEnvr & butEnvr, int poX, int poY) {

    for (int i = 0; i < butEnvr.buttonNum; i++)
        if (poX > butEnvr.buttons[i].poX && poX < butEnvr.buttons[i].poX + butEnvr.buttons[i].buttonWidth &&
            poY < butEnvr.buttons[i].poY && poY > butEnvr.buttons[i].poY - butEnvr.buttons[i].buttonHeight)
            return butEnvr.buttons[i].tag;

    return none_wc;

}

void addButton(ButtonEnvr & butEnvr, Button & but) {
    butEnvr.buttons[butEnvr.buttonNum++] = but;
}

void changeButtonPos(Button &but, const Pos pos, bool tag) {

    if (tag) {
        but.xs = pos.x;
        but.ys = pos.y;
    }
    else {
        but.xe = pos.x;
        but.ye = pos.y;
    }

}

void ini_button (Panel & pal, int poX, int poY) {

    pal.panelHeight = PANELHEIGHT;
    pal.panelWidth = PANELWIDTH;
    pal.poX = poX;
    pal.poY = poY;

}

PanelTag checkPanel (const Panel & pal, int poX, int poY) {

    int x = poX - pal.poX, y = poY - pal.poY + pal.panelHeight;

    if (poX > 5 && poX < 35 && poY > 5 && poY < 35)
        return blank_wc;
    else if (poX > 5 && poX < 35 && poY > 35 && poY < 65)
        return green_wc;
    else if (poX > 35 && poX < 65 && poY > 5 && poY < 35)
        return white_wc;
    else if (poX > 35 && poX < 65 && poY > 35 && poY < 65)
        return blue_wc;
    else if (poX > 65 && poX < 95 && poY > 5 && poY < 35)
        return red_wc;
    else if (poX > 5 && poX < 55 && poY > 570 && poY < 590)         // warning! Can't use in the other place!
        return back_wc;

}