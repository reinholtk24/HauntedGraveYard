#include "path.h"

path::path(int x, int y, int weight)
{
    fromX = x;
    fromY = y;
    totalWeight = weight;
}

int path::getFromX()
{
    return fromX;
}

int path::getFromY()
{
    return fromY;
}

int path::getTotalWeight()
{
    return totalWeight;
}

path::~path()
{
    //dtor
}
