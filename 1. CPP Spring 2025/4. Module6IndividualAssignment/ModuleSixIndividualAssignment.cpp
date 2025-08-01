/*
Calculus II (MAT282-WB1)
Toby Hansen, March 12 2025.
Module Six Individual Assignment
This program is a simple factorial 
calculator that works using a while loop.
*/

#include <iostream>
using namespace std;

int main() {

    // This code banner is printed before the code is run.
    cout<< "Calculus II (MAT282-WB1)\n"
        << "Toby Hansen, March 12 2025.\n"
        << "Module Six Individual Assignment\n"
        << "calculator that works using a while loop."
    << "\n\n";

    // This while loop ensures that the program is repeatable.
    while (true) {

        // This section declares the variables used throughout the program.
        int factorialInt = 0;
        int factorialTotal = 1;

        // This section gets input from the user to decide what number is facorialed.
        cout << "\nEnter a positive integer: ";
        cin >> factorialInt;
        cin.clear();
        cin.ignore(1000, '\n'); // Removes excess characters in buffer.
        while (factorialInt < 1) { // Loops until valid number input.
            cout << "Invalid input.\nEnter a positive integer: ";
            cin >> factorialInt;
            cin.clear();
            cin.ignore(1000, '\n');
        }

        // This section calculates the factorial, and displays the answer as it does.
        cout << factorialInt << "! = ";
        while (true) { // Loops until the entire factorial equation is printed.
            factorialTotal *= factorialInt;
            cout << factorialInt;
            factorialInt--;
            if (factorialInt == 0) { // End of the factorial calculation, exit the while loop.
                cout << " = " << factorialTotal;
                break; 
            }
            cout << "*";
        }

        // This section restarts the program if the user wants to calculate another factorial. 
        cout << "\nDo you want to do another calculation? (y/n): ";
        if (cin.get() != 'y') {
            break; // Exits the loop, ending the program.
        }
    }

    return 0;
}