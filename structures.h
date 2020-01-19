#ifndef STRUCTURES_H
#define STRUCTURES_H

struct car;

struct plate
{
    std::string date;
    std::string number;
    plate *next = nullptr;
};

struct owner
{
    std::string date;
    std::string name;
    car *car;
    owner *next = nullptr;
};

struct car
{
    std::string brand;
    std::string model;
    std::string constructionYear;
    std::string engineCapacity;
    std::string engineNumber;
    std::string VIN;
    std::string firstRegistration;
    plate *plates = nullptr;
    owner *owners = nullptr;
    car *next = nullptr;
};

struct reportedOwners
{
    std::string name;
    reportedOwners *next = nullptr;
};

#endif