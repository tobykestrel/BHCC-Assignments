/*
Toby Hansen, July 17 2025.
Project 2, CSC-237-200.
ProgramExplanationLine1
ProgramExplanationLine2.
*/

#include <iostream>
#include <fstream>
using namespace std;

// This section is for declaring function prototypes.
void addParts(); // Add parts: increases the units value for an existing InventoryItem object.
void printHelpText(); // Displays the help text.
void inputInventoryData(); // Inputs inventory data from a file.
void newInventoryItem(); // Creates a new inventoryItem object.
void outputInventoryData(); // Outputs inventory data to a file.
void printInventoryList(); // Prints an inventory list on the screen.
void removeParts(); // Remove parts: reduces the units value for an existing InventoryItem object.


// This is the main function.
int main() {

    // This code banner is printed before the code is run.
    cout<< "Toby Hansen, July 16 2025.\n"
        << "Project 2, CSC-237-200.\n"
        << "headerLine3\n"
        << "headerLine4\n\n";

	// This section is a command-loop repeating the program until the user decides to quit.
	while(true) {
		switch (cin.get()) {
			case 'a': addParts(); break; // Add parts: increase the units value for an existing InventoryItem object.
			case 'h': printHelpText(); break; // Displays the Help text.
			case 'i': inputInventoryData(); break; // Input inventory data from a file.
			case 'n': newInventoryItem(); break; // Create a New inventory Item.
			case 'o': outputInventoryData(); break; // Output inventory data to a file.
			case 'p': printInventoryList(); break; // Print inventory list on the screen.
			case 'q': system("pause"); return 0; // Quits the program.
			case 'r': removeParts(); break; // Remove parts: reduce the units value for an existing InventoryItem object.
		}
	}
}

 // This function increases the units value for an existing InventoryItem object.
void addParts() {

}

// This function displays the help text.
void printHelpText() {

}

// This function inputs inventory data from a file.
void inputInventoryData() {

}

// This function creates a new inventoryItem object.
void newInventoryItem() {

}

// This function outputs inventory data to a file.
void outputInventoryData() {

}

// This function prints an inventory list on the screen.
void printInventoryList() {

}

// This function reduces the units value for an existing InventoryItem object.
void removeParts() {

}