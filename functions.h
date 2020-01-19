#ifndef FUNCTIONS_H
#define FUNCTIONS_H

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

string ownerPeriodOfTime(owner *p);

void outputPlatesDetails(ofstream &output, car *p);

void outputCarDetails(ofstream &output, car *p);

void addToReportedList(reportedOwners *&p);

void createReport(std::ofstream &output, car *p);

#endif