/*========================================
| Toby Hansen, August 7 2025.            |
| Exceptions Lab, CSC-237-200.           |
| This program expands upon the previous |
| lab (inheritance) to catch exceptions. |
========================================*/

#ifndef EMPLOYEE_H
#define EMPLOYEE_H
#include <string>
using namespace std;

class Employee {
private:
	static int lastEmployeeNumberIssued;   // Sequential employee number
	int employeeNumber;                    // Employee number for current employee
	string employeeName;		           // Employee name
	string hireDate;	                   // Hire date

	// Validity tester
	bool testHireDate(string &d) const;
public:
	// Exception class
	class InvalidHireDate : public exception { 
	private:
		string message;
	public:
		// Constructor: when exception is thrown, store the invalid hire date in the message.
		InvalidHireDate(string &invalidHireDate) { message = "Error: Invalid Hire Date [" + invalidHireDate + "], use MM/DD/YYYY format."; }
		string msg() const { return message; }
	};

	// Constructors
	Employee();
	Employee(string aName, string aDate);
	
	// Setters
	void setEmployeeName(string n);
	void setHireDate(string date);

	// Getters
	string getEmployeeName() const;
	int getEmployeeNumber() const;
	string getHireDate() const;
	static int getLastEmployeeNumberIssued();
};

#endif
