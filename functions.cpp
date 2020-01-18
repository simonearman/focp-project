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

int inputMode(string line, int mode)
{
    if (line.find("--- car ---") == 0)
        return 1;
    else if (mode == 1)
        mode = 2;
    else if (line.find("vehicle registration plate") == 0)
        return 3;
    else if (line.find("owner") == 0)
        return 4;
    return mode;
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
    if (p)
    {
        auto pointer = p;

        while (pointer->next)
        {
            pointer = pointer->next;
        }

        if (line.rfind("brand", 0) == 0)
        {
            pointer->brand = line.substr(line.rfind(" "));
        }
        else if (line.rfind("model", 0) == 0)
        {
            pointer->model = line.substr(line.rfind(" "));
        }
        else if (line.rfind("year of construction", 0) == 0)
        {
            pointer->constructionYear = line.substr(line.rfind(" "));
        }
        else if (line.rfind("engine capacity", 0) == 0)
        {
            pointer->engineCapacity = line.substr(line.rfind(" "));
        }
        else if (line.rfind("engine number", 0) == 0)
        {
            pointer->engineNumber = line.substr(line.rfind(" "));
        }
        else if (line.rfind("VIN number", 0) == 0)
        {
            pointer->VIN = line.substr(line.rfind(" "));
        }
        else if (line.rfind("first registration", 0) == 0)
        {
            pointer->firstRegistration = line.substr(line.rfind(" "));
        }
    }
}

void newPlate(string line, car *&p)
{
    if (p && line.find("vehicle registration plate") != 0)
    {
        auto pointer = p;

        while (pointer->next)
        {
            pointer = pointer->next;
        }

        if (pointer->plates.date == "" && pointer->plates.number == "")
        {
            pointer->plates.date = line.substr(0, line.find(" "));
            pointer->plates.number = line.substr(line.find(" "));
            return;
        }

        auto pointer2 = pointer->plates.next;

        while (pointer2->next)
        {
            pointer2 = pointer2->next;
        }

        pointer2->next = new plate{line.substr(0, line.find(" ")), line.substr(line.find(" "))};
    }
}

void newOwner(string line, car *&p) //Works only for max 2 owners in the same line
{
    if (p && line.find("owner") != 0)
    {
        auto pointer = p;

        while (pointer->next)
        {
            pointer = pointer->next;
        }

        if (line.find(",") == string::npos) //Checks if there is only one name
        {
            if (pointer->owners.date == "" && pointer->owners.name == "")
            {
                pointer->owners.date = line.substr(0, line.find(" "));
                pointer->owners.name = line.substr(line.find(" "));
                return;
            }

            auto pointer2 = pointer->owners.next;

            while (pointer2->next)
            {
                pointer2 = pointer2->next;
            }

            pointer2->next = new owner{line.substr(0, line.find(" ")), line.substr(line.find(" "))};
            return;
        }

        //If there are two names
        if (pointer->owners.date == "" && pointer->owners.name == "")
        {
            pointer->owners.date = line.substr(0, line.find(" "));
            pointer->owners.name = line.substr(line.find(" "), line.find(",")-11);

            pointer->owners.next->date = line.substr(0, line.find(" "));
            pointer->owners.next->name = line.substr(line.rfind(" "));
            return;
        }

        auto pointer2 = pointer->owners.next;

        while (pointer2->next)
        {
            pointer2 = pointer2->next;
        }

        pointer2->next = new owner{line.substr(0, line.find(" ")), line.substr(line.find(" "), line.find(",") - 11)};
        pointer2->next->next = new owner{line.substr(0, line.find(" ")), line.substr(line.find(" "), line.find(",") - 11)};
    }
}