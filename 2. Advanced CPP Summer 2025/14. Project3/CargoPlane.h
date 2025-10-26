// Specification file for the CargoPlane Class (given)
#ifndef CARGO_PLANE_H
#define CARGO_PLANE_H
#include <iostream>
#include <iomanip>
#include <string>
#include "Airplane.h"
using namespace std;

class CargoPlane : public Airplane {
private:
	int maxCargoWeight;		// Maximum weight of cargo

public:
	// Constructors
	CargoPlane() : Airplane() {
		maxCargoWeight = 0;
	}
	CargoPlane(string manufacturer, string model, int yearBuilt, int flightHours, int maxCargoWeight) : 
	    Airplane( manufacturer, model, yearBuilt, flightHours) {
		this->maxCargoWeight = maxCargoWeight;
	}

	// Destructor
	virtual ~CargoPlane() { cout << "Destructor for CargoPlane " << this->getAirplane_ID() << endl; }

	// Setters
	void setMaxCargoWeight(int s);
	static CargoPlane* addNewCargoPlane();

	// Getters
	int getMaxCargoWeight() const;
	virtual string getDescription() const;
};

#endif