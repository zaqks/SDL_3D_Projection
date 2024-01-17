typedef Object Pyramid;

Pyramid *initPyramid2()
{
    Pyramid *obj = initObject();

    double n2 = (double)N / 2;

    Point *currentPoint;
    double x, y, z;

    for (int k = 0; k < N; k++)
    {
        z = k;
        z -= n2;
        z /= n2;

        for (int j = 0; j < N; j++)
        {
            //j += 1;

            y = j;
            y -= n2;
            y /= n2;
            //
            for (int i = 0; i < j; i++)
            {
                x = i + (N - j) / 2;
                x -= n2;
                x /= n2;
                //

                currentPoint = initPoint(x, y, z);
                pushArrayNode(obj->points, currentPoint);
            }
        }
    }

    return obj;
}
