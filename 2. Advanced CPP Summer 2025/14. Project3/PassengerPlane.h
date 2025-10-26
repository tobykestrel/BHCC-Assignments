// Specification file for the PassengerPlane Class (given)
#ifndef PASSENGER_PLANE_H
#define PASSENGER_PLANE_H
#include <iostream>
#include <iomanip>
#include <string>
#include "Airplane.h"
using namespace std;

class PassengerPlane : public Airplane {
private:
	int maxNumberOfPassengers;	// Maximum number of passengers

public:
	// Constructors
	PassengerPlane() : Airplane() {
		maxNumberOfPassengers = 0;
	}
	PassengerPlane(string manufacturer, string model, int yearBuilt, int flightHours, int maxNumberOfPassengers) : 
	    Airplane( manufacturer, model, yearBuilt, flightHours) {
		this->maxNumberOfPassengers = maxNumberOfPassengers;
	}

	// Destructor
	virtual ~PassengerPlane() { cout << "Destructor for PassengerPlane " << this->getAirplane_ID() << endl; }

	// Setters
	void setMaxNumberOfPassengers(int passengers);
	static PassengerPlane* addNewPassengerPlane();

	// Getters
	int getMaxNumberOfPassengers() const;
	virtual string getDescription() const;
};

#endif