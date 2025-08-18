/*
Toby Hansen, July 10 2025.
Pointers Lab, CSC-237-200.
This program uses pointers as function paramters
for arrays and uses dynamic memory allocation.
*/

#include <iostream>
#include <iomanip>
using namespace std;

// This section is for declaring function prototypes.
void populateIntegerArray(int *arr, int arraySize);
void displayIntegerArray(int *arr, int arraySize);
int findMaximumValue(int *arr, int arraySize);

// This is the main function.
int main() {

    // This code banner is printed before the code is run.
    cout<< "Toby Hansen, July 10 2025.\n"
        << "Pointers Lab, CSC-237-200.\n"
        << "This program uses pointers as function paramters\n"
        << "for arrays and uses dynamic memory allocation.\n\n";

    // This section takes a user's input for the desired array size (>1).
    int arraySize;
    cout << "Enter desired array size: ";
    while (!(cin >> arraySize) || arraySize < 2) { // While the input is invalid:
        cin.clear(); // Clear the buffer.
        cin.ignore(10000, '\n'); // Ignore all remaining characters.
        cout << "Invalid input. Enter again: "; // Let the user know and ask again.
    }

	// This section dynamically allocates an int array of the desired size.
	int* arr = new int[arraySize];
	cout << "arrayPtr = " << setw(16) << setfill('0') << hex << uppercase << (unsigned long long)arr << endl;

	// This section calls the functions to populate and display the array, then prints the highest int.
	populateIntegerArray(arr, arraySize);
	displayIntegerArray(arr, arraySize);
	cout << "Maximum integer in array is: " << dec << findMaximumValue(arr, arraySize) << endl;

	// This section frees the memory allocated for the array.
	cout << "DELETING array at arrayPtr = " << setw(16) << setfill('0') << hex << uppercase << (unsigned long long)arr << endl;
	delete[] arr; 

    // Finishes up the program.
    system("pause"); // Wait for user input.
    return 0; // End the program
}

// This function populates an integer array with the given arraySize amount.
// Two paramaters are taken, an int pointer array, and an int of the array's size.
void populateIntegerArray(int *arr, int arraySize) {
	for (int i = 0; i < arraySize; i++) {
		cout << "Enter value for array element " << i << ": ";
		while (!(cin >> arr[i])) { // While the input is invalid:
			cin.clear(); // Clear the buffer.
			cin.ignore(10000, '\n'); // Ignore all remaining characters.
			cout << "Invalid input. Enter again: "; // Let the user know and ask again.
		}
	}
}

// This function displays each item in an integer array.
// Two paramaters are taken, an int pointer array, and an int of the array's size.
void displayIntegerArray(int *arr, int arraySize) {
	for (int i = 0; i < arraySize; i++) {
		cout << setw(16) << setfill('0') << hex << uppercase << (unsigned long long)(size_t)&arr[i]; 	// Array item pointer.
		cout << ": arrayPtr[" << setfill(' ') << dec << i << "] = " << setw(10) << arr[i];				// Array index and item (Dec).
		cout << "  (Hex " << setw(8) << setfill('0') << hex << uppercase << arr[i] << ")\n"; 			// Array item (Hex)
	}
}

// This function finds the highest value in an integer array.
// Two paramaters are taken, an int pointer array, and an int of the array's size.
int findMaximumValue(int *arr, int arraySize) {
	int highestSoFar = arr[0];
	for (int i = 1; i < arraySize; i++) {
		if (arr[i] > highestSoFar) highestSoFar = arr[i];
	}
	return highestSoFar;
}