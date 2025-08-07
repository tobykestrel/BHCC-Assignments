/*========================================
| Toby Hansen, August 7 2025.            |
| Exceptions Lab, CSC-237-200.           |
| This program expands upon the previous |
| lab (inheritance) to catch exceptions. |
========================================*/

#include "ProductionWorker.h"
#include <iostream>
using namespace std;

// Setters
void ProductionWorker::setShift(int newShift) { 
    if (testShift(newShift)) { shift = newShift; 
	} else { throw InvalidShift(newShift); }
}
void ProductionWorker::setPayRate(double newPayRate) { 
    if (testPayRate(newPayRate)) { payRate = newPayRate; 
	} else { throw InvalidPayRate(newPayRate); }
}

// Getters
int ProductionWorker::getShiftNumber() const { return shift; }
double ProductionWorker::getPayRate() const { return payRate; }

// This function returns the string representation of the shift name.
string ProductionWorker::getShiftName() const { 
    switch(shift) {
        case 1: return "Day";
        case 2: return "Night";
    } 
}

// This function tests shift input validity. 
bool ProductionWorker::testShift(int &s) const {
    if (s == 1 || s == 2) { return true; }
    return false;
}

// This function tests pay rate input validity. 
bool ProductionWorker::testPayRate(double &pr) const {
    if (pr >= 0) { return true; }
    return false;
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
    ProductionWorker* newProductionWorker = nullptr;
    while (!newProductionWorker) {
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
        
        try { newProductionWorker = new ProductionWorker(newName, newHireDate, newShift, newPayRate);
        } catch (const Employee::InvalidHireDate &e) { cout << e.msg() << endl; 
        } catch (const ProductionWorker::InvalidShift &e) { cout << e.msg() << endl; 
        } catch (const ProductionWorker::InvalidPayRate &e) { cout << e.msg() << endl; }
    }
    return newProductionWorker;
}