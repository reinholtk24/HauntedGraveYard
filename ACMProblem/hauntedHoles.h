#ifndef hauntedHoles_H
#define hauntedHoles_H
#include <vector>

class HauntedHoles
{
public:
    HauntedHoles(){}
    HauntedHoles(int x2, int y2)
    {
        x = x2;
        y = y2;
    }

private:
    int x;
    int y;
    int time;
};

#endif //hauntedHoles_H
