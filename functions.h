#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include "structures.h"

string switchArgument(string switchName, int argc, char *argv[]);

void inputMode(string line, int &mode);

void newCar(car *&p);

car *lastCar(car *p);

void getCarInfo(string line, car *&p);

void newPlate(string line, car *&p);

void newOwner(string line, car *&p);

#endif