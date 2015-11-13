#include <iostream>
#include "graveyard.h"
#include <fstream>
#include <sstream>
#include <vector>

std::vector<int> getNumbers(std::string inString);

int main()
{
    std::vector<int> myNums;
    myNums.clear();
    myNums.resize(1);


    std::cout << "hello world." << std::endl;

    std::cout << "Viewing initialized graveyard." << std::endl;

    std::string line = "";
    std::ifstream myfile ("randomGraveYard.txt");

      if (myfile.is_open())
      {
            while ( getline (myfile,line) )
            {
                myNums = getNumbers(line);

                for(int i = 0; i < myNums.size(); i++)
                {
                    std::cout << myNums.at(i) << " ";
                }

                std::cout << std::endl;

                myNums.clear();
            }
            myfile.close();
      }

  else {std::cout << "Unable to open file"; }

    GraveYard myYard(3,3);

    myYard.viewYard();

    myYard.setGrave(1,2);

    myYard.viewYard();

    return 0;
}

std::vector<int> getNumbers(std::string inString)
{
    std::vector<int> numbers;
    numbers.clear();
    numbers.resize(1);

    std::string currentNum = "";

    for(int k = 0; k < inString.length(); k++)
    {
        if(inString.at(k) == ' ' || inString.at(k) == '/n')
        {
            std::istringstream buffer(currentNum);
            int value = 0;
            buffer >> value;
            numbers.push_back(value);
            currentNum = "";
        }
        else
        {
            currentNum = currentNum + inString.at(k);
            std::cout << "CurrentNum: " << currentNum << std::endl;
        }
    }

    return numbers;
}
