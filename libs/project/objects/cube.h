#define SCALE 200
#define MX SCREEN_WIDTH / 2
#define MY SCREEN_HEIGHT / 2

void drawCubeW(
    SDL_Renderer *renderer, Cube *cube)
{

    // points
    Point *current;
    for (int i = 0; i < cube->points->length; i++)
    {
        current = cube->points->arr[i].val;
        SDL_RenderDrawPoint(renderer, current->x * SCALE + MX, current->y * SCALE + MY);
    }

    // lines
    int *points;
    Point *point1;
    Point *point2;

    for (int i = 0; i < cube->lines->length; i++)
    {
        points = cube->lines->arr[i].val;

        point1 = cube->points->arr[points[0]].val;
        point2 = cube->points->arr[points[1]].val;

        SDL_RenderDrawLine(
            renderer,
            point1->x * SCALE + MX,
            point1->y * SCALE + MY,

            point2->x * SCALE + MX,
            point2->y * SCALE + MY);
    }
}
