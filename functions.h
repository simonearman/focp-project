#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include "structures.h"

/** The function returns true if the switches were used correctly.
@param argc number of arguments used
@param argv array of arguments used */
bool checkSwitches(int argc, char *argv[]);

/** The function returns the value provided in a switch.
@param switchName name of the switch the functions is looking for
@param argc number of arguments used
@param argv array of arguments used */
std::string switchArgument(std::string switchName, int argc, char *argv[]);

/** The function determines what type of car info is being provided in a line and changes the mode accordingly.
@param line line of input which is being tested
@param mode variable which will be changed on info type detection */
void inputMode(std::string line, int &mode);

/** The function returns the pointer to the last car of a list.
@param p pointer to the list which is being tested */
car *lastCar(car *p);

/** The function adds a new car to a list.
@param p pointer to the list to which the car is being added to */
void newCar(car *&p);

/** The function changes the car info according to the contents of the provided line.
@param line line which contains the car info
@param p pointer to the car which info is being changed */
void getCarInfo(std::string line, car *&p);

/** The function returns the pointer to the last plate of a car.
@param p pointer to the car which plates are being tested */
plate *lastCarLastPlate(car *p);

/** The function add a new plate to a car.
@param line line which contains the new plate's info
@param p pointer to the car to which the new plate is being added to */
void newPlate(std::string line, car *&p);

/** The function returns the pointer to the last owner of a car.
@param p pointer to the car which owners are being tested */
owner *lastCarLastOwner(car *p);

/** The function adds a new owner to a car.
@param line line which contains the new owner's info
@param p pointer to the car to which the new owner is being added to */
void newOwner(std::string line, car *&p);

/** The function returns the period of time when an owner had a car.
@param p pointer to the owner whose ownership is being tested */
std::string ownerPeriodOfTime(owner *p);

/** The function outputs car's plate info into a file.
@param output file which plate info is being outputed into
@param p pointer to the car which plate info is being tested */
void outputPlatesDetails(std::ofstream &output, car *p);

/** The function outputs car info into a file.
@param output file which car info is being outputed into
@param p pointer to the car which is being tested */
void outputCarDetails(std::ofstream &output, car *p);

/** The function adds an owner to a reported people list.
@param p pointer to the list to which the owner is being added to */
void addToReportedList(reportedOwners *&p);

/** The function deletes a reported people list.
@param p pointer to the list which is being deleted */
void deleteReportedList(reportedOwners *&p);

/** The function outputs all car, plate and owner info into a file.
@param output file which the info is being outputed into
@param p pointer to the car list containing the info */
void createReport(std::ofstream &output, car *p);

/** The function deletes a plate list.
@param p pointer to the plate list which is being deleted */
void deletePlates(plate *&p);

/** The function deletes an owner list.
@param p pointer to the owner list which is being deleted */
void deleteOwners(owner *&p);

/** The function deletes a car list and its plates and owners.
@param p pointer to the car list which is being deleted */
void deleteCars(car *&p);

#endif