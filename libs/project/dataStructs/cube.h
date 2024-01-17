typedef struct
{
    Array *points;
    Array *lines; // contains indx of points
} Cube;

Cube *initCube()
{
    Cube *cube = (Cube *)malloc(sizeof(Cube));

    // points
    cube->points = initArray();
    double points[8][3] = {{-1, 1, 1}, {1, 1, 1}, {1, -1, 1}, {-1, -1, 1}, {-1, 1, -1}, {1, 1, -1}, {1, -1, -1}, {-1, -1, -1}};

    Point *currentPoint;
    for (int i = 0; i < 8; i++)
    {
        currentPoint = initPoint(points[i][0], points[i][1], points[i][2]);
        pushArrayNode(cube->points, currentPoint);
    }

    // lines
    cube->lines = initArray();
    double lines[12][2] = {
        {0, 1},
        {1, 2},
        {2, 3},
        {3, 0},
        //
        {4, 5},
        {5, 6},
        {6, 7},
        {7, 4},
        //
        {0, 4},
        {1, 5},
        {2, 6},
        {3, 7},
    };

    int *coord;
    for (int i = 0; i < 12; i++)
    {
        coord = (int *)malloc(sizeof(int) * 2);
        coord[0] = lines[i][0];
        coord[1] = lines[i][1];

        pushArrayNode(cube->lines, coord);
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

void rotateCubeY(Cube *cube, double a)
{
    Point *current;
    Point *new;
    for (int i = 0; i < cube->points->length; i++)
    {
        current = cube->points->arr[i].val;
        new = rotatePointY(current, a);

        cube->points->arr[i].val = new;
        free(current);
    }
}

void rotateCubeZ(Cube *cube, double a)
{
    Point *current;
    Point *new;
    for (int i = 0; i < cube->points->length; i++)
    {
        current = cube->points->arr[i].val;
        new = rotatePointZ(current, a);

        cube->points->arr[i].val = new;
        free(current);
    }
}

//
Cube *initCube2()
{
    Cube *cube = (Cube *)malloc(sizeof(Cube));

    // points
    cube->points = initArray();

    //
    int n = 10;
    double n2 = (double)n / 2;

    Point *currentPoint;
    double x, y, z;

    for (int k = 0; k < n; k++)
    {
        z = k;
        z -= n2;
        z /= n2;

        for (int i = 0; i < n; i++)
        {
            x = i;
            x -= n2;
            x /= n2;
            for (int j = 0; j < n; j++)
            {
                y = j;
                y -= n2;
                y /= n2;

                currentPoint = initPoint(x, y, z);
                pushArrayNode(cube->points, currentPoint);
            }
        }
    }

    // lines
    cube->lines = initArray();

    return cube;
}
