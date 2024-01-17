

typedef Object Cube;

Cube *initCube()
{
    Cube *cube = initObject();

    // points
    double points[8][3] = {{-1, 1, 1}, {1, 1, 1}, {1, -1, 1}, {-1, -1, 1}, {-1, 1, -1}, {1, 1, -1}, {1, -1, -1}, {-1, -1, -1}};

    Point *currentPoint;
    for (int i = 0; i < 8; i++)
    {
        currentPoint = initPoint(points[i][0], points[i][1], points[i][2]);
        pushArrayNode(cube->points, currentPoint);
    }

    // lines
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
    Cube *cube = initObject();

    // points

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

    return cube;
}
