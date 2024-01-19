#define SCALE 200
#define MX SCREEN_WIDTH / 2
#define MY SCREEN_HEIGHT / 2

void drawObject(
    SDL_Renderer *renderer, Object *obj)
{

    // points
    Point *current;
    for (int i = 0; i < obj->points->length; i++)
    {
        current = obj->points->arr[i].val;
        SDL_RenderDrawPoint(renderer, current->x * SCALE + MX, current->y * SCALE + MY);
    }

    // lines
    int *points;
    Point *point1;
    Point *point2;

    for (int i = 0; i < obj->lines->length; i++)
    {
        points = obj->lines->arr[i].val;

        point1 = obj->points->arr[points[0]].val;
        point2 = obj->points->arr[points[1]].val;

        SDL_RenderDrawLine(
            renderer,
            point1->x * SCALE + MX,
            point1->y * SCALE + MY,

            point2->x * SCALE + MX,
            point2->y * SCALE + MY);
    }
}
