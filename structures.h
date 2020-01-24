/** @file */

#ifndef STRUCTURES_H
#define STRUCTURES_H

struct car;

/** A plate of a singly linked list. */
struct plate
{
    std::string date;      ///< plate date
    std::string number;    ///< plate number
    plate *next = nullptr; ///< next plate in a list
};

/** An owner of a singly linked list. */
struct owner
{
    std::string date;      ///< owner date
    std::string name;      ///< owner name
    car *car;              ///< pointer to owner's car
    owner *next = nullptr; ///< next owner in a list
};

/** A car of a singly linked list. */
struct car
{
    std::string brand;             ///< car brand
    std::string model;             ///< car model
    std::string constructionYear;  ///< car year of construction
    std::string engineCapacity;    ///< car engine capacity
    std::string engineNumber;      ///< car engine number
    std::string VIN;               ///< car VIN number
    std::string firstRegistration; ///< car first registration date
    plate *plates = nullptr;       ///< pointer to car plates
    owner *owners = nullptr;       ///< pointer to car owners
    car *next = nullptr;           ///< next car in a list
};

#endif