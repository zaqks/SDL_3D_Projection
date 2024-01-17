#include "libs/project/imports.h"

int main()
{
    win = initWin("3D projection");
    renderer = win->renderer;

    //cube = initCube2();
    pyr = initPyramid2();

    mainLoop(win, eventFunc, loopFunc);

    return 0;
}
