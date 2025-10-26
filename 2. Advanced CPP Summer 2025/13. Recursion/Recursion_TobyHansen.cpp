/*=====================================
| Toby Hansen, August 18 2025.        |
| Recursion Lab, CSC-237-200.         |
| This program uses a linked list to  |
| organize and manage an integer set. |
=====================================*/

#include "IntList.h"
#include <iostream>
using namespace std;

// This section is for global variables.
IntList* list = new IntList();

// This section is for declaring function prototypes.
void appendNode(); // This function appends a new node at the end of the list.
void deleteNode(); // This function deletes a node from the list.
void insertNode(); // This function insert a new node into the list (maintaining the order).
void printHelpText(); // This function displays the help text with the supported commands.

// This is the main function.
int main() {

    // This code banner is printed before the code is run.
    cout<< "/*=====================================\n"
        << "| Toby Hansen, August 18 2025.        |\n"
        << "| Recursion Lab, CSC-237-200.         |\n"
        << "| This program uses a linked list to  |\n"
        << "| organize and manage an integer set. |\n"
        << "=====================================*/\n\n";

	// This section is a command-loop repeating the program until the user decides to quit.
	char command;
	cout << "Enter command ('h' for list of supported commands): ";
	while(true) {
		command = cin.get();
		cin.ignore(10000, '\n');
		switch (command) {
			case 'a': appendNode(); break; 	// Append a new node at the end of the list.
			case 'd': deleteNode(); break; 	// Delete a value from the list.
			case 'i': insertNode(); break; 	// Insert a value into the list.
			case 'c': list->displayListLen(); break; 			// Display the count of nodes in the list.
			case 'n': list->displayListLenRecursively(); break; // Display the count of nodes in the list recursively.
			case 'm': list->displayMaxValue(); break; 			// Display the maximum list value.
			case 'l': list->displayMaxValueRecursively(); break;// Display the maximum list value recursively.
			case 't': list->displayListSum(); break; 			// Display the sum of list values.
			case 's': list->displayListSumRecursively(); break; // Display the sum of list values recursively.
			case 'p': list->printList(); break; 					// Print the list contents.
			case 'r': list->printListRecursively(); break; 			// Print the list contents recursively.
			case 'b': list->printListBackwardsRecursively(); break; // Print the list contents recursively backwards.
			case 'h': printHelpText(); break; 					// Display the help text.
			case 'q': delete list; system("pause"); return 0;	// Quit the program.
		}
		cout << "Command: ";
	}
}

// This function appends a new node at the end of the list.
void appendNode() {
	int newNum;

    // This section takes the user's input on what the int should be.
    cout << "Enter value of new node: ";
    while (!(cin >> newNum)) { // While the input is invalid:
        cin.clear(); // Clear errors.
        cin.ignore(10000, '\n'); // Ignore all remaining characters.
        cout << "Invalid input. Enter again: "; // Let the user know and ask again.
    }
	cin.ignore(10000, '\n');

	list->appendNode(newNum);
}

// This function deletes a node from the list.
void deleteNode() {
	int deleteNum;

    // This section takes the user's input on what the int should be.
    cout << "Enter value of node to delete: ";
    while (!(cin >> deleteNum)) { // While the input is invalid:
        cin.clear(); // Clear errors.
        cin.ignore(10000, '\n'); // Ignore all remaining characters.
        cout << "Invalid input. Enter again: "; // Let the user know and ask again.
    }
	cin.ignore(10000, '\n');

	list->deleteNode(deleteNum);
}

// This function insert a new node into the list (maintaining the order).
void insertNode() {
	int newNum;

    // This section takes the user's input on what the int should be.
    cout << "Enter value of new node: ";
    while (!(cin >> newNum)) { // While the input is invalid:
        cin.clear(); // Clear errors.
        cin.ignore(10000, '\n'); // Ignore all remaining characters.
        cout << "Invalid input. Enter again: "; // Let the user know and ask again.
    }
	cin.ignore(10000, '\n');

	list->insertNode(newNum);
}

// This function displays the help text with the supported commands.
void printHelpText() {
	cout<< "Supported commands: \n"
		<< "     a    Append a node to the list end.\n" 
		<< "     d    Delete a value from the list.\n" 
		<< "     i    Insert a value into the list.\n"
		<< "     c    Display the count of list nodes.\n" 
		<< "     n    Display the count of list nodes. (recursive)\n" 
		<< "     m    Display the maximum list value.\n"
		<< "     l    Display the maximum list value. (recursive)\n"
		<< "     t    Display the sum of list values.\n"
		<< "     s    Display the sum of list values. (recursive)\n"
		<< "     p    Print the contents of the list.\n"
		<< "     r    Print the contents of the list. (recursive)\n"
		<< "     b    Print the contents of the list backwards. (recursive)\n"
		<< "     h    Display the help text.\n"
		<< "     q    Quit the program.\n";
}