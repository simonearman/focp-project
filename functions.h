#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include "structures.h"

string switchArgument(string switchName, int argc, char *argv[]);

void newCar(car *&p);

void getCarInfo(string line, car *&p);

#endif