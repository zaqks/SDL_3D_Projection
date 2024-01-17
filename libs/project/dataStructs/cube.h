#define N 20

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

Cube *initCube2()
{
    Cube *cube = (Cube *)malloc(sizeof(Cube));

    // points
    cube->points = initArray();

    //
    
    double n2 = (double)N / 2;

    Point *currentPoint;
    double x, y, z;

    for (int k = 0; k < N; k++)
    {
        z = k;
        z -= n2;
        z /= n2;

        for (int i = 0; i < N; i++)
        {
            x = i;
            x -= n2;
            x /= n2;
            for (int j = 0; j < N; j++)
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

Cube *cloneCube(Cube *src)
{
    Cube *dst = (Cube *)malloc(sizeof(Cube));
    dst->points = initArray();
    dst->lines = initArray();

    // points
    Point *currentP;
    for (int i = 0; i < src->points->length; i++)
    {
        currentP = src->points->arr[i].val;
        pushArrayNode(dst->points, initPoint(currentP->x, currentP->y, currentP->z));
    }

    // lines
    int *current;
    int *line;
    for (int i = 0; i < src->lines->length; i++)
    {
        current = src->lines->arr[i].val;
        line = (int *)malloc(sizeof(int) * 2);
        line[0] = current[0];
        line[1] = current[1];

        pushArrayNode(dst->lines, line);
    }

    return dst;
}

void freeCube(Cube *cube)
{
    freeArray(cube->points);
    freeArray(cube->lines);
    free(cube);
}

Cube * rotateCubeX(Cube *src, double a)
{
    // clone the src
    Cube *dst = cloneCube(src);
    //

    Point *current;
    Point *new;
    for (int i = 0; i < dst->points->length; i++)
    {
        current = dst->points->arr[i].val;
        new = rotatePointX(current, a);

        dst->points->arr[i].val = new;
        free(current);
    }

    return dst;
}

Cube *rotateCubeY(Cube *src, double a)
{
    // clone the src
    Cube *dst = cloneCube(src);
    //

    Point *current;
    Point *new;
    for (int i = 0; i < dst->points->length; i++)
    {
        current = dst->points->arr[i].val;
        new = rotatePointY(current, a);

        dst->points->arr[i].val = new;
        free(current);
    }

    return dst;
}

Cube * rotateCubeZ(Cube *src, double a)
{
    // clone the src
    Cube *dst = cloneCube(src);
    //

    Point *current;
    Point *new;
    for (int i = 0; i < dst->points->length; i++)
    {
        current = dst->points->arr[i].val;
        new = rotatePointZ(current, a);

        dst->points->arr[i].val = new;
        free(current);
    }

    return dst;
}

//
