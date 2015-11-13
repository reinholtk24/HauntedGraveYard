#include "graveyard.h"
#include <iostream>

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

void GraveYard::setGrave(int x, int y)
{
    graveYard.at(x).at(y) = 1;
}

 void GraveYard::setHauntedHole(int x1, int y1, int x2, int y2, int time)
 {
     graveYard.at(x1).at(y2) = 1;

 }

