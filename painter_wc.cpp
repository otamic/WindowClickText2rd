//
// Created by 冯彦澄 on 2019-02-04.
//
#include "painter_wc.h"
#include "picElem_wc.h"

#include <cstring>

void setPixel (const Paper & pap, int x, int y) {
    if (y >= 0 && y < pap.paperHeight && x >= 0 && x < pap.paperWidth)
        pap.paper[y][x] = 1;
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

void lineBres (Paper & pap, const Button & but) {
    lineBresenham(pap, but, setPixel);
}

void roudBres (Paper & pap, const Button & but) {
    circleMidpoint(pap, but, setPixel);
}

void rect (Paper & pap, const Button & but) {
    rectanglePic (pap, but, setPixel);
}