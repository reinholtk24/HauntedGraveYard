#include "graveyard.h"
#include <iostream>
#include "hauntedHoles.h"

GraveYard::GraveYard()
{
    height = 0;
    width = 0;
    //initialize array
}
GraveYard::GraveYard(int W, int H)
{
    graveYard.clear();
    graveYard.resize(H);
    height = H;
    width = W;

    for(int i = 0; i < H; i++)
    {
        graveYard.at(i).resize(W);
    }

    for(int j = 0; j < H; j++)
    {
        for(int k = 0; k < W; k++)
        {

            graveYard.at(j).at(k) = 0;

        }

    }

    graveYard[0][0] = -1;
    graveYard[H-1][W-1] = -2;
    holes.clear();
    holeCounter = 2;
    holeIndex = holeCounter - 2;
}

void GraveYard::viewYard()
{
    for(int j = 0; j < height; j++)
    {
        for(int k = 0; k < width; k++)
        {

            std::cout << graveYard.at(j).at(k) << " ";

        }
        std::cout << std::endl;
    }


}
void GraveYard::clearIt()
{
    holes.clear();
    graveYard.clear();
    holeCounter = 0;
    holeIndex = 0;
    height = 0;
    width = 0;
}

void GraveYard::setGrave(int x, int y)
{
    if(x > 0 && y > 0 )
    {
         graveYard.at(y).at(x) = 1;
    }
    else if(x == 0 && y > 0 )
    {
        graveYard.at(y).at(x) = 1;
    }
    else if( x > 0 && y == 0)
    {
        graveYard.at(y).at(x) = 1;
    }
}

 void GraveYard::setHauntedHole(int x1, int y1, int x2, int y2, int time)
 {
    if(x1 > 0 && y1 > 0 )
    {
         graveYard.at(y1).at(x1) = holeCounter; // Set Grave position beginning with value of two;
         HauntedHoles newHole(x2,y2,time); // in
         holes[holeIndex] = newHole;
         holeCounter++;
         holeIndex++;
    }
    else if(x1 == 0 && y1 > 0 )
    {
        graveYard.at(y1).at(x1) = holeCounter; // Set Grave position beginning with value of two;
         HauntedHoles newHole(x2,y2,time); // in
         holes[holeIndex] = newHole;
         holeCounter++;
         holeIndex++;
    }
    else if( x1 > 0 && y1 == 0)
    {
        graveYard[y1][x1] = holeCounter; // Set Grave position beginning with value of two;
         HauntedHoles newHole(x2,y2,time); // in
         holes.push_back(newHole);
         holeCounter++;
         holeIndex++;
    }


 }

