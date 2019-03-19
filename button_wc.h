//
// Created by 冯彦澄 on 2019-02-03.
//

#ifndef WINDOWCLICKTEXT2RD_BUTTON_WC_H
#define WINDOWCLICKTEXT2RD_BUTTON_WC_H

/************************************
 * Button
 * Panel
 ************************************/

#include "evalElem_wc.h"

const int BUTTONWIDTH = 50, BUTTONHEIGHT = 20;
const int PANELWIDTH = 100, PANELHEIGHT = 700;
const char buttonS[10][10] = { { 'l', 'i', 'n', 'e', '\0' },
                               { 'r', 'e', 'c', 't', '\0' },
                               { 'r', 'o', 'n', 'd', '\0' }};
const int MAX_BUTTON_NUM = 100;

/************************************
 * Elemental type
 ************************************/
struct Button {

    int buttonWidth, buttonHeight;
    int poX, poY;                                               // The top left corner relative to the window

};

struct Panel {

    int panelWidth, panelHeight;
    int poX, poY;

};

struct ButtonEnvr {                                             // Button set

    Button buttons[MAX_BUTTON_NUM];
    int buttonNum;

};

/************************************
 * Expand type
 ************************************/
struct MFButton {

    Button buttonAttribute;

    Tag tag;
    int xs, ys;
    int xe, ye;
};

struct MFButtonSet {

    MFButton mfButtons[MAX_BUTTON_NUM];
    int buttonNum;

};


/*************************************
 * Elemental function
 *************************************/

/*
 * Button function
 */
void ini_button (Button & but, int poX, int poY);

/*
 * Button Set function
 */
void ini_buttonEnvr(ButtonEnvr & butEnvr);
void addButton(ButtonEnvr & butEnvr, Button & but);
//(Tag) checkButton(const ButtonEnvr & butEnvr, int poX, int poY);

/*
 * Panel function
 */
void ini_panel (Panel & pal, int poX, int poY);
PanelTag checkPanel (const Panel & pal, int poX, int poY);          // need for moving
Color_wc changeColor (PanelTag pTag);                               // need for moving

/************************************
 * Expand function
 ************************************/

/*
 * MFButton function
 */
void ini_MFButton(MFButton & but, Tag tag, int poX, int poY);
void changeMFButtonPos(MFButton & but, const Pos pos, bool tag);

/*
 * MFButton set function
 */
void ini_MFButtonSet (MFButtonSet & butSet);
void addMFButton (MFButtonSet & butSet, MFButton & but);
Tag checkMFButton (const MFButtonSet & butSet, int poX, int poY);   // need for moving






#endif //WINDOWCLICKTEXT2RD_BUTTON_WC_H
