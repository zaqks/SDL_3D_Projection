#define N 31

typedef struct
{
    Array *points;
    Array *lines; // contains indx of points

} Object;

Object *initObject()
{
    Object *obj = (Object *)malloc(sizeof(Object));
    obj->points = initArray();
    obj->lines = initArray();

    return obj;
}

Object *cloneObject(Object *src)
{
    Object *dst = (Object *)malloc(sizeof(Object));
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

void freeObject(Object *obj)
{
    freeArray(obj->points);
    freeArray(obj->lines);
    free(obj);
}

Object *rotateObjectX(Object *src, double a)
{
    // clone the src
    Object *dst = cloneObject(src);
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

Object *rotateObjectY(Object *src, double a)
{
    // clone the src
    Object *dst = cloneObject(src);
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

Object *rotateObjectZ(Object *src, double a)
{
    // clone the src
    Object *dst = cloneObject(src);
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



