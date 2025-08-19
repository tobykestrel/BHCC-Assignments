// Specification file for the Airplane class (given)
#ifndef AIRPLANE_H
#define AIRPLANE_H
#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

class Airplane {
private:
	static int last_airplane_ID_issued;   // Sequential airplane ID number value
	int airplane_ID;                      // Unique ID number for current Airplane
	string manufacturer;		          // Manufacturer name
	string model;		                  // Manufacturer's model name
	int yearBuilt;	                      // Year of Manufacture  
	int flightHours;                      // Total hours of flight.

public:
	// Constructors
	Airplane();
	Airplane(string manufacturerName, string modelName,int year, int hours);

	// Destructor
	virtual ~Airplane() { cout << "Destructor for Airplane " << airplane_ID << endl; }
	
	// Setters
	void setManufacturer(string company);
	void setModel(string name);
	void setYearBuilt(int year);
	void setFlightHours(int hours);

	// Getters
	string getManufacturer() const;
	string getModel() const;
	int getAirplane_ID() const;
	int getYearBuilt() const;
	int getFlightHours() const;
	static int get_last_airplane_ID_issued();
	virtual string getDescription() const;
};

#endif
