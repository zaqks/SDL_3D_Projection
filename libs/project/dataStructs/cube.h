typedef struct
{
    Array *points;
    Array *lines;
} Cube;

Cube *initCube()
{
    Cube *cube = (Cube *)malloc(sizeof(Cube));

    cube->points = initArray();

    double points[8][3] = {{-1, 1, 1}, {1, 1, 1}, {1, -1, 1}, {-1, -1, 1}, {-1, 1, -1}, {1, 1, -1}, {1, -1, -1}, {-1, -1, -1}};

    //

    //

    double x, y, z;

    Point *currentPoint;
    for (int i = 0; i < 8; i++)
    {
        currentPoint = initPoint(points[i][0], points[i][1], points[i][2]);
        pushArrayNode(cube->points, currentPoint);
    }

    return cube;
}

void rotateCubeX(Cube *cube, double a)
{
    Point *current;
    Point *new;
    for (int i = 0; i < cube->points->length; i++)
    {
        current = cube->points->arr[i].val;
        new = rotatePointX(current, a);

        cube->points->arr[i].val = new;
        free(current);
    }
}