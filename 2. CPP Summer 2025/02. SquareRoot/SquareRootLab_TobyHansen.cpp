/*
Toby Hansen, June 10 2025.
Square Root Lab, CSC-237-200.
This program calculates an approximation of the
square root of a number entered by the user.
*/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

// This is the main function.
int main() {

    // This code banner is printed before the code is run.
    cout<< "Toby Hansen, June 10 2025.\n"
        << "Square Root Lab, CSC-237-200.\n"
        << "This program calculates an approximation of the\n"
        << "square root of a number entered by the user.\n";

    // This section is for declaring variables used throughout the program.
    int precision = 18, fieldWidth = 25; // Values used to make the output easier.
    double inputNumber; // The number to calculate the square root of.
    double tolerance; // The permissible error for the calculated result.
    double estimate; // The initial estimate for the square root.
    double quotient; // inputNumber divided by the estimate.
    double difference; // Difference between the estimate and the quotient.
    double result; // Copy of the estimate variable, before the next calculation.
    int n; // Number of “guesses” so far (loop counter).
    string repeatProgram = "n"; // The string to hold input from the user regarding whether to repeat the program or not.

    // This section is the main program, and repeats until the user decides to stop.
    do {

        // This section takes the user's input for a number to find the square root of.
        cout << "\nInput a number to find the square root of: ";
        while (!(cin >> inputNumber)) { // While the input is invalid:
            cin.clear(); // Clear the buffer.
            cin.ignore(10000, '\n'); // Ignore all remaining characters.
            cout << "Invalid input. Enter again: "; // Let the user know and ask again.
        }
        
        // This section takes the user's input for the tolerance in approximation.
        cout << "Input the permissible error: ";
        while (!(cin >> tolerance)) { // While the input is invalid:
            cin.clear(); // Clear the buffer.
            cin.ignore(10000, '\n'); // Ignore all remaining characters.
            cout << "Invalid input. Enter again: "; // Let the user know and ask again.
        }

        // This section takes the user's input for an initial estimate of what the square root might be.
        cout << "Input an initial estimate of the square root: ";
        while (!(cin >> estimate)) { // While the input is invalid:
            cin.clear(); // Clear the buffer.
            cin.ignore(10000, '\n'); // Ignore all remaining characters.
            cout << "Invalid input. Enter again: "; // Let the user know and ask again.
        }

        // This section outputs the headers for the columns of the estimation table.
        cout<< "\nEstimating the square root of " << inputNumber << "\nWith a tolerance of " << tolerance
            << "\n\nN" << setw(fieldWidth) << "Estimate" << setw(fieldWidth) << "Quotient" << setw(fieldWidth) << "Difference" << endl 
            << "-" << setw(fieldWidth) << "----------" << setw(fieldWidth) << "----------" << setw(fieldWidth) << "----------" << endl;

        // This section calculates the square root of the input number by repeatedly estimating and correcting.
        n = 1; // Setting n to 1 here prevents the estimation couinter from breaking on repetitions of the program.
        do {
            quotient = inputNumber / estimate; // Calculate the quotient.
            difference = fabs(estimate - quotient); // Calculate the difference.
            cout << setprecision(precision) << n << setw(fieldWidth) << estimate << setw(fieldWidth) << quotient << setw(fieldWidth) << difference << "\n"; // Output the intermediate result.
            result = estimate; // Save the current estimate.
            estimate = (result + quotient) / 2; // Calculate another estimate.
            n++; // Increment the number of estimations by one.
        } while (difference >= tolerance);
        cout << "\nThe square root of " << inputNumber << "\n                is " << result << "\n             (+/-) " << difference;

        // This section is for repeating the program if the user wants to.
        cout << "\nDo you want to repeat the program? ";
        cin >> repeatProgram;
    } while (repeatProgram == "y" || repeatProgram == "yes");

    // Finishes up the program.
    system("pause"); // Wait for user input.
    return 0; // End the program.
}