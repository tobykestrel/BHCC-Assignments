/*========================================
| Toby Hansen, August 7 2025.            |
| Exceptions Lab, CSC-237-200.           |
| This program expands upon the previous |
| lab (inheritance) to catch exceptions. |
========================================*/

#ifndef PRODUCTION_WORKER_H
#define PRODUCTION_WORKER_H
#include "Employee.h"

class ProductionWorker : public Employee {
private:
	int shift;		// The worker's shift
	double payRate;	// The worker's hourly pay rate

	// Validity testers
	bool testShift(int &shift) const;
	bool testPayRate(double &rate) const;
public:
	// Exception classes
	class InvalidShift : public exception { 
	private:
		string message;
	public:
		// Constructor: when exception is thrown, store the invalid shift number in the message.
		InvalidShift(int &invalidShiftNum) { message = "Error: Invalid shift number: " + to_string(invalidShiftNum); }
		string msg() const { return message; }
	};

	class InvalidPayRate : public exception { 
	private:
		string message;
	public:
		// Constructor: when exception is thrown, store the invalid pay rate in the message.
		InvalidPayRate(double &invalidRate) { message = "Error: Invalid pay rate: " + to_string(invalidRate); }
		string msg() const { return message; }
	};

	// Default constructor
	ProductionWorker() : Employee() {
		shift = 0; payRate = 0.0;
	}

	// Constructor
	ProductionWorker(string aName, string aDate, int aShift, double aPayRate)
		: Employee(aName, aDate) {
		setShift(aShift);
		setPayRate(aPayRate);
	}

	// Setters
	void setShift(int s);
	void setPayRate(double r);

	// Getters
	int getShiftNumber() const;
	string getShiftName() const;
	double getPayRate() const;

	// Logic
	static ProductionWorker *createNewProductionWorker();
	void printWorkerData() const;
};

#endif