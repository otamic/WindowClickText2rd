//
// Created by 冯彦澄 on 2019-02-03.
//

#include <cstdlib>
#include <cstdio>
#include <cstring>
#include "paper_wc.h"

void ini_paper(Paper & pap) {

    pap.paper = (Color_wc **) malloc(pap.paperHeight * sizeof(Color_wc *));
    for (int i = 0; i < pap.paperHeight; i++)
        pap.paper[i] = (Color_wc *) malloc(pap.paperWidth * sizeof(Color_wc));


    for (int i = 0; i < pap.paperHeight; i++)
        for (int j = 0; j < pap.paperWidth; j++)
            pap.paper[i][j].red = pap.paper[i][j].green = pap.paper[i][j].blue = 127;


}

void destroy_paper (Paper & pap) {

    for (int i = 0; i < pap.paperHeight; i++)
        free (pap.paper[i]);
    free (pap.paper);

}

void setPaperSize(Paper & pap, int newSize) {
    pap.squreSize = newSize;
}

void setPaperFront(Paper & pap, int newWidth, int newHeight) {
    pap.paperHeight = newHeight;
    pap.paperWidth = newWidth;
}

void locatePaper(Paper & pap, int poX, int poY) {
    pap.abX = poX;
    pap.abY = poY;
}

void loadIn(Paper & pap) {

    destroy_paper(pap);

    FILE * fp;
    fp = fopen("Pic.txt", "r");
    fscanf(fp, "%d %d %d\n", &pap.paperWidth, &pap.paperHeight, &pap.squreSize);

    ini_paper(pap);

    for (int i = 0; i < pap.paperHeight; i++)
        for (int j = 0; j < pap.paperWidth; j++)
            for (int k = 0; k < 3; k++)
                fscanf(fp, "%hhu %hhu %hhu", &pap.paper[i][j].red, &pap.paper[i][j].green, &pap.paper[i][j].blue);
    fclose(fp);

}

void loadOut(Paper & pap) {

    FILE * fp;
    fp = fopen("Pic.txt", "w");
    fprintf(fp, "%d %d %d\n", pap.paperWidth, pap.paperHeight, pap.squreSize);
    for (int i = 0; i < pap.paperHeight; i++) {
        for (int j = 0; j < pap.paperWidth; j++)
            for (int k = 0; k < 3; k++)
                fprintf(fp, "%hhu %hhu %hhu ", pap.paper[i][j].red, pap.paper[i][j].green, pap.paper[i][j].blue);
        fprintf(fp, "\n");
    }
    fclose(fp);

}

Pos getPoint (Paper & pap, int poX, int poY) {

    Pos t;
    t.x = (poX - pap.abX) / pap.squreSize;
    t.y = (pap.paperHeight * pap.squreSize - pap.abY + poY) / pap.squreSize;

//  if (x >= 0 && x <= pap.paperWidth && y >= 0 && y <= pap.paperHeight)
//  没有检测是不是在图内
    return t;

}

void ini_paper (Paper & pap, int poX, int poY) {

    pap.paper = (Color_wc **) malloc(pap.paperHeight * sizeof(Color_wc *));
    for (int i = 0; i < pap.paperHeight; i++)
        pap.paper[i] = (Color_wc *) malloc(pap.paperWidth * sizeof(Color_wc));


    for (int i = 0; i < pap.paperHeight; i++)
        for (int j = 0; j < pap.paperWidth; j++)
            pap.paper[i][j].red = pap.paper[i][j].green = pap.paper[i][j].blue = 127;

    pap.abX = poX;
    pap.abY = poY;

}
