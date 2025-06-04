/*
Calculus II (MAT282-WB1) Module Four Group Project by Toby Hansen, March 2 2025
This program is a simple calculator that receives two operand inputs from the user as well as an 
operation input. The operation is then applied to the two operands, and the outcome is displayed.
*/

#include <iostream>
using namespace std;

int main() { 
    
    // This code banner is printed before the code is run.
    cout<< "Calculus II (MAT282-WB1) Module Four Group Project by Toby Hansen, March 2 2025\n"
        << "This program is a simple calculator that receives two operand inputs from the user as well as an\n"
        << "operation input. The operation is then applied to the two operands, and the outcome is displayed.\n\n";

    // This section displays a start menu with the available operators.
    cout<< "================= Valid Operators =================\n"
        << "        Addition: +               Substraction: -  \n"
        << "  Multiplication: *                   Division: /  \n"
        << "          Modulo: %                                \n"
        << "===================================================\n";

    // This section declares the variables used throughout the program.
    double operandOne, operandTwo, solution;
    char operation;
    
    // This while loop ensures that the program is repeatable.
    while (true) { 

        // This section gets input from the user for the first operand.
        cout << "\nEnter first operand: ";
        while (!(cin >> operandOne)) { // Loops until valid number input.
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input, not a number.\nEnter first operand: ";
        }
        cin.ignore(1000, '\n');

        // This section gets input from the user for the second operand.
        cout << "\nEnter second operand: ";
        while (!(cin >> operandTwo)) { // Loops until valid number input.
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input, not a number.\nEnter second operand: ";
        }
        cin.ignore(1000, '\n');

        // This section gets input from the user for the operation.
        const string operators = "+-*/%";
        cout << "\nEnter valid operator: ";
        while (true) { // Loops until valid char input.
            cin >> operation;
            if (!(operators.find(operation) < operators.length())) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid input, not a valid operator.\nEnter valid operator: ";
            } else if (operandTwo == 0 && (operation == '/' || operation == '%')) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid input, cannot divide by or mod zero.\nEnter valid operator: ";
            } else {
                break;
            }
        }
        cin.ignore(1000, '\n');

        // This section calculates the solution.
        switch (operation) {
            case '+':
                solution = operandOne + operandTwo;
                break;
            case '-':
                solution = operandOne - operandTwo;
                break;
            case '*':
                solution = operandOne * operandTwo;
                break;
            case '/':
                solution = operandOne / operandTwo;
                break;
            case '%':
                // Mathematical formula of modulo
                solution = operandOne - operandTwo * (int)(operandOne/operandTwo);
                break;
        }

        // This section outputs the solution.
        cout<< "\n\n==================== Solution ====================\n\n"
            << "             " << operandOne << " " << operation << " " << operandTwo << " = " << solution
            << "\n\n==================================================\n\n";

        // This section restarts the program if the user wants to calculate again.
        cout << "Would you like to calculate again? (y/n) ";
        cin.ignore(1000, '\n');
        if (cin.get() != 'y') { // Stops the program if the user inputs 'y'.
            break;
        }

    } 
    
    return 0; 
}
