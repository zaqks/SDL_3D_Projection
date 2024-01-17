double scale = 100;
double angle = 1;
double mx = 200;
double my = 200;

void loopFunc(Window *win)
{
    rotateCubeX(cube, angle);
    rotateCubeY(cube, angle);
    rotateCubeZ(cube, angle);


    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);
    //

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    drawCubeW(renderer, cube);

    //
    SDL_RenderPresent(renderer);
}

void eventFunc(SDL_Event e)
{
}