#ifndef STRUCTURES_H
#define STRUCTURES_H

using namespace std;

struct plate
{
    string date;
    string number;
    plate *next = nullptr;
};

struct owner
{
    string date;
    string name;
    owner *next = nullptr;
};

struct car
{
    string brand;
    string model;
    string constructionYear;
    string engineCapacity;
    string engineNumber;
    string VIN;
    string firstRegistration;
    plate plates;
    owner owners;
    car *next = nullptr;
};

#endif