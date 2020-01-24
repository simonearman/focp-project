/** @file */

#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "structures.h"

/** The function checks if the user has put correct switch arguments.
@param argc number of arguments
@param argv array of arguments
@return true if the switches are correct */
bool checkSwitches(int argc, char *argv[]);

/** The function reads the program's arguments.
@param switchName name of the switch
@param argc number of arguments
@param argv array of arguments
@return argument of the switch */
std::string switchArgument(std::string switchName, int argc, char *argv[]);

/** The function finds the last car in a list.
@param p pointer to the car list
@return pointer to the last car */
car *lastCar(car *p);

/** The function adds a new car to a car list.
@param p pointer to the car list */
void newCar(car *&p);

/** The function reads a line containing car details and add details to the last car in a list.
@param line line of car details
@param p pointer to the car list */
void getCarInfo(std::string line, car *&p);

/** The function finds the last plate of the last car in a list.
@param p pointer to the car list
@return pointer to the last plate of the last car */
plate *lastCarLastPlate(car *p);

/** The function reads a line containing plate details and adds a new plate to a car list.
@param line line of plate details
@param p pointer to the car list */
void newPlate(std::string line, car *&p);

/** The function finds the last owner of the last car in a list.
@param p pointer to the car list
@return pointer to the last owner of the last car */
owner *lastCarLastOwner(car *p);

/** The function reads a line containing owner details and adds a new owner to a car list.
@param line line of owner details
@param p pointer to the car list */
void newOwner(std::string line, car *&p);

/** The function reads a line and decides what type of car details it contains.
@param line line of car details
@param mode variable which stores the type of car details */
void inputMode(std::string line, int &mode);

/** The function creates a new car, an owner or a plate to a car list, depending on the mode variable.
@param input file containing all car details
@param p pointer to the car list
@param line line of car, owner or plate details
@param mode variable which stores the type of car details */
void getInfoFromLine(std::ifstream &input, car *&p, std::string line, int &mode);

/** The function reads a owner's ownership details.
@param p pointer to the owner list
@return period of ownership */
std::string ownerPeriodOfTime(owner *p);

/** The function outputs plate details.
@param output file where the output is saved at
@param p pointer to the car list */
void outputPlatesDetails(std::ofstream &output, car *p);

/** The function outputs owner details.
@param output file where the output is saved at
@param p pointer to the car list */
void outputCarDetails(std::ofstream &output, car *p);

/** The function deletes a plate list.
@param p pointer to the plate list */
void deletePlates(plate *&p);

/** The function deletes an owner list.
@param p pointer to the owner list */
void deleteOwners(owner *&p);

/** The function deletes a car list.
@param p pointer to the car list */
void deleteCars(car *&p);

/** The function adds a new owner to a reported owners list.
@param name name of the new owner
@param p pointer to the owner list */
void newReportedOwner(std::string name, owner *&p);

/** The function creates a report of owners and their cars.
@param output file where the report is saved at
@param p pointer to the car list */
void createReport(std::ofstream &output, car *p);

#endif