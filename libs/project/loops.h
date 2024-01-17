double scale = 100;
double mx = 200;
double my = 200;

Cube *cubes[3] = {};
double aX = 0;
double aY = 0;
double aZ = 0;

bool lock = false;

void eventFunc(SDL_Event e)
{
    // keyboard
    if (e.type == SDL_KEYDOWN)
    {
        switch (e.key.keysym.sym)
        {
        case SDLK_LEFT:
            aY += 1;
            break;
        case SDLK_RIGHT:
            aY -= 1;
            break;
        //
        case SDLK_UP:
            aX += 1;
            break;
        case SDLK_DOWN:
            aX -= 1;
            break;

        default:
            break;
        }
    }

    // mouse
    if (e.type == SDL_MOUSEBUTTONDOWN)
    {
        lock = true;
    }
    if (e.type == SDL_MOUSEBUTTONUP)
    {
        lock = false;
    }

    if (lock)
    {

        if (e.type == SDL_MOUSEMOTION)
        {
            aY -=  e.motion.xrel/2;
            aX +=  e.motion.yrel/2;
            
        }
    }
}

void loopFunc(Window *win)
{

    cube2 = rotateObjectX(cube, aX);
    cubes[0] = cube2;

    cube2 = rotateObjectY(cube2, aY);
    cubes[1] = cube2;

    cube2 = rotateObjectZ(cube2, aZ);
    cubes[2] = cube2;

    //
    SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
    SDL_RenderClear(renderer);

    SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
    drawObject(renderer, cube2);

    for (int i = 0; i < 3; i++)
    {
        freeObject(cubes[i]);
    }

    //
    SDL_RenderPresent(renderer);
}
