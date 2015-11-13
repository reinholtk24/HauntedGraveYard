#include <iostream>
#include "graveyard.h"
#include <fstream>
#include <sstream>
#include <vector>

std::vector<int> getNumbers(std::string inString);

int main()
{
    std::cout << "WELCOME TO THE HAUNTED GRAVEYARD" << std::endl;

    std::vector<std::vector<int> > myNums;
    myNums.clear();

    std::string line = "";
    std::ifstream myfile ("randomGraveYard.txt");

    if (myfile.is_open())
    {
            while ( getline (myfile,line) )
            {
                myNums.push_back(getNumbers(line));

            }
            myfile.close();
    }

    else {std::cout << "Unable to open file"; }

    std::cout << std::endl;

    int tracker = 0;
    int tries = 1;
    int numOfGraves = 0;
    int numOfHoles = 0;

    bool flag = true;

    std::cout << std::endl;

    while(flag == true)
    {
        if(myNums[tracker][0] == 0 && myNums[tracker][1] == 0)
        {
            flag = false;
            break;
        }
        else
        {
            GraveYard myYard(myNums[tracker][0],myNums[tracker][1]);

            tracker++;

            numOfGraves = myNums[tracker][0];

            tracker++;

            if(numOfGraves == 0)
            {
                //Do nothing
            }
            else
            {
                for(int k = 0; k < numOfGraves; k++)
                {
                    myYard.setGrave(myNums[tracker][0],myNums[tracker][1]);
                    tracker++;
                }
            }

            numOfHoles = myNums[tracker][0];

            tracker++;

            if(numOfHoles == 0)
            {
                // Do nothing
            }
            else
            {
                for(int l = 0; l < numOfHoles; l++)
                {
                    myYard.setHauntedHole(myNums[tracker][0],myNums[tracker][1],myNums[tracker][2],myNums[tracker][3],myNums[tracker][4]);
                    tracker++;
                }
            }

            std::cout << "Yard Number: " << tries << std::endl;

            myYard.viewYard();

            myYard.clearIt();

            tries++;
        }

    }

    return 0;
}

std::vector<int> getNumbers(std::string inString)
{
    std::vector<int> numbers;
    numbers.clear();

    std::string currentNum = "";

    for(int k = 0; k < inString.length(); k++)
    {
        if(inString.at(k) == ' ')
        {
            std::stringstream buffer(currentNum);
            int value = 0;
            buffer >> value;
            numbers.push_back(value);
            currentNum = "";
            buffer.clear();
            buffer.str(std::string());
        }
        else if(k == inString.length()-1)
        {
            currentNum = currentNum + inString.at(k);
            std::stringstream newbuffer(currentNum);
            int valueTwo = 0;
            newbuffer >> valueTwo;
            numbers.push_back(valueTwo);
            currentNum = "";
            newbuffer.clear();
            newbuffer.str(std::string());
        }
        else
        {
            currentNum = currentNum + inString.at(k);
        }
    }

    return numbers;
}
