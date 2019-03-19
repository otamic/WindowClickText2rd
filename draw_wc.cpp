//
// Created by 冯彦澄 on 2019-02-03.
//

#include <GLUT/glut.h>
#include <cstring>
#include "draw_wc.h"
#include "picElem_wc.h"

void setPoint(const Paper & pap, int x, int y, Color_wc col) {

    glColor3b (col.red, col.green, col.blue);
    if (y >= 0 && y <= pap.paperHeight && x >= 0 && x <= pap.paperWidth)
        glRecti(pap.abX + x * pap.squreSize, pap.abY - (pap.paperHeight - y) * pap.squreSize, pap.abX + (x + 1) * pap.squreSize, pap.abY - (pap.paperHeight - y - 1) * pap.squreSize);

}

void drawPaper(const Paper & pap, bool hasLines) {

    for (int i = 0; i < pap.paperHeight; i++)
        for (int j = 0; j < pap.paperWidth; j++)
            setPoint(pap, j, i, pap.paper[i][j]);

    if (hasLines) {
        glColor3b (100, 100, 100);
        glLineWidth(0.5);
        glBegin(GL_LINES);
        for (int i = 0; i <= pap.paperWidth; i++) {
            glVertex2f(pap.abX + i * pap.squreSize, pap.abY);
            glVertex2f(pap.abX + i * pap.squreSize, pap.abY - pap.paperHeight * pap.squreSize);
        }
        for (int i = 0; i <= pap.paperHeight; i++) {
            glVertex2f(pap.abX, pap.abY - i * pap.squreSize);
            glVertex2f(pap.abX + pap.paperWidth * pap.squreSize, pap.abY - i * pap.squreSize);
        }
        glEnd();
    }

}



void drawString(const char * s, int poX, int poY) {

    glColor3b (127, 127, 127);
    glRasterPos2i(poX, poY);
    int len = strlen(s);
    for (int i = 0; i < len; i++)
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, s[i]);

}

void drawString(const char * s) {

    glColor3b (127, 127, 127);
    int len = strlen(s);
    for (int i = 0; i < len; i++)
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, s[i]);

}

void drawNum(int num, int poX, int poY) {

    glColor3b (127, 127, 127);
    glRasterPos2i(poX, poY);
    int snum[10] = {0}, len = 0;
    if (num == 0)
        len++;
    while(num) {
        snum[len++] = num % 10;
        num /= 10;
    }
    for (int i = len; i >= 0; i--)
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, '0'+snum[i]);

}

void drawNum(int num) {

    glColor3b (127, 127, 127);
    int snum[10] = {0}, len = 0;
    if (num == 0)
        len++;
    while(num) {
        snum[len++] = num % 10;
        num /= 10;
    }
    for (int i = len; i >= 0; i--)
        glutBitmapCharacter(GLUT_BITMAP_8_BY_13, '0'+snum[i]);

}

static void drawButton(const Button & but) {

    glColor3b (127, 127, 127);
    glBegin(GL_LINE_LOOP);
    glVertex2i(but.poX, but.poY);
    glVertex2i(but.poX, but.poY - but.buttonHeight);
    glVertex2i(but.poX + but.buttonWidth, but.poY - but.buttonHeight);
    glVertex2i(but.poX + but.buttonWidth, but.poY);
    glEnd();

}

static void drawMFButton (const MFButton & but) {

    drawButton(but.buttonAttribute);
    drawString(buttonS[but.tag], but.buttonAttribute.poX + 2, but.buttonAttribute.poY - but.buttonAttribute.buttonHeight / 2);

}

void drawButtons(const ButtonEnvr & butEnvr) {

    for (int i = 0; i < butEnvr.buttonNum; i++)
        drawButton(butEnvr.buttons[i]);

}

void drawMFButtons (const MFButtonSet & buttonSet) {

    for (int i = 0; i < buttonSet.buttonNum; i++)
        drawMFButton(buttonSet.mfButtons[i]);

}

void drawPanel (const Panel pal) {

    glColor3b (BLANK_WC.red, BLANK_WC.green, BLANK_WC.blue);
    glRecti (pal.poX + 5, pal.poY - pal.panelHeight + 695, pal.poX + 35, pal.poY - pal.panelHeight + 665);
    glColor3b (WHITE_WC.red, WHITE_WC.green, WHITE_WC.blue);
    glRecti (pal.poX + 35, pal.poY - pal.panelHeight + 695, pal.poX + 65, pal.poY - pal.panelHeight + 665);
    glColor3b (RED_WC.red, RED_WC.green, RED_WC.blue);
    glRecti (pal.poX + 65, pal.poY - pal.panelHeight + 695, pal.poX + 95, pal.poY - pal.panelHeight + 665);
    glColor3b (GREEN_WC.red, GREEN_WC.green, GREEN_WC.blue);
    glRecti (pal.poX + 5, pal.poY - pal.panelHeight + 665, pal.poX + 35, pal.poY - pal.panelHeight + 635);
    glColor3b (BLUE_WC.red, BLUE_WC.green, BLUE_WC.blue);
    glRecti (pal.poX + 35, pal.poY - pal.panelHeight + 665, pal.poX + 65, pal.poY - pal.panelHeight + 635);

    glColor3b (WHITE_WC.red, WHITE_WC.green, WHITE_WC.blue);
    glBegin (GL_LINE_LOOP);
    glVertex2i (5, 110);
    glVertex2i (55, 110);
    glVertex2i (55, 130);
    glVertex2i (5, 130);
    glEnd ();
    drawString ("back", 10, 115);

}

void text_draw_info(Tag tag) {

    glColor3b (127, 127, 127);
    glRasterPos2i(10, 90);
    switch(tag) {
        case line_wc:
            drawString("draw a line. ");
            break;
        case rectangle_wc:
            drawString("draw a rectangle. ");
            break;
        case round_wc:
            drawString("draw a round. ");
            break;
        default:
            drawString("draw nothing. ");
            break;
    }

}

void text_draw_info (PanelTag tag) {

    glColor3b (127, 127, 127);
    glRasterPos2i(10, 75);
    switch(tag) {
        case blank_wc:
            drawString("Blank");
            break;
        case white_wc:
            drawString("White");
            break;
        case red_wc:
            drawString("Red");
            break;
        case green_wc:
            drawString ("Green");
            break;
        case blue_wc:
            drawString ("Blue");
            break;
        default:
            drawString("draw nothing");
            break;
    }
}

void text_draw_keyInfo (bool isInput) {

    glColor3b (127, 127, 127);
    glRasterPos2i (10, 60);
    drawString ("Are you sure to ");
    if (isInput)
        drawString ("Input");
    else
        drawString ("Output");
    drawString ("? Y / N");

}

void text_draw_other() {

    glColor3b (127, 127, 127);
    glBegin(GL_LINES);
    glVertex2i(100,700);
    glVertex2i(100,100);
    glVertex2i(0,100);
    glVertex2i(1000,100);
    glEnd();

}

/*
//  只能画一四象限
void text_lineDDA(const Paper & pap, const Button & but) {

    glColor3f(0.0f, 0.0f, 0.0f);

    int dx = but.xe - but.xs, dy = but.ye - but.ys, steps;
    float xIncrement, yIncrement, x = but.xs, y = but.ys;

    if (dx > dy)
        steps = dx;
    else
        steps = dy;

    xIncrement = (float) dx / (float) steps;
    yIncrement = (float) dy / (float) steps;

//  setPoint(pap, int (y + 0.5), int (x + 0.5));
    setPoint(pap, int (x), int (y));
//  setPixel(pap, roud(x), roud(y));
    for (int k = 0; k < steps; k++) {
        x += xIncrement;
        y += yIncrement;
//      setPoint(pap, int (y + 0.5), int (x + 0.5));
        setPoint(pap, int (y), int (x));
//      setPixel(pap, roud(x), roud(y));
    }

}
 */

void text_lineBres (Paper & pap, const MFButton & but, Color_wc col) {
    lineBresenham(pap, but, setPoint, col);
}

void text_roudBres (Paper & pap, const MFButton & but, Color_wc col) {
    circleMidpoint(pap, but, setPoint, col);
}

void text_rect (Paper & pap, const MFButton & but, Color_wc col) {
    rectanglePic(pap, but, setPoint, col);
}

