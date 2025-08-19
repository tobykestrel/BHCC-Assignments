/*=========================================
| Toby Hansen, August 19 2025.            |
| Project Three, CSC-237-200.         	  |
| This program uses inheritance to manage |
| and organize a fleet of varying planes. |
=========================================*/

#include "Airplane.h"
#include <string>
using namespace std;

int Airplane::last_airplane_ID_issued=0;   // Sequential plane ID

// Constructors
Airplane::Airplane() {
    last_airplane_ID_issued++;
    airplane_ID = last_airplane_ID_issued;
    manufacturer = "";
    model = "";
    yearBuilt = 0;
    flightHours = 0;
}
Airplane::Airplane(string company, string name, int year, int hours) {
    last_airplane_ID_issued++;
    airplane_ID = last_airplane_ID_issued;
    manufacturer = company;
    model = name;
    yearBuilt = year;
    flightHours = hours;
}

// Setters
void Airplane::setManufacturer(string company) { manufacturer = company; }
void Airplane::setModel(string name) { model = name; }
void Airplane::setYearBuilt(int year) { yearBuilt = year; }
void Airplane::setFlightHours(int hours) { flightHours = hours; }

// Getters
string Airplane::getManufacturer() const { return manufacturer; }
string Airplane::getModel() const { return model; }
int Airplane::getAirplane_ID() const { return airplane_ID; }
int Airplane::getYearBuilt() const { return yearBuilt; }
int Airplane::getFlightHours() const { return flightHours; }
int Airplane::get_last_airplane_ID_issued() { return last_airplane_ID_issued; }

// This function returns a string description of the plane's:
// ID, Manufacturer, Model, Year, and Hours Flown.
string Airplane::getDescription() const { 
    string desc = "ID#: " + to_string(getAirplane_ID());
    desc += ", Manufacturer: " + getManufacturer();
    desc += ", Model: " + getModel();
    desc += ", Year: " + to_string(getYearBuilt());
    desc += ", Hours: " + to_string(getFlightHours());
    return desc; 
}