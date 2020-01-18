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

void inputMode(string line, int &mode)
{
    if (line.find("--- car ---") == 0)
        mode = 1;
    else if (mode == 1)
        mode = 2;
    else if (line.find("vehicle registration plate") == 0)
        mode = 3;
    else if (line.find("owner") == 0)
        mode = 4;
}

car *lastCar(car *p)
{
    while (p->next)
        p = p->next;
    return p;
}

void newCar(car *&p)
{
    if (!p)
    {
        p = new car;
    }
    else
    {
        lastCar(p)->next = new car;
    }
}

void getCarInfo(string line, car *&p)
{
    if (p)
    {
        if (line.rfind("brand", 0) == 0)
        {
            lastCar(p)->brand = line.substr(line.rfind(" ") + 1);
        }
        else if (line.rfind("model", 0) == 0)
        {
            lastCar(p)->model = line.substr(line.rfind(" ") + 1);
        }
        else if (line.rfind("year of construction", 0) == 0)
        {
            lastCar(p)->constructionYear = line.substr(line.rfind(" ") + 1);
        }
        else if (line.rfind("engine capacity", 0) == 0)
        {
            lastCar(p)->engineCapacity = line.substr(line.rfind(" ") + 1);
        }
        else if (line.rfind("engine number", 0) == 0)
        {
            lastCar(p)->engineNumber = line.substr(line.rfind(" ") + 1);
        }
        else if (line.rfind("VIN number", 0) == 0)
        {
            lastCar(p)->VIN = line.substr(line.rfind(" ") + 1);
        }
        else if (line.rfind("first registration", 0) == 0)
        {
            lastCar(p)->firstRegistration = line.substr(line.rfind(" ") + 1);
        }
    }
}

plate* lastCarLastPlate(car *p)
{
    auto pointer = lastCar(p)->plates;
    while (pointer->next)
        pointer = pointer->next;
    return pointer;
}

void newPlate(string line, car *&p)
{
    if (line.find("vehicle registration plate") != 0)
    {
        if (!lastCar(p)->plates)
        {
            lastCar(p)->plates = new plate{line.substr(0, line.find(" ")), line.substr(line.find(" ") + 1)};
        }
        else
        {
            lastCarLastPlate(p)->next = new plate{line.substr(0, line.find(" ")), line.substr(line.find(" ") + 1)};
        }
    }
}

owner *lastCarLastOwner(car *p)
{
    auto pointer = lastCar(p)->owners;
    while (pointer->next)
        pointer = pointer->next;
    return pointer;
}

void newOwner(string line, car *&p)
{
    if (line.find("owner") != 0)
    {
        if (line.find(",") == string::npos) //If there is only one name
        {
            if (!lastCar(p)->owners)
            {
                lastCar(p)->owners = new owner{line.substr(0, line.find(" ")), line.substr(line.find(" ") + 1)};
            }
            else
            {
                lastCarLastOwner(p)->next = new owner{line.substr(0, line.find(" ")), line.substr(line.find(" ") + 1)};
            }
        }
        else //If there are two names
        {
            if (!lastCar(p)->owners)
            {
                lastCar(p)->owners = new owner{line.substr(0, line.find(" ")), line.substr(line.find(" ") + 1, line.find(",") - 11)};
                lastCarLastOwner(p)->next = new owner{line.substr(0, line.find(" ")), line.substr(line.find(", ") + 2)};
            }
            else
            {
                lastCarLastOwner(p)->next = new owner{line.substr(0, line.find(" ")), line.substr(line.find(" ") + 1, line.find(",") - 11)};
                lastCarLastOwner(p)->next = new owner{line.substr(0, line.find(" ")), line.substr(line.find(", ") + 2)};
            }
        }
    }
}