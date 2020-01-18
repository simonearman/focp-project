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

        while (getline(inputFile, line))
        {
            if (line == "--- car ---")
            {
                newCar(cars);
            }
            else
            {
                getCarInfo(line, cars);
            }
        }
    }



    return 0;
}