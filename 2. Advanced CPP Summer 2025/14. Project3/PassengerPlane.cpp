/*=========================================
| Toby Hansen, August 19 2025.            |
| Project Three, CSC-237-200.         	  |
| This program uses inheritance to manage |
| and organize a fleet of varying planes. |
=========================================*/

#include "PassengerPlane.h"
#include <string>
using namespace std;

// Setters
void PassengerPlane::setMaxNumberOfPassengers(int passengers) { maxNumberOfPassengers = passengers; }

// Getters
int PassengerPlane::getMaxNumberOfPassengers() const { return maxNumberOfPassengers; }

// This function returns a string description of the airplane's: 
// ID, Manufacturer, Model, Year, Hours Flown, and Max Passengers.
string PassengerPlane::getDescription() const { 
    string desc = "ID#: " + to_string(getAirplane_ID());
    desc += ", Manufacturer: " + getManufacturer();
    desc += ", Model: " + getModel();
    desc += ", Year: " + to_string(getYearBuilt());
    desc += ", Hours: " + to_string(getFlightHours());
    desc += ", MaxPassengers: " + to_string(getMaxNumberOfPassengers());
    return desc; 
}