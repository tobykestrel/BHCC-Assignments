/*
Toby Hansen, July 1 2025.
Arrays Lab, CSC-237-200.
This program finds the highest, lowest, 
sum, and average of a given number set.
*/

#include <iostream>
#include <fstream>
using namespace std;

// This section is for declaring global variables.
const int ARRAY_SIZE = 100;

// This section is for declaring function prototypes.
int getLowest(int (&nums)[ARRAY_SIZE], int numsCount);
int getHighest(int (&nums)[ARRAY_SIZE], int numsCount);
int getSum(int (&nums)[ARRAY_SIZE], int numsCount);
double getAverage(int (&nums)[ARRAY_SIZE], int numsCount);

// This is the main function.
int main() {

    // This code banner is printed before the code is run.
    cout<< "Toby Hansen, July 1 2025.\n"
        << "Arrays Lab, CSC-237-200.\n"
        << "This program finds the highest, lowest,\n"
        << "sum, and average of a given number set.\n\n";

    // This section is for declaring variables used throughout the program.
	int numbers[ARRAY_SIZE];
	string inputFileName;
    ifstream inputFile;
    string line;
	int amountOfNums = 0;

	// This section asks the user what the input file should be.
    cout << "What is the name of the input file? ";
	cin >> inputFileName;
	
    // This section opens the file for reading from.
    inputFile.open(inputFileName);
    while (!inputFile) { // While the input file is invalid:
        cin.clear(); // Clear the buffer.
        cin.ignore(10000, '\n'); // Ignore all remaining characters.
        cout << "Error opening \"" << inputFileName << "\"!"; // Let the user know.
		cout << "What is the name of the input file? "; // Ask again.
		cin >> inputFileName; // Set the new input file name.
    	inputFile.open(inputFileName); // Try opening the new file.
    } 

    // This section reads each line into the numbers array.
    while (getline(inputFile, line) && amountOfNums < ARRAY_SIZE) {
		numbers[amountOfNums++] = stoi(line);
	} 

    // This section closes the file.
    inputFile.close(); // Close the file when done.

	// This section displays the Lowest, Highest, Sum, and Average of the given number set.
	cout<< "Amount of numbers read from input file: " << amountOfNums
		<< "\nThe highest value is: " << getHighest(numbers, amountOfNums)
		<< "\nThe lowest value is: " << getLowest(numbers, amountOfNums)
		<< "\nThe sum of the numbers is: " << getSum(numbers, amountOfNums)
		<< "\nThe average of the numbers is: " << getAverage(numbers, amountOfNums) << endl;

    // Finishes up the program.
    system("pause"); // Wait for user input.
    return 0; // End the program
}

int getLowest(int (&nums)[ARRAY_SIZE], int numsCount) {
	int lowestSoFar = nums[0];
	for (int i = 1; i < numsCount; i++) if (nums[i] < lowestSoFar) lowestSoFar = nums[i];
	return lowestSoFar;
}

int getHighest(int (&nums)[ARRAY_SIZE], int numsCount) {
	int highestSoFar = nums[0];
	for (int i = 1; i < numsCount; i++) if (nums[i] > highestSoFar) highestSoFar = nums[i];
	return highestSoFar;
}

int getSum(int (&nums)[ARRAY_SIZE], int numsCount) {
	int sum = 0;
	for (int i = 0; i < numsCount; i++) sum += nums[i];
	return sum;
}

double getAverage(int (&nums)[ARRAY_SIZE], int numsCount) {
	return getSum(nums, numsCount) / (double)numsCount;
}