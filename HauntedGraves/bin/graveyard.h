#ifndef GRAVEYARD_H
#define GRAVEYARD_H
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "hauntedHoles.h"
#include "path.h"

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
    void clearIt();
    void gravePath();
    int around(int fromX, int fromY, int toX, int toY);
    void toGrave(int x, int y);
    void toHole(int fromX, int fromY,int toX, int toY, int weight, int holeNumber);
    void toGrass(int fromX, int fromY,int toX, int toY, int weight);
    void toExit(int fromX, int fromY, int toX, int toY, int weight);

private:
    std::vector<std::vector<int> > graveYard;
    std::vector<HauntedHoles> holes;
    int height;
    int width;
    int holeCounter;
    int holeIndex;
    int currentX;
    int currentY;
    std::vector<std::vector<path*> > paths;
    std::vector<std::vector<int> > visited;

};
#endif // GRAVEYARD_H
