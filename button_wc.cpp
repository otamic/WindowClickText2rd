//
// Created by 冯彦澄 on 2019-02-03.
//

#include "button_wc.h"

void ini_button (Button & but, int poX, int poY) {

    but.poX = poX;
    but.poY = poY;
    but.buttonHeight = BUTTONHEIGHT;
    but.buttonWidth = BUTTONWIDTH;

}

void ini_buttonEnvr(ButtonEnvr & butEnvr) {
    butEnvr.buttonNum = 0;
}

void addButton(ButtonEnvr & butEnvr, Button & but) {
    butEnvr.buttons[butEnvr.buttonNum++] = but;
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
    else if (x > 35 && x < 65 && y > 5 && y < 35)
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

void ini_MFButton(MFButton & but, Tag tag, int poX, int poY) {

    but.tag = tag;
    ini_button(but.buttonAttribute, poX, poY);

}

void ini_MFButtonSet (MFButtonSet & butSet) {

    butSet.buttonNum = 0;

}

void addMFButton (MFButtonSet & butSet, MFButton & but) {

    butSet.mfButtons[butSet.buttonNum++] = but;

}

Tag checkMFButton (const MFButtonSet & butSet, int poX, int poY) {

    for (int i = 0; i < butSet.buttonNum; i++)
        if (poX > butSet.mfButtons[i].buttonAttribute.poX && poX < butSet.mfButtons[i].buttonAttribute.poX + butSet.mfButtons[i].buttonAttribute.buttonWidth &&
            poY < butSet.mfButtons[i].buttonAttribute.poY && poY > butSet.mfButtons[i].buttonAttribute.poY - butSet.mfButtons[i].buttonAttribute.buttonHeight)
            return butSet.mfButtons[i].tag;

    return none_wc;

}

void changeMFButtonPos(MFButton & but, const Pos pos, bool tag) {

    if (tag) {
        but.xs = pos.x;
        but.ys = pos.y;
    }
    else {
        but.xe = pos.x;
        but.ye = pos.y;
    }

}
