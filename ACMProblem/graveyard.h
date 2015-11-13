#ifndef GRAVEYARD_H
#define GRAVEYARD_H
#include <vector>

// -1 Entrance
// -2 Exit
// 0 Grass
// 1 Grave
// 2 Holy Hole

class GraveYard
{
public:
    GraveYard();
    GraveYard(int W, int H);
    void viewYard();
    void setHauntedHole(int x1, int y1, int x2, int y2, int time); //x1,y1 is the location of the hole. y2,x2 is the location that the hole takes you.
    void setGrave(int x, int y);

private:
    std::vector<std::vector<int> > graveYard;
    int height;
    int width;

};
#endif // GRAVEYARD_H
