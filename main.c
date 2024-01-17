#include "libs/project/imports.h"

int main()
{
    win = initWin("3D projection");

    mainLoop(win, eventFunc, loopFunc);

    return 0;
}
