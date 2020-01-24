#include <iostream>
#include <fstream>
#include <string>
#include "structures.h"
#include "functions.h"

using namespace std;

int main(int argc, char *argv[])
{
    if (checkSwitches(argc, argv) == false)
    {
        cout << "Please provide correct arguments for switches -i and -o";
        return 0;
    }

    ifstream inputFile(switchArgument("-i", argc, argv));
    ofstream outputFile(switchArgument("-o", argc, argv));
    car *cars = nullptr;

    if (inputFile.is_open())
    {
        string line;
        int mode = 0;

        while (getline(inputFile, line))
        {
            getInfoFromLine(inputFile, cars, line, mode);
        }
        inputFile.close();
    }

    createReport(outputFile, cars);

    outputFile.close();

    deleteCars(cars);

    cout << "Output file has been created" << endl;;
    return 0;
}