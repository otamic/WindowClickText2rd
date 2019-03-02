//
// Created by 冯彦澄 on 2019-02-04.
//
#include "painter_wc.h"
#include "picElem_wc.h"

#include <cstring>

void setPixel (const Paper & pap, int x, int y, Color_wc col) {
    if (y >= 0 && y < pap.paperHeight && x >= 0 && x < pap.paperWidth) {
        pap.paper[y][x].red = col.red;
        pap.paper[y][x].green = col.green;
        pap.paper[y][x].blue = col.blue;
    }
}

/*
void lineDDA (Paper & pap, int xs, int ys, int xe, int ye) {

    int dx = xe - xs, dy = ye - ys, steps;
    float xIncrement, yIncrement, x = xs, y = ys;

    if (dx > dy)
        steps = dx;
    else
        steps = dy;

    xIncrement = (float) dx / (float) steps;
    yIncrement = (float) dy / (float) steps;

    setPixel(pap, wc_round(x), wc_round(y));
    for (int k = 0; k < steps; k++) {
        x += xIncrement;
        y += yIncrement;
        setPixel(pap, wc_round(x), wc_round(y));
    }

}
 */

void lineBres (Paper & pap, const Button & but, Color_wc col) {
    lineBresenham(pap, but, setPixel, col);
}

void roudBres (Paper & pap, const Button & but, Color_wc col) {
    circleMidpoint(pap, but, setPixel, col);
}

void rect (Paper & pap, const Button & but, Color_wc col) {
    rectanglePic (pap, but, setPixel, col);
}