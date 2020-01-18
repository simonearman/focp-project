#include <iostream>
#include "structures.h"
#include "functions.h"

string switchArgument(string switchName, int argc, char *argv[])
{
    for (int i = 0; i < argc; i++)
    {
        string argument = argv[i];
        if (argument == switchName)
        {
            return argv[i + 1];
        }
    }
    return "";
}

void newCar(car *&p)
{
    if (!p)
    {
        p = new car;
    }

    auto pointer = p;

    while (pointer->next)
    {
        pointer = pointer->next;
    }

    pointer->next = new car;
}

void getCarInfo(string line, car *&p)
{

}