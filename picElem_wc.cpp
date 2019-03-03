//
// Created by 冯彦澄 on 2019-02-16.
//

#include "picElem_wc.h"
#include "tool_wc.h"

void lineBresenham (const Paper & pap, const Button & but, void setPixel (const Paper &, int, int, Color_wc), Color_wc col) {

    int xs = but.xs, ys = but.ys, xe = but.xe, ye = but.ye;

    int dx = wc_abs(xe - xs), dy = wc_abs(ye - ys);

    bool tag = true;

    if (dx < dy) {
        wc_swap(dx, dy);
        wc_swap(xs, ys);
        wc_swap(xe, ye);
        tag = false;
    }

    int p = 2 * dy - dx;
    int twoDy = 2 * dy, twoDyMinusDx = 2 * (dy - dx);
    int x, y, add = 1;

    if (xs > xe) {
        x = xe;
        y = ye;
        xe = xs;
        if (y > ys)
            add = -1;
    }
    else {
        x = xs;
        y = ys;
        if (y > ye)
            add = -1;
    }
    if (tag)
        setPixel(pap, x, y, col);
    else
        setPixel(pap, y, x, col);

    while(x < xe) {
        x++;
        if (p < 0)
            p += twoDy;
        else {
            y += add;
            p += twoDyMinusDx;
        }
        if (tag)
            setPixel(pap, x, y, col);
        else
            setPixel(pap, y, x, col);
    }
}

void rectanglePic (const Paper & pap, const Button & but, void setPixel (const Paper &, int, int, Color_wc), Color_wc col) {

    int x1 = but.xs < but.xe ? but.xs : but.xe, x2 = but.xs + but.xe - x1;
    int y1 = but.ys > but.ye ? but.ys : but.ye, y2 = but.ys + but.ye - y1;

    for (int i = x1; i <= x2; i++) {
        setPixel (pap, i, y1, col);
        setPixel (pap, i, y2, col);
    }
    for (int i = y2 + 1; i < y1; i++) {
        setPixel (pap, x1, i, col);
        setPixel (pap, x2, i, col);
    }

}

static void circlePlotPoints (const Paper & pap, int xc, int yc, int x, int y,  void setPixel (const Paper &, int, int, Color_wc), Color_wc col) {

    setPixel (pap, xc + x, yc + y, col);
    setPixel (pap, xc - x, yc + y, col);
    setPixel (pap, xc + x, yc - y, col);
    setPixel (pap, xc - x, yc - y, col);
    setPixel (pap, xc + y, yc + x, col);
    setPixel (pap, xc - y, yc + x, col);
    setPixel (pap, xc + y, yc - x, col);
    setPixel (pap, xc - y, yc - x, col);

}

void circleMidpoint (const Paper & pap, const Button & but, void setPixel (const Paper &, int, int, Color_wc), Color_wc col) {

    int radius = (int) wc_sqrtf( (but.xs - but.xe) * (but.xs - but.xe) + (but.ys - but.ye) * (but.ys - but.ye) );
    int p = 1 - radius;

    int x = 0, y = radius;
    circlePlotPoints(pap, but.xs, but.ys, x, y, setPixel, col);
    while (x < y) {
        x++;
        if (p < 0)
            p += 2 * x + 1;
        else {
            y--;
            p += 2 * (x - y) + 1;
        }
        circlePlotPoints(pap, but.xs, but.ys, x, y, setPixel, col);
    }

}

void lineBresenham_2 (const Paper & pap, const Button & but, void setPixel (const Paper &, int, int, int, bool, Color_wc), Color_wc col, int width) {

    int xs = but.xs, ys = but.ys, xe = but.xe, ye = but.ye;

    int dx = wc_abs(xe - xs), dy = wc_abs(ye - ys);

    bool tag = true;
    bool column = dx < dy;

    if (dx < dy) {
        wc_swap(dx, dy);
        wc_swap(xs, ys);
        wc_swap(xe, ye);
        tag = false;
    }

    int p = 2 * dy - dx;
    int twoDy = 2 * dy, twoDyMinusDx = 2 * (dy - dx);
    int x, y, add = 1;

    if (xs > xe) {
        x = xe;
        y = ye;
        xe = xs;
        if (y > ys)
            add = -1;
    }
    else {
        x = xs;
        y = ys;
        if (y > ye)
            add = -1;
    }
    if (tag)
        setPixel(pap, x, y, width, column, col);
    else
        setPixel(pap, y, x, width, column, col);

    while(x < xe) {
        x++;
        if (p < 0)
            p += twoDy;
        else {
            y += add;
            p += twoDyMinusDx;
        }
        if (tag)
            setPixel(pap, x, y, width, column, col);
        else
            setPixel(pap, y, x, width, column, col);
    }

}