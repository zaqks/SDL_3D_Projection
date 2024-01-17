#include "libs/project/imports.h"

int main()
{
    win = initWin("3D projection");
    renderer = win->renderer;

    cube = initCube2();

    mainLoop(win, eventFunc, loopFunc);

    return 0;
}
