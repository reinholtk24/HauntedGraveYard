#ifndef hauntedHoles_H
#define hauntedHoles_H
#include <vector>

class HauntedHoles
{
public:
    HauntedHoles(){}
    HauntedHoles(int x2, int y2, int weight)
    {
        x = x2;
        y = y2;
        time = weight;
    }
    void setX(int x);
    void setY(int y);
    int getY();
    int getX();
    void setTime(int time);
    int getTime();

private:
    int x;
    int y;
    int time;
};

#endif //hauntedHoles_H
