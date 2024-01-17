#define SCALE 100
#define MX 200
#define MY 200

void drawCubeW(
    SDL_Renderer *renderer, Cube *cube)
{

    Point *current;
    for (int i = 0; i < cube->points->length; i++)
    {
        current = cube->points->arr[i].val;
        SDL_RenderDrawPoint(renderer, current->x * SCALE + MX, current->y * SCALE + MY);
    }
}
