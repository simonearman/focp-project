#include <iostream>
#include <fstream>
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

plate *lastCarLastPlate(car *p)
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
                lastCar(p)->owners = new owner{line.substr(0, line.find(" ")), line.substr(line.find(" ") + 1), lastCar(p)};
            }
            else
            {
                lastCarLastOwner(p)->next = new owner{line.substr(0, line.find(" ")), line.substr(line.find(" ") + 1), lastCar(p)};
            }
        }
        else //If there are two names
        {
            if (!lastCar(p)->owners)
            {
                lastCar(p)->owners = new owner{line.substr(0, line.find(" ")), line.substr(line.find(" ") + 1, line.find(",") - 11), lastCar(p)};
                lastCarLastOwner(p)->next = new owner{line.substr(0, line.find(" ")), line.substr(line.find(", ") + 2), lastCar(p)};
            }
            else
            {
                lastCarLastOwner(p)->next = new owner{line.substr(0, line.find(" ")), line.substr(line.find(" ") + 1, line.find(",") - 11), lastCar(p)};
                lastCarLastOwner(p)->next = new owner{line.substr(0, line.find(" ")), line.substr(line.find(", ") + 2), lastCar(p)};
            }
        }
    }
}

string ownerPeriodOfTime(owner *p)
{
    if (p->next)
        return p->date + " - " + p->next->date;
    else
        return p->date + " - now";
}

void outputPlatesDetails(ofstream &output, car *p)
{
    auto plates = p->plates;
    while (plates)
    {
        output << plates->date + " " + plates->number + "\n";
        plates = plates->next;
    }
}

void outputCarDetails(ofstream &output, car *p)
{
    output << "brand: " + p->brand + "\n";
    output << "model: " + p->model + "\n";
    output << "year of construction: " + p->constructionYear + "\n";
    output << "engine capacity: " + p->engineCapacity + "\n";
    output << "engine number: " + p->engineNumber + "\n";
    output << "VIN number: " + p->VIN + "\n";
    output << "first registration: " + p->firstRegistration + "\n";
    output << "vehicle registration plates:\n";
    outputPlatesDetails(output, p);
}

void addToReportedList(reportedOwners *&p, string name)
{
    if (!p)
    {
        p = new reportedOwners{name};
    }
    else
    {
        while (p->next)
        {
            p = p->next;
        }
        p->next = new reportedOwners{name};
    }
    
}

void createReport(ofstream &output, car *p)
{
    auto carPointer = p;
    reportedOwners *reportedPeople = nullptr;

    while (carPointer)
    {
        auto ownerPointer = carPointer->owners;

        while (ownerPointer)
        {
            auto tempReported = reportedPeople;
            while (tempReported)
            {
                if (ownerPointer->name == tempReported->name)
                    return;
                tempReported = tempReported->next;
            }

            output << "---------------- owner ----------------" << endl;
            output << ownerPointer->name + "\n";
            addToReportedList(reportedPeople, ownerPointer->name);

            auto tempPointer1 = p;

            while (tempPointer1)
            {
                auto tempPointer2 = tempPointer1->owners;

                while (tempPointer2)
                {
                    if (ownerPointer->name == tempPointer2->name)
                    {
                        output << "--- car ---\n";
                        output << "period of time: " << ownerPeriodOfTime(tempPointer2) << "\n";
                        outputCarDetails(output, tempPointer2->car);
                    }

                    tempPointer2 = tempPointer2->next;
                }

                tempPointer1 = tempPointer1->next;
            }

            ownerPointer = ownerPointer->next;
        }

        carPointer = carPointer->next;
    }
}