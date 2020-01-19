#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include "structures.h"

string switchArgument(string switchName, int argc, char *argv[]);

void inputMode(string line, int &mode);

car *lastCar(car *p);

void newCar(car *&p);

void getCarInfo(string line, car *&p);

plate *lastCarLastPlate(car *p);

void newPlate(string line, car *&p);

owner *lastCarLastOwner(car *p);

void newOwner(string line, car *&p);

void createRaport(car *p);

#endif