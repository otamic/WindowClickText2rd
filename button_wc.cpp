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

void ini_panel (Panel & pal, int poX, int poY) {

    pal.panelHeight = PANELHEIGHT;
    pal.panelWidth = PANELWIDTH;
    pal.poX = poX;
    pal.poY = poY;

}

PanelTag checkPanel (const Panel & pal, int poX, int poY) {

    int x = poX - pal.poX, y = pal.poY - poY;

    if (x > 5 && x < 35 && y > 5 && y < 35)
        return blank_wc;
    else if (x > 5 && x < 35 && y > 35 && y < 65)
        return green_wc;
    else if (x > 35 && y < 65 && y > 5 && y < 35)
        return white_wc;
    else if (x > 35 && x < 65 && y > 35 && y < 65)
        return blue_wc;
    else if (x > 65 && x < 95 && y > 5 && y < 35)
        return red_wc;
    else if (x > 5 && x < 55 && y > 570 && y < 590)
        return back_wc;
    else
        return nothing_wc;

}

Color_wc changeColor (PanelTag pTag) {

    switch (pTag) {
        case blank_wc:
            return BLANK_WC;
        case white_wc:
            return WHITE_WC;
        case red_wc:
            return RED_WC;
        case green_wc:
            return GREEN_WC;
        case blue_wc:
            return BLUE_WC;
        default:
            break;
    }
}