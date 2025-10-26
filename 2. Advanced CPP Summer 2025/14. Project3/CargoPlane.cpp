/*=========================================
| Toby Hansen, August 19 2025.            |
| Project Three, CSC-237-200.         	  |
| This program uses inheritance to manage |
| and organize a fleet of varying planes. |
=========================================*/

#include "CargoPlane.h"
#include <string>
using namespace std;

// Setters
void CargoPlane::setMaxCargoWeight(int weight) { maxCargoWeight = weight; }

// Getters
int CargoPlane::getMaxCargoWeight() const { return maxCargoWeight; }

// This function returns a string description of the airplane's: 
// ID, Manufacturer, Model, Year, Hours Flown, and Max Cargo Weight.
string CargoPlane::getDescription() const { 
    string desc = "ID#: " + to_string(getAirplane_ID());
    desc += ", Manufacturer: " + getManufacturer();
    desc += ", Model: " + getModel();
    desc += ", Year: " + to_string(getYearBuilt());
    desc += ", Hours: " + to_string(getFlightHours());
    desc += ", MaxCargoWeight: " + to_string(getMaxCargoWeight());
    return desc; 
}