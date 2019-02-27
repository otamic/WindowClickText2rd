//
// Created by 冯彦澄 on 2019-02-15.
//

#include "tool_wc.h"

int wc_round (const float a) { return int (a + 0.5); }

int wc_abs (int a) { return a > 0 ? a : -a; }

void wc_swap (int & a, int & b) {

    int c = a;
    a = b;
    b = c;

}

float wc_sqrtf (float x) {

    float xhalf = 0.5f * x;
    int i = *(int *) &x;
    i = 0x5f375a86 - (i >> 1);
    x = *(float *) &i;

    x = x * (1.5f - xhalf * x * x);
    x = x * (1.5f - xhalf * x * x);
    x = x * (1.5f - xhalf * x * x);

    return 1 / x;

}