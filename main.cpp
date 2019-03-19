#include <GLUT/glut.h>
#include "draw_wc.h"
#include "painter_wc.h"

GLsizei Width = 1000, Height = 700;

/************************************
 * Model to select
 ************************************/
const int PIXEL_MODE_1 = 1;     // 90  * 60
const int PIXEL_MODE_2 = 2;     // 180 * 120
const int PIXEL_MODE_3 = 3;     // 300 * 200
const int PIXEL_MODE_4 = 4;     // 450 * 300
const int PIXEL_MODE_5 = 5;     // 900 * 600

int pixel_mode = PIXEL_MODE_2;
bool hasLines = true;           // Paper has lines or not

/************************************
 * OpenGL model
 ************************************/
void init();
void Display();
void Reshape(GLsizei newWidth, GLsizei newHeight);
void Mouse(int button, int state, int x, int y);
void myMotion(int x, int y);
void Keyboard(unsigned char key, int x, int y);

/************************************
 * Environmental variables
 ************************************/
Paper pap;
MFButtonSet butSet;
MFButton mfLineButton, mfRecButton, mfRoundButton;
Tag info;

bool motion;
bool firKey, isInput;

Color_wc colorAtTime;
PanelTag pTag;
Panel pal;

int main(int argc, char ** argv) {

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(Width, Height);
    glutCreateWindow("Text");

    init();
    glutDisplayFunc(Display);
    glutReshapeFunc(Reshape);
    glutMouseFunc(Mouse);
    glutKeyboardFunc(Keyboard);
    glutMotionFunc(myMotion);
    glutMainLoop();

    return 0;
}

void init() {
    /*
     * OpenGl needed
     */
    glClearColor(0.2f, 0.2f, 0.2f, 1.0f);

    /*
     * Create a Paper
     * ? write in Paper
     */
    switch (pixel_mode) {
        case PIXEL_MODE_1:
            setPaperSize(pap, 10);
            setPaperFront(pap, 90, 60);
            break;
        case PIXEL_MODE_2:
            setPaperSize(pap, 5);
            setPaperFront(pap, 180, 120);
            break;
        case PIXEL_MODE_3:
            setPaperSize(pap, 3);
            setPaperFront(pap, 300, 200);
            break;
        case PIXEL_MODE_4:
            setPaperSize(pap, 2);
            setPaperFront(pap, 450, 300);
            break;
        case PIXEL_MODE_5:
            setPaperSize(pap, 1);
            setPaperFront(pap, 900, 600);
            break;
        default:
            break;
    }
    ini_paper(pap, 100, Height);

    /*
     * Create Buttons
     */
    ini_MFButton(mfLineButton, line_wc, 10, 600);
    ini_MFButton(mfRecButton, rectangle_wc, 10, 550);
    ini_MFButton(mfRoundButton, round_wc, 10, 500);
    ini_MFButtonSet(butSet);
    addMFButton(butSet, mfLineButton);
    addMFButton(butSet, mfRoundButton);
    addMFButton(butSet, mfRecButton);

    /*
     * Create a Panel
     */
    ini_panel (pal, 0, Height);

    /*
     * Initialize some environmental variables
     */
    info = none_wc;
    firKey = true;
    colorAtTime = BLANK_WC;
    pTag = blank_wc;

}

void Reshape(GLsizei newWidth, GLsizei newHeight) {

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glViewport(0, 0, newWidth, newHeight);
    gluOrtho2D(0, newWidth, 0, newHeight);
    Width = newWidth;
    Height = newHeight;
    glMatrixMode(GL_MODELVIEW);

}

void Display() {

    glClear(GL_COLOR_BUFFER_BIT);

    /*
     * Show the function or the panel (function selected)
     * Need for changes
     */
    if (info == none_wc)
        drawMFButtons(butSet);
    else
        drawPanel (pal);

    /*
     * Draw the Paper of course
     * Draw means using the OpenGL function, while paint means changing the Paper's pixel only
     */
    drawPaper(pap, hasLines);

    /*
     * Draw the frame
     */
    text_draw_other();

    /*
     * Draw some information in words at the button of the window
     * First line: function selected
     * Second line: color at the time
     * Third line: feedback from the keyboard
     */
    text_draw_info(info);
    if (info != none_wc)
        text_draw_info(pTag);
    if (!firKey)
        text_draw_keyInfo(isInput);

    /*
     * Draw the Pic element which has not been recorded in the Paper
     */
    if (motion)
        switch (info) {
            case line_wc:
                text_lineBres(pap, mfLineButton, colorAtTime);
                break;
            case rectangle_wc:
                text_rect(pap, mfRecButton, colorAtTime);
                break;
            case round_wc:
                text_roudBres(pap, mfRoundButton, colorAtTime);
                break;
            default:
                break;
        }

    glutSwapBuffers();

}

void Mouse(int button, int state, int x, int y) {

    int xx = x, yy = Height - y;                                         // left up as the zero point

    /*
     * Need for changes!
     */
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        /*
         * Has clicked in the left (or Panel) area
         */
        if (x > 0 && x < 100 && y > 0 && y < 600) {
            if (info == none_wc)
                info = checkMFButton(butSet, xx, yy);
            else {
                pTag = checkPanel(pal, xx, yy);
                if (pTag != nothing_wc && pTag != back_wc)
                    colorAtTime = changeColor(pTag);
                else if (pTag == back_wc) {
                    info = none_wc;
                    pTag = blank_wc;
                    colorAtTime = BLANK_WC;
                }
            }
        }

        /*
         * has clicked in the Paper
         */
        if (x > 100 && x < 1000 && y > 0 && y < 600) {
            Pos start = getPoint(pap, xx, yy);
            switch (info) {
                case line_wc:
                    changeMFButtonPos(mfLineButton, start, true);
                    changeMFButtonPos(mfLineButton, start, false);
                    break;
                case rectangle_wc:
                    changeMFButtonPos(mfRecButton, start, true);
                    changeMFButtonPos(mfRecButton, start, false);
                    break;
                case round_wc:
                    changeMFButtonPos(mfRoundButton, start, true);
                    changeMFButtonPos(mfRoundButton, start, false);
                    break;
                default:
                    break;
            }

            motion = true;
        }

    }

    if (button == GLUT_LEFT_BUTTON && state == GLUT_UP) {
        if (x > 100 && x < 1000 && y > 0 && y < 600) {
            Pos end = getPoint(pap, xx, yy);
            switch (info) {
                case line_wc:
                    changeMFButtonPos(mfLineButton, end, false);
                    lineBres(pap, mfLineButton, colorAtTime);
                    break;
                case rectangle_wc:
                    changeMFButtonPos(mfRecButton, end, false);
                    rect (pap, mfRecButton, colorAtTime);
                    break;
                case round_wc:
                    changeMFButtonPos(mfRoundButton, end, false);
                    roudBres(pap, mfRoundButton, colorAtTime);
                    break;
                default:
                    break;
            }

            motion = false;
        }

    }

    glutPostRedisplay();

}

void myMotion(int x, int y) {

    int xx = x, yy = Height - y;

    if (x > 100 && x < 1000 && y > 0 && y < 600) {
        Pos end = getPoint(pap, xx, yy);
        switch (info) {
            case line_wc:
                changeMFButtonPos(mfLineButton, end, false);
                break;
            case rectangle_wc:
                changeMFButtonPos(mfRecButton, end, false);
                break;
            case round_wc:
                changeMFButtonPos(mfRoundButton, end, false);
                break;
            default:
                break;
        }
    }

    glutPostRedisplay();
}

void Keyboard(unsigned char key, int x, int y) {

    if (firKey) {
        switch(key) {
            case 'i':
            case 'I':
                isInput = true;
                firKey = false;
                break;
            case 'o':
            case 'O':
                isInput = false;
                firKey = false;
                break;
            default:
                break;
        }
    }
    else {
        switch (key) {
            case 'y':
            case 'Y':
                if (isInput)
                    loadIn (pap);
                else
                    loadOut (pap);
                break;
            default:

                break;
        }
        firKey = true;
    }

    glutPostRedisplay();

}