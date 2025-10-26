/*==========================================
| Toby Hansen, August 5 2025.              |
| Inheritance Lab, CSC-237-200.            |
| This program uses inheritance to connect |
| classes for employee view and management.|
==========================================*/

#include "ProductionWorker.h"
#include <iostream>
using namespace std;

// Setter functions
void ProductionWorker::setShift(int newShift) { shift = newShift; }
void ProductionWorker::setPayRate(double newPayRate) { payRate = newPayRate; }

// Getter functions
int ProductionWorker::getShiftNumber() const { return shift; }
double ProductionWorker::getPayRate() const { return payRate; }

// This function returns the string representation of the shift name.
string ProductionWorker::getShiftName() const { 
    switch(shift) {
        case 1: return "Day";
        case 2: return "Night";
    } 
}

// This function prints the worker's data.
void ProductionWorker::printWorkerData() const {
    cout<< "Name: " << getEmployeeName() << endl
        << "Employee number: " << getEmployeeNumber() << endl
        << "Hire Date: " << getHireDate() << endl
        << "Shift: " << getShiftName() << endl
        << "Shift number: " << getShiftNumber() << endl
        << "Pay rate: " << getPayRate() << endl;
}

// This function creates and returns a new production worker.
ProductionWorker* ProductionWorker::createNewProductionWorker() {
    string newName, newHireDate;
    int newShift;
    double newPayRate;
		
    // This section takes the user's input on what the string should be.
    cout << "Enter name of new employee: ";
    getline(cin, newName);
		
    // This section takes the user's input on what the string should be.
    cout << "Enter hire date of new employee: ";
    getline(cin, newHireDate);

    // This section takes the user's input on what the int should be.
    cout << "Enter shift for new employee (1=day, 2=night): ";
    while (!(cin >> newShift)) { // While the input is invalid:
        cin.clear(); // Clear errors.
        cin.ignore(10000, '\n'); // Ignore all remaining characters.
        cout << "Invalid input. Enter again: "; // Let the user know and ask again.
    }
	cin.ignore(10000, '\n');

    // This section takes the user's input on what the pay rate should be.
    cout << "Enter hourly pay rate for new employee: ";
    while (!(cin >> newPayRate)) { // While the input is invalid:
        cin.clear(); // Clear errors.
        cin.ignore(10000, '\n'); // Ignore all remaining characters.
        cout << "Invalid input. Enter again: "; // Let the user know and ask again.
    }
	cin.ignore(10000, '\n');

    ProductionWorker* newProductionWorker = new ProductionWorker(newName, newHireDate, newShift, newPayRate);
    return newProductionWorker;
}