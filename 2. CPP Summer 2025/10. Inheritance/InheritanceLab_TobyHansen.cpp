/*==========================================
| Toby Hansen, August 5 2025.              |
| Inheritance Lab, CSC-237-200.            |
| This program uses inheritance to connect |
| classes for employee view and management.|
==========================================*/

#include "ProductionWorker.h"
#include <iostream>
using namespace std;

// This section is for declaring function prototypes.
void printHelpText(); // Displays the help text.

// This is the main function.
int main() {

    // This code banner is printed before the code is run.
    cout<< "/*==========================================\n"
        << "| Toby Hansen, August 5 2025.              |\n"
        << "| Inheritance Lab, CSC-237-200.            |\n"
        << "| This program uses inheritance to connect |\n"
        << "| classes for employee view and management.|\n"
        << "==========================================*/\n\n";

	// This section is a command-loop repeating the program until the user decides to quit.
	ProductionWorker* worker;
	char command;
	cout << "Enter command ('h' for list of supported commands): ";
	while(true) {
		command = cin.get();
		cin.ignore(10000, '\n');
		switch (command) {
			case 'c': worker = ProductionWorker::createNewProductionWorker(); break; 	// Create a new ProductionWorker object.
			case 'h': printHelpText(); break; 											// Displays the Help text.
			case 'p': worker->printWorkerData(); break; 								// Print ProductionWorker information.
			case 'q': system("pause"); return 0; 										// Quits the program.
		}
		cout << "Command: ";
	}
}

// This function displays the help text with the supported commands.
void printHelpText() {
	cout<< "Supported commands: \n"
		<< "     c    Create a new ProductionWorker object.\n" 
		<< "     h    Display the help text.\n" 
		<< "     p    Print ProductionWorker information.\n" 
		<< "     q    Quit the program.\n";
}