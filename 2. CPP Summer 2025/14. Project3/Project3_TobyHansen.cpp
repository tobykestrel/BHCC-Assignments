/*=========================================
| Toby Hansen, August 19 2025.            |
| Project Three, CSC-237-200.         	  |
| This program uses inheritance to manage |
| and organize a fleet of varying planes. |
=========================================*/

#include "Airplane.h"
#include "CargoPlane.h"
#include "PassengerPlane.h"
#include <iostream>
#include <vector>
using namespace std;

// This section is for global variables.
vector<Airplane*> fleet; 

// This section is for declaring function prototypes.
void addPlane(); 		// This function adds a new plane to the fleet.
void removePlane(); 	// This function removes a plane from the fleet.
void flyPlane(); 		// This function flies a plane.
void printFleet(); 		// This function displays the current fleet information.
void printHelpText(); 	// This function displays the help text with the supported commands.

// This is the main function.
int main() {

    // This code banner is printed before the code is run.
    cout<< "/*=========================================\n"
        << "| Toby Hansen, August 19 2025.            |\n"
        << "| Project Three, CSC-237-200.         	  |\n"
        << "| This program uses inheritance to manage |\n"
        << "| and organize a fleet of varying planes. |\n"
        << "=========================================*/\n\n";

	// This section is a command-loop repeating the program until the user decides to quit.
	char command;
	cout << "Enter command ('h' for list of supported commands): ";
	while(true) {
		command = cin.get();
		cin.ignore(10000, '\n');
		switch (command) {
			case 'a': addPlane(); break; 		// Add a new plane to the fleet.
			case 'f': flyPlane(); break; 		// Fly a plane in the fleet.
			case 'h': printHelpText(); break; 	// Print the help text.
			case 'p': printFleet(); break; 		// Print current fleet information.
			case 'q': system("pause"); return 0;// Quit the program.
			case 'r': removePlane(); break; 	// Remove a plane from the fleet.
		}
		cout << "Command: ";
	}
}

// This function adds a new plane to the fleet.
void addPlane() {
	
    // This section takes the user's input on what type the plane is.
	char type;
	do {
    	cout << "Specify type of plane to be added (c=cargo,p=passenger): ";
		type = cin.get();
		cin.ignore(10000, '\n');
	} while (type != 'c' && type != 'p');

    // This section takes the user's input on what the manufacturer of the plane is.
	string manufacturer;
    cout << "Enter the Manufacturer: ";
    getline(cin, manufacturer);
	
    // This section takes the user's input on what the model of the plane is.
	string model;
    cout << "Enter the Model: ";
    getline(cin, model);

    // This section takes the user's input on what year the plane was built in.
	int yearBuilt;
    cout << "Enter the year the plane was built in: ";
    while (!(cin >> yearBuilt)) {
        cin.clear();  cin.ignore(10000, '\n');
        cout << "Invalid input. Enter again: ";
    } cin.ignore(10000, '\n');

    // This section takes the user's input on the total amount of hours the plane has flown.
	int hoursFlown;
    cout << "Enter the total amount of hours the plane has flown: ";
    while (!(cin >> hoursFlown)) {
        cin.clear();  cin.ignore(10000, '\n');
        cout << "Invalid input. Enter again: ";
    } cin.ignore(10000, '\n');

	// This section acquires the type-specific variables and then adds the new plane to the fleet.
	if (type == 'c') { // If the type is cargo, the user's input is taken on the max weight the cargo plane can carry.
		int maxCargoWeight;
		cout << "Enter the total amount of weight the cargo plane can carry: ";
		while (!(cin >> maxCargoWeight)) {
			cin.clear();  cin.ignore(10000, '\n');
			cout << "Invalid input. Enter again: ";
		} cin.ignore(10000, '\n'); 
		fleet.push_back(new CargoPlane(manufacturer, model, yearBuilt, hoursFlown, maxCargoWeight));
	} else if (type == 'p') { // If the type is passenger, the user's input is taken on the max passengers the plane can carry.
		int maxPassengers;
		cout << "Enter the total amount of passengers the plane can carry: ";
		while (!(cin >> maxPassengers)) {
			cin.clear();  cin.ignore(10000, '\n');
			cout << "Invalid input. Enter again: "; 
		} cin.ignore(10000, '\n');
		fleet.push_back(new PassengerPlane(manufacturer, model, yearBuilt, hoursFlown, maxPassengers));
	}
	cout << "New plane: " << fleet[fleet.size()-1]->getDescription() << "\nSize of fleet: " << fleet.size() << endl;
}

// This function removes a plane from the fleet.
void removePlane() {

    // This section takes the user's input on what the ID of the plane to be removed is.
	int planeID;
    cout << "Enter the ID of the plane to remove: ";
    while (!(cin >> planeID)) { // While the input is invalid:
        cin.clear();  cin.ignore(10000, '\n'); // Clear errors and ignore any remaining characters.
        cout << "Invalid input. Enter again: "; // Let the user know and ask again.
    } cin.ignore(10000, '\n'); // After valid input is given, ignore any remaining characters.

	// If a plane with the specified ID can be found, remove it. Otherwise, tell the user.
	for (int i = 0; i < fleet.size(); i++) {
		if (fleet[i]->getAirplane_ID() == planeID) { 
			string desc = fleet[i]->getDescription();
			delete fleet[i]; 
			fleet.erase(fleet.begin() + i);
			cout << "Removal complete: Airplane [" << desc << "] has been removed.\n";
			return; 
		}
	}
	cout << "ERROR: A plane with the specified ID could not be found.\n";
}

// This function flies a plane.
void flyPlane() {

    // This section takes the user's input on what the ID of the plane to fly is.
	int planeID;
    cout << "Enter the ID of the plane to fly: ";
    while (!(cin >> planeID)) { // While the input is invalid:
        cin.clear();  cin.ignore(10000, '\n'); // Clear errors and ignore any remaining characters.
        cout << "Invalid input. Enter again: "; // Let the user know and ask again.
    } cin.ignore(10000, '\n'); // After valid input is given, ignore any remaining characters.
	
    // This section takes the user's input on how long the plane is flown.
	int hours;
    cout << "Enter the hours the plane was flown: ";
    while (!(cin >> hours)) { // While the input is invalid:
        cin.clear();  cin.ignore(10000, '\n'); // Clear errors and ignore any remaining characters.
        cout << "Invalid input. Enter again: "; // Let the user know and ask again.
    } cin.ignore(10000, '\n'); // After valid input is given, ignore any remaining characters.

	// If a plane with the specified ID can be found, fly it. Otherwise, tell the user.
	for (int i = 0; i < fleet.size(); i++) {
		if (fleet[i]->getAirplane_ID() == planeID) {
			cout << "Choosing Airplane: [" << fleet[i]->getDescription() << "]\n";
			fleet[i]->setFlightHours(fleet[i]->getFlightHours() + hours); 
			cout << "Flight  Completed: [" << fleet[i]->getDescription() << "]\n";
			return; 
		}
	}
	cout << "ERROR: A plane with the specified ID '" << planeID << "' could not be found.\n";
	
}

// This function displays the current fleet information.
void printFleet() {
	cout << "Current fleet contains " << fleet.size() << " airplane(s):\n";
	for (int i = 0; i < fleet.size(); i++) {
		cout << fleet[i]->getDescription() << endl;
	}
}

// This function displays the help text with the supported commands.
void printHelpText() {
	cout<< "Supported commands: \n"
		<< "     a    Add a new plane to the fleet.\n" 
		<< "     f    Fly a plane in the fleet.\n" 
		<< "     h    Print the help text.\n"
		<< "     p    Print current fleet information.\n" 
		<< "     q    Quit the program.\n" 
		<< "     r    Remove a plane from the fleet.\n";
}