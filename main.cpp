#include <iostream>
#include <fstream>
#include <string>
#include "structures.h"
#include "functions.h"

using namespace std;

int main(int argc, char *argv[])
{
    ifstream inputFile(switchArgument("-i", argc, argv));
    ofstream outputFile(switchArgument("-o", argc, argv));

    if (inputFile.is_open())
    {
        string line;
        car *cars = nullptr;
        int mode = 0;

        while (getline(inputFile, line))
        {
            switch (inputMode(line, mode))
            {
            case 1: //Line indicates there is a new car
                newCar(cars);
                break;
            case 2: //Line contains car info
                getCarInfo(line, cars);
                break;
            case 3: //Line contains plate info
                newPlate(line, cars);
                break;
            case 4: //Line contains owner info
                newOwner(line, cars);
                break;
            }
        }
    }
    return 0;
}