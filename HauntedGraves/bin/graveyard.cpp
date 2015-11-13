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

 void GraveYard::gravePath()
 {
     currentX = 0;
     currentY = 0;
     paths.clear();
     paths.resize(height);
     visited.clear();
     visited.resize(height);

     for(int i = 0; i < height; i++)
     {
         paths.at(i).resize(width);
         visited.at(i).resize(width);
     }

     for (int i = 0; i < height; i++)
     {
         for (int j = 0; j < width; j++)
         {
             visited[i][j] = -1;
         }
     }
     int complete = 0;
     while(1)
     {
         if(around(currentX, currentY, (currentX + 1), currentY == 1))
         {
             complete = 1;
         }
         if (around(currentX, currentY, (currentX - 1), currentY == 1))
         {
             complete  = 1;
         }
         if (around(currentX, currentY, currentX, (currentY + 1))== 1)
         {
             complete = 1;
         }
         if (around(currentX, currentY, currentX, (currentY - 1)) == 1)
         {
             complete = 1;
         }

         visited[currentY][currentX] = 1;

         int found = 0;
         int minWeight = 0;
         int nextX = 0;
         int nextY = 0;
         for (int i = 0; i < height; i++)
         {
             for (int j = 0; j < width; j++)
             {
                 if (visited[i][j] == 0)
                 {
                     if (found == 0)
                     {
                         minWeight = paths[i][j]->getTotalWeight();
                         nextX = j;
                         nextY = i;
                         found = 1;
                     }
                     else if (found == 1 && paths[i][j]->getTotalWeight() < minWeight)
                     {
                         minWeight = paths[i][j]->getTotalWeight();
                         nextX = j;
                         nextY = i;
                     }
                 }
             }
         }
         if (found == 0)
         {
             if (complete == 1)
             {
                 std::cout << paths[height][width]->getTotalWeight() << std::endl;
                 break;
             }
             else if(complete == 0)
             {
                 std::cout << "Impossible" << std::endl;
                 break;
             }
         }
         else if (found == 1)
         {
             currentX = nextX;
             currentY = nextY;
         }
     }
 }

 int GraveYard::around(int fromX, int fromY, int toX, int toY)
 {
     if (toX < (height -1) && toY < (width -1) && graveYard[fromY][fromX] == 0)
     {
         toGrass(fromX, fromY, toX, toY, paths[fromY][fromX]->getTotalWeight());
         return 0;
     }
     else if (toX < (height -1) && toY < (width -1) && graveYard[fromY][fromX] == 1)
     {
         toGrave(toX, toY);
         return 0;
     }
     else if (toX < (height -1) && toY < (width -1) && graveYard[fromY][fromX] >= 2)
     {
         toHole(fromX, fromY, toX, toY, paths[fromY][fromX]->getTotalWeight(), graveYard[fromY][fromX]);
         return 0;
     }
     else if (toX < (height -1) && toY < (width -1) && graveYard[fromY][fromX] == -2)
     {
         toExit(toX, toY, toX, toY, paths[fromY][fromX]->getTotalWeight());
         return 1;
     }
 }

 void GraveYard::toGrave(int x, int y)
 {
     if (visited[y][x] != 1)
     {
         visited[y][x] = 1;
         path *pathing = new path(-1,-1,-1);
         paths[y][x] = pathing;
     }
 }

 void GraveYard::toHole(int fromX, int fromY,int toX, int toY, int weight, int holeNumber)
 {
     if (visited[toY][toX] != 1)
     {
         int index = holeNumber - 2;
         if (visited[toY][toX] != -1)
         {
             path *pathing = new path(fromX, fromY, weight + 1);
             paths[toY][toX] = pathing;
             visited[toY][toX] = 0;
         }
         else if (visited[toY][toX] != -1 || paths[toY][toX]->getTotalWeight() < (weight + 1))
         {
             delete paths[toY][toX];
             path *pathing = new path(fromX, fromY, weight + 1);
             paths[toY][toX] = pathing;
         }
         //Other hole end here
     }
 }

 void GraveYard::toGrass(int fromX, int fromY, int toX, int toY, int weight)
 {
     if (visited[toY][toX] != 1)
     {
         if (visited[toY][toX] != -1)
         {
             path *pathing = new path(fromX, fromY, weight + 1);
             paths[toY][toX] = pathing;
             visited[toY][toX] = 0;
         }
         else if (visited[toY][toX] != -1 || paths[toY][toX]->getTotalWeight() < (weight + 1))
         {
             delete paths[toY][toX];
             path *pathing = new path(fromX, fromY, weight + 1);
             paths[toY][toX] = pathing;
         }
     }
 }

 void GraveYard::toExit(int fromX, int fromY, int toX, int toY, int weight)
 {
     if (visited[toY][toX] != 1)
     {
         if (visited[toY][toX] != -1)
         {
             path *pathing = new path(fromX, fromY, weight + 1);
             paths[toY][toX] = pathing;
             visited[toY][toX] = 0;
         }
         else if (visited[toY][toX] != -1 || paths[toY][toX]->getTotalWeight() < (weight + 1))
         {
             delete paths[toY][toX];
             path *pathing = new path(fromX, fromY, weight + 1);
             paths[toY][toX] = pathing;
         }
     }

 }

