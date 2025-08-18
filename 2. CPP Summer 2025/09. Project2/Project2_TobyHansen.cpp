/*=======================================
| Toby Hansen, July 31 2025.            |
| Project 2, CSC-237-200.               |
| This program allows the user to view  |
| and manage an inventory and its items.|
=======================================*/

#include "InventoryItem.h"
#include <iomanip>
#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

// This section is for declaring function prototypes.
void addParts(); // Add parts: increases the units value for an existing InventoryItem object.
void printHelpText(); // Displays the help text.
void inputInventoryData(); // Inputs inventory data from a file.
void newInventoryItem(); // Creates a new inventoryItem object.
void outputInventoryData(); // Outputs inventory data to a file.
void printInventoryList(); // Prints an inventory list on the screen.
void removeParts(); // Remove parts: reduces the units value for an existing InventoryItem object.
int splitLineToArray(string inputText, string inputDelim, string outputFieldArray[], int maxFields);

// Global Vector Variable
vector<InventoryItem> inventory;
const int maxParts = 30;

// This is the main function.
int main() {

    // This code banner is printed before the code is run.
    cout<< "=========================================\n"
        << "| Toby Hansen, July 31 2025.            |\n"
        << "| Project 2, CSC-237-200.               |\n"
        << "| This program allows the user to view  |\n"
        << "| and manage an inventory and its items.|\n"
        << "=========================================\n\n";

	// This section is a command-loop repeating the program until the user decides to quit.
	while(true) {
		cout << "Command: ";
		char command = cin.get();
		cin.ignore(10000, '\n');
		switch (command) {
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

// This function increases the units for an existing inventory item.
void addParts() {

	// This section gets the desired item number from the user.
	int itemNumber;
	cout << "Specify the desired item number: ";
	if (!(cin >> itemNumber) || itemNumber < 0 || itemNumber > inventory.size()-1) {
        cin.clear(); // Clear errors.
        cin.ignore(10000, '\n'); // Ignore all remaining characters.
		cout << "Error: Specified item number is not in use.";
		return;
	}
	cin.ignore(10000, '\n');

	// This section gets the desired amount of parts to be added from the user, and adds them.
	int addedPartsAmount;
	int currentUnits = inventory[itemNumber].getUnits();
	cout << "Specify the amount of parts to add: ";
	while (!(cin >> addedPartsAmount) || addedPartsAmount < 0 || currentUnits + addedPartsAmount > maxParts) {
		cin.clear(); // Clear errors.
		cin.ignore(10000, '\n'); // Ignore all remaining characters.
		cout << "Specified amount of parts is out of range (0-" << maxParts - inventory[itemNumber].getUnits() << ").\nSpecify the amount of parts to add: ";
	}
	cin.ignore(10000, '\n');
	inventory[itemNumber].setUnits(currentUnits + addedPartsAmount);
}

// This function displays the help text with the supported commands.
void printHelpText() {
	cout<< "Supported commands: \n"
		<< "     a    Add parts: increase the units value for an existing InventoryItem object.\n" 
		<< "     h    Displays the Help text.\n" 
		<< "     i    Input inventory data from a file\n" 
		<< "     n    Create a New inventory Item.\n" 
		<< "     o    Output inventory data to a file.\n" 
		<< "     p    Print inventory list on the screen.\n" 
		<< "     q    Quits the program.\n" 
		<< "     r    Remove parts: reduce the units value for an existing InventoryItem object.\n\n";
}

// This function inputs inventory data from a file.
void inputInventoryData() {

	// This section opens the file for reading from.
    ifstream inputFile;
    string filename;
	cout << "Enter name of input file: ";
    getline(cin, filename);
	inputFile.open(filename);
    while (!inputFile) { // If the file couldn't be opened:
        cout << "Error opening file! Enter name of input file: "; // Let the user know and try again.
		getline(cin, filename);
		inputFile.open(filename);
    }

    // This section reads each line for processing into the inventory vector.
    string line, lineAsArray[4];
	int recordsLoaded = 0;
    while (getline(inputFile, line)) {
		if (splitLineToArray(line, "|", lineAsArray, 4) == 4) {
			recordsLoaded++;
			InventoryItem newInvItem(lineAsArray[1], stod(lineAsArray[2]), stoi(lineAsArray[3]));
			inventory.push_back(newInvItem);
		}
    }

    // This section closes the file and tells the user how many records were loaded.
    inputFile.close();
	cout << recordsLoaded << " records loaded to array.\n";
}

// This function creates a new inventory item.
void newInventoryItem() {

	// This section gets the description for the new item.
	cout << "Specify the description of the new item: ";
	string description;
	getline(cin, description);

	// This section gets the unit cost for the new item.
	cout << "Specify the unit cost of the new item: ";
	double cost;
	while (!(cin >> cost) || cost < 0) {
		cin.clear(); // Clear errors.
		cin.ignore(10000, '\n'); // Ignore all remaining characters.
		cout << "Specified unit cost is invalid.\nSpecify the unit cost of the new item: ";
	}
	cin.ignore(10000, '\n');

	// This section gets the initial quantity for the new item.
	cout << "Specify the initial quantity of the new item: ";
	int units;
	while (!(cin >> units) || units < 0 || units > maxParts) {
		cin.clear(); // Clear errors.
		cin.ignore(10000, '\n'); // Ignore all remaining characters.
		cout << "Specified initial quantity is out of range (0-" << maxParts << ").\nSpecify the initial quantity of the new item: ";
	}
	cin.ignore(10000, '\n');

	// This section adds the new inventory item and announces it to the user.
	InventoryItem newInvItem(description, cost, units);
	inventory.push_back(newInvItem);
	cout << "Announcing a new inventory Item: " << description << "\nWe now have " << inventory.size() << " different inventory items in stock!\n";
}

// This function outputs the inventory data to a file.
void outputInventoryData() {

	// This section opens the file for writing to.
    ofstream outputFile;
    string filename;
	cout << "Enter name of output file: ";
    getline(cin, filename);
	outputFile.open(filename);
    while (!outputFile) { // If the file couldn't be opened:
        cout << "Error opening file! Enter name of output file: "; // Let the user know and try again.
		getline(cin, filename);
		outputFile.open(filename);
    }

	// This section writes the inventory data to the specified output file.
    for (int i = 0; i < inventory.size(); i++) {
		outputFile << i << "|" << inventory[i].getDescription() << "|" << inventory[i].getCost() << "|" << inventory[i].getUnits() << endl;
    }

    // This section closes the file and tells the user how many records were loaded.
    outputFile.close();
	cout << inventory.size() << " records written to file.\n";
}

// This function prints the inventory list to the console.
void printInventoryList() {

	// This section outputs the file header and line seperation.
    cout<< setw(5) << "  #  " 
        << setw(50) << left << "Description" 
        << setw(8) << right << "  Cost  " 
        << setw(8) << "  Units " << endl
		<< setw(5) << " ___ " 
        << setw(50) << left << "________________" 
        << setw(8) << right << " ______ " 
        << setw(8) << " ______ " << endl;

    for (int i = 0; i < inventory.size(); i++) {
		cout<< setw(3) << i << "  " 
			<< setw(50) << left << inventory[i].getDescription() 
			<< setw(6) << right << fixed << setprecision(2) << inventory[i].getCost() << "  "
			<< setw(6) << fixed << setprecision(0) << inventory[i].getUnits() << endl;
    }
	cout << inventory.size() << " records.\n";
}

// This function reduces the units for an existing inventory item.
void removeParts() {

	// This section gets the desired item number from the user.
	int itemNumber;
	cout << "Specify the desired item number: ";
	if (!(cin >> itemNumber) || itemNumber < 0 || itemNumber > inventory.size()-1) {
        cin.clear(); // Clear errors.
        cin.ignore(10000, '\n'); // Ignore all remaining characters.
		cout << "Error: Specified item number is not in use.";
		return;
	}
	cin.ignore(10000, '\n');

	// This section gets the desired amount of parts to be removed from the user, and removes them.
	int removedPartsAmount;
	int currentUnits = inventory[itemNumber].getUnits();
	cout << "Specify the amount of parts to remove: ";
	while (!(cin >> removedPartsAmount) || removedPartsAmount < 0 || currentUnits - removedPartsAmount < 0) {
		cin.clear(); // Clear errors.
		cin.ignore(10000, '\n'); // Ignore all remaining characters.
		cout << "Specified amount of parts is out of range (0-" << inventory[itemNumber].getUnits() << ").\nSpecify the amount of parts to remove: ";
	}
	cin.ignore(10000, '\n');
	inventory[itemNumber].setUnits(currentUnits - removedPartsAmount);
}

/* ============================================================================
*  Function: splitLineToArray - Scan through one line of text, output fields to array.
*  Inputs:
*      inputText =  string containing one line of text.
*      inputDelim = string containing the delimiter character
*                       (separates one data field from the next).
*      maxFields =  Maximum number of fields
*  Outputs:
*      returns the number of fields found.
*      outputFieldArray[] = array of strings containing output fields
*
*  Desciption:
*      Starting at the beginning of the inputText string, scan for each
*      occurrence of the inputDelimiter character/string.  The first data field begins
*      at the starting position and ends at the position before the delimiter.
*      The SECOND data field begins at the position AFTER the delimiter, and
*      extends to the position before the NEXT ocurrence of the delimiter.
*      If no delimiter is found, then the current data field extends to the
*      end of the line.
* 
*      The function that CALLS splitLineToArray determines what the delimiter 
*      is, and passes it to the function in the 
*                 string inputDelim
*      parameter.  The inputDelim string may have a string length of 
*      1 or some value greater than 1.  The inputDelim parameter must 
*      NOT be the empty string.
*---------------------------------------------------------------------------*/

int splitLineToArray(string inputText, string inputDelim, string outputFieldArray[], int maxFields) {
	//	Local Variables:
	size_t nextFieldPosition = 0;	//	Start position of data field.
	size_t foundPosition;			//  Position where delimiter was found,
	int fieldCount = 0;		        //  Number of data fields found so far,
	bool endOfLine = false;			//	Flag -- end of input line detected,
	string dataField;				//  Copy of the data field.

	if (inputDelim == "") {
		cout << "ERROR(splitLineToArray): the inputDelim parameter must NOT be the empty string." << endl;
		return 0;
	}
	while (!endOfLine) {
		foundPosition = inputText.find(inputDelim, nextFieldPosition);
		if (foundPosition != string::npos) {
			// (Here if 'inputDelim' was found in the input string.)
			// Copy the data field contents from the input string to the
			// 'dataField' local variable.
			dataField = inputText.substr(nextFieldPosition, foundPosition - nextFieldPosition);
			fieldCount++;

			// Adjust 'nextFieldPosition' as preparation for finding NEXT delimiter.
			nextFieldPosition = foundPosition + inputDelim.length();
		} else {
			// (Here if the string 'find' function reached the end of the input 
			// string WITHOUT finding the inputDelim value.)
			endOfLine = true;   // (The "while-loop" will not repeat again.)

			// Set foundPosition to the LENGTH of the original inputText, to handle
			// the case where there is more text AFTER the last occurrence of the 
			// inputDelim string.
			foundPosition = inputText.length();

			// If there is text to output to the caller, use the substr function
			// (in the string class) to copy that text to the dataField local 
			// variable, and increment the fieldCount local variable.
			if (foundPosition > nextFieldPosition) {
				dataField = inputText.substr(nextFieldPosition, foundPosition - nextFieldPosition);
				fieldCount++;
			}
		}
		if (fieldCount > 0) {
			if (fieldCount > maxFields) {
				cout << "ERROR at line __LINE__: too many input fields, fieldCount=" << fieldCount << endl;
			} else {
				outputFieldArray[fieldCount - 1] = dataField;
			}
		}
	}
	return fieldCount;
}