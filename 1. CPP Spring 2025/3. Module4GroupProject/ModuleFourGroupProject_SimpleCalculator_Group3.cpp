/*
Calculus II (MAT282-WB1) Module Four Group Project by Group 3, March 2 2025.
Group Members: Toby Hansen, Dowon Yang, Rakin Bhuiyan, John Nagasawa.
This program is a simple calculator that receives two operand inputs from the user as well as an 
operation input. The operation is then applied to the two operands, and the outcome is displayed.
*/

#include <iostream>
using namespace std;

int main() {

    // This code banner is printed before the code is run. (Toby)
    cout<< "Calculus II (MAT282-WB1) Module Four Group Project by Group 3, March 2 2025\n"
        << "Group Members: Toby Hansen, Dowon Yang, Rakin Bhuiyan, John Nagasawa.\n"
        << "This program is a simple calculator that receives two operand inputs from the user as well as an\n"
        << "operation input. The operation is then applied to the two operands, and the outcome is displayed.\n\n";

    // This section displays a start menu with the available operators. (Toby)
    cout<< "================= Valid Operators =================\n"
        << "        Addition: +               Substraction: -  \n"
        << "  Multiplication: *                   Division: /  \n"
        << "          Modulo: %                                \n"
        << "===================================================\n";

    // This section declares the variables used throughout the program. (Dowon)
    double operand1, operand2, solution;
    char operation;

    // This while loop ensures that the program is repeatable.
    while (true) {

        // This section gets input from the user for the first operand. (Toby)
        cout << "\nEnter first operand: ";
        while (!(cin >> operand1)) { // Loops until valid number input.
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input, not a number.\nEnter first operand: ";
        }
        cin.ignore(1000, '\n');

        // This section gets input from the user for the second operand. (Toby)
        cout << "\nEnter second operand: ";
        while (!(cin >> operand2)) { // Loops until valid number input.
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input, not a number.\nEnter second operand: ";
        }
        cin.ignore(1000, '\n');

        // This section gets input from the user for the operation. (Toby and Dowon)
        cout << "\nEnter valid operator: ";
        while (true) { // Loops until valid char input.
            cin >> operation;
            if (operation != '+' && operation != '-' && operation != '*' && operation != '/' && operation != '%') {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid input, not a valid operator.\nEnter valid operator: ";
            } else if (operand2 == 0 && (operation == '/' || operation == '%')) {
                cin.clear();
                cin.ignore(1000, '\n');
                cout << "Invalid input, cannot divide by or mod zero.\nEnter valid operator: ";
            } else {
                break;
            }
        }
        cin.ignore(1000, '\n');

        // This section calculates the solution. (Toby)
        switch (operation) {
            case '+':
                solution = operand1 + operand2;
                break;
            case '-':
                solution = operand1 - operand2;
                break;
            case '*':
                solution = operand1 * operand2;
                break;
            case '/':
                solution = operand1 / operand2;
                break;
            case '%':
                // Mathematical formula of modulo.
                solution = operand1 - operand2 * (int)(operand1/operand2);
                break;
        }

        // This section outputs the solution. (Toby)
        cout<< "\n\n==================== Solution ====================\n\n"
            << "             " << operand1 << " " << operation << " " << operand2 << " = " << solution
            << "\n\n==================================================\n\n";

        // This section restarts the program if the user wants to calculate again. (Dowon)
        char choice;
        cout << "Do you want to do another calculation? (y/n): ";
        while (!(cin >> choice) || (choice != 'y' && choice != 'Y' && choice != 'n' && choice != 'N')) {
            cin.clear(); 
            cin.ignore(1000, '\n'); 
            cout << "Error: Invalid input. Please enter 'y' or 'n': ";
        }

        if (choice == 'n' || choice == 'N') {
            break; // Exits the loop, ending the program.
        }
    }
    
    return 0;
}