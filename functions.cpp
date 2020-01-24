#include <iostream>
#include <fstream>
#include "structures.h"
#include "functions.h"

using namespace std;

bool checkSwitches(int argc, char *argv[])
{
    bool foundI = false;
    bool foundO = false;
    for (int i = 0; i < argc; i ++)
    {
        string argument = argv[i];
        if (argument == "-i")
        {
            foundI = true;
            i++;
        }
        if (argument == "-o")
        {
            foundO = true;
            i++;
        }
    }

    if (!foundI || !foundO)
        return false;

    return true;
}

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
        string date = line.substr(0, line.find(" "));
        string number = line.substr(line.find(" ") + 1);
        if (!lastCar(p)->plates)
        {
            lastCar(p)->plates = new plate{date, number};
        }
        else
        {
            lastCarLastPlate(p)->next = new plate{date, number};
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
            string date = line.substr(0, line.find(" "));
            string name = line.substr(line.find(" ") + 1);
            if (!lastCar(p)->owners)
            {
                lastCar(p)->owners = new owner{date, name, lastCar(p)};
            }
            else
            {
                lastCarLastOwner(p)->next = new owner{date, name, lastCar(p)};
            }
        }
        else //If there are two names
        {
            string date = line.substr(0, line.find(" "));
            string name1 = line.substr(line.find(" ") + 1, line.find(",") - 11);
            string name2 = line.substr(line.find(", ") + 2);
            if (!lastCar(p)->owners)
            {
                lastCar(p)->owners = new owner{date, name1, lastCar(p)};
                lastCarLastOwner(p)->next = new owner{date, name2, lastCar(p)};
            }
            else
            {
                lastCarLastOwner(p)->next = new owner{date, name1, lastCar(p)};
                lastCarLastOwner(p)->next = new owner{date, name2, lastCar(p)};
            }
        }
    }
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

void getInfoFromLine(ifstream &input, car *&p, string line, int &mode)
{
    inputMode(line, mode);
    switch (mode)
    {
    case 1: //Line indicates there is a new car
        newCar(p);
        break;
    case 2: //Line contains car info
        getCarInfo(line, p);
        break;
    case 3: //Line contains plate info
        newPlate(line, p);
        break;
    case 4: //Line contains owner info
        newOwner(line, p);
        break;
    }
}

string ownerPeriodOfTime(owner *p)
{
    if (p->next)
    {
        if (p->date != p->next->date)
        {
            return p->date + " - " + p->next->date;
        }
        return ownerPeriodOfTime(p->next);
    }
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

void deletePlates(plate *&p)
{
    if (p)
    {
        deletePlates(p->next);
        delete p;
        p = nullptr;
    }
}

void deleteOwners(owner *&p)
{
    if (p)
    {
        deleteOwners(p->next);
        delete p;
        p = nullptr;
    }
}

void deleteCars(car *&p)
{
    if (p)
    {
        deletePlates(p->plates);
        deleteOwners(p->owners);
        deleteCars(p->next);
        delete p;
        p = nullptr;
    }
}

void newReportedOwner(string name, owner *&p)
{
    if (!p)
    {
        p = new owner{"", name};
    }
    else
    {
        auto pointer = p;
        while (pointer->next)
            pointer = pointer->next;
        pointer->next = new owner{"", name};
    }
}

void createReport(ofstream &output, car *p)
{
    auto carPointer = p;
    owner *reportedPeople = nullptr;

    while (carPointer)
    {
        auto ownerPointer = carPointer->owners;

        while (ownerPointer)
        {
            bool found = false;
            auto temp = reportedPeople;

            while (temp)
            {
                if (ownerPointer->name == temp->name)
                    found = true;
                temp = temp->next;
            }

            if (!found)
            {
                output << "---------------- owner ----------------" << endl;
                output << ownerPointer->name + "\n";
                newReportedOwner(ownerPointer->name, reportedPeople);

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
            }
            ownerPointer = ownerPointer->next;
        }
        carPointer = carPointer->next;
    }
    deleteOwners(reportedPeople);
}