/*========================================
| Toby Hansen, August 7 2025.            |
| Exceptions Lab, CSC-237-200.           |
| This program expands upon the previous |
| lab (inheritance) to catch exceptions. |
========================================*/

#include "Employee.h"
#include <string>
using namespace std;

int Employee::lastEmployeeNumberIssued=0;   // Sequential employee number

// Default constructor
Employee::Employee() {
	lastEmployeeNumberIssued++;
	employeeNumber = lastEmployeeNumberIssued;
	employeeName = "";
	hireDate = "";
}

// Constructor
Employee::Employee(string aName, string aDate) {
	lastEmployeeNumberIssued++;
	employeeNumber = lastEmployeeNumberIssued;
	employeeName = aName;
	setHireDate(aDate);
}

// Setters
void Employee::setEmployeeName(string n) { employeeName = n; }
void Employee::setHireDate(string d) { 
	if (testHireDate(d)) { hireDate = d; 
	} else { throw InvalidHireDate(d); }
}

// Getters
string Employee::getEmployeeName() const { return employeeName; }
int Employee::getEmployeeNumber() const { return employeeNumber; }
string Employee::getHireDate() const { return hireDate; }
int Employee::getLastEmployeeNumberIssued() { return lastEmployeeNumberIssued; }

// This functions tests hire date input validity.
bool Employee::testHireDate(string &d) const {
	if (d.length() == 10 && d[2] == '/' && d[5] == '/' && 
	isdigit(d[0]) && isdigit(d[1]) && isdigit(d[3]) && isdigit(d[4]) && 
	isdigit(d[6]) && isdigit(d[7]) && isdigit(d[8]) && isdigit(d[9])) {
		return true;
	}
	return false;
}