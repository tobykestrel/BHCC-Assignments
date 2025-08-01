/*
Toby Hansen, June 3 2025.
Miles Per Gallon Lab, CSC-237-200.
This program calculates a user's miles per gallon
based on their input of odometer and gallons filled.
*/

#include <iostream>
#include <iomanip>
using namespace std;

// This is the main function.
int main() {

    // This code banner is printed before the code is run.
    cout<< "Toby Hansen, June 3 2025.\n"
        << "Miles Per Gallon Lab, CSC-237-200.\n"
        << "This program calculates a user's miles per gallon\n"
        << "based on their input of odometer and gallons filled.\n\n";

    // This section is for declaring variables used throughout the program.
    int odomoterPrevious, odometerLatest, milesTraveled;
    double gallonsFilled, milesPerGallon;

    // This section takes the user's input for the odometer at the previous fill-up.
    cout << "Odometer reading at the previous fill-up: ";
    while (!(cin >> odomoterPrevious)) { // While the input is invalid:
        cin.clear(); // Clear the buffer.
        cin.ignore(10000, '\n'); // Ignore all remaining characters.
        cout << "Invalid input. Enter again: "; // Let the user know and ask again.
    }
    
    // This section takes the user's input for the odometer at the latest fill-up.
    cout << "Odometer reading at the latest fill-up: ";
    while (!(cin >> odometerLatest)) { // While the input is invalid:
        cin.clear(); // Clear the buffer.
        cin.ignore(10000, '\n'); // Ignore all remaining characters.
        cout << "Invalid input. Enter again: "; // Let the user know and ask again.
    }

    // This section calculates the distance traveled between the previous and latest fill-ups.
    milesTraveled = odometerLatest - odomoterPrevious;
    cout << "Distance Travelled = " << milesTraveled << " miles.\n";

    // This section takes the user's input for the amount of gallons purchased at the latest fill-up.
    cout << "Gallons filled at the latest fill-up: ";
    while (!(cin >> gallonsFilled)) { // While the input is invalid:
        cin.clear(); // Clear the buffer.
        cin.ignore(10000, '\n'); // Ignore all remaining characters.
        cout << "Invalid input. Enter again: "; // Let the user know and ask again.
    }

    // This section calculates the miles per gallon of the user.
    milesPerGallon = milesTraveled / gallonsFilled;
    cout << fixed << setprecision(1) << "You get " << milesPerGallon << " miles per gallon. In other words,\nYour fuel economy is " << milesPerGallon << " MPG.\n";

    // This section finishes up the program.
    system("pause"); // Wait for user input.
    return 0; // End the program.
}