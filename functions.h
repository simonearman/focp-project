#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "structures.h"

bool checkSwitches(int argc, char *argv[]);

std::string switchArgument(std::string switchName, int argc, char *argv[]);

void inputMode(std::string line, int &mode);

car *lastCar(car *p);

void newCar(car *&p);

void getCarInfo(std::string line, car *&p);

plate *lastCarLastPlate(car *p);

void newPlate(std::string line, car *&p);

owner *lastCarLastOwner(car *p);

void newOwner(std::string line, car *&p);

std::string ownerPeriodOfTime(owner *p);

void outputPlatesDetails(std::ofstream &output, car *p);

void outputCarDetails(std::ofstream &output, car *p);

void addToReportedList(reportedOwners *&p);

void deleteReportedList(reportedOwners *&p);

void createReport(std::ofstream &output, car *p);

void deletePlates(plate *&p);

void deleteOwners(owner *&p);

void deleteCars(car *&p);

#endif