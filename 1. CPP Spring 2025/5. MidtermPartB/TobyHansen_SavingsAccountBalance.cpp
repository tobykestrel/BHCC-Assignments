/*
Midterm Part B (CSC-120-WBL).
Toby Hansen, March 30 2025.
This program calculates the balance of a 
savings account after a period of time.
*/

#include <iostream>
#include <fstream>
#include <iomanip>
using namespace std;

int main() {

    // This code banner is printed before the code is run.
    cout<< "Midterm Part B (CSC-120-WBL).\n"
        << "Toby Hansen, March 30 2025.\n"
        << "This program calculates the balance of a \n"
        << "savings account after a period of time.";

    // This while loop ensures that the program is repeatable.
    while (true) {

        // This section declares the variables used throughout the program.
        double annualInterestRate = 0, balance = 0, thisMonthsDeposit = 0, thisMonthsWithdraw = 0, thisMonthsInterest = 0; 
        int monthsPassed = 0;

        // This section gets input from the user for what the starting balance is for the account.
        cout << "\n\nWhat is the starting balance in the account? ";
        while (!(cin >> balance) || balance < 0) { // Loops until valid number input.
            cout << "Invalid input. Enter a non-negative starting balance: ";
            cin.clear();
            cin.ignore(1000, '\n'); // Removes excess characters in buffer.
        }

        // This section gets input from the user for what the annual interest is for the account.
        cout << "What is the annual interest rate for the account? ";
        while (!(cin >> annualInterestRate) || annualInterestRate <= 0) { // Loops until valid number input.
            cout << "Invalid input. Enter a positive interest rate: ";
            cin.clear();
            cin.ignore(1000, '\n'); // Removes excess characters in buffer.
        }

        // This section gets input from the user for how many months have passed since the account was established.
        cout << "How many months have passed since the account was established? ";
        while (!(cin >> monthsPassed) || monthsPassed <= 0) { // Loops until valid number input.
            cout << "Invalid input. Enter a positive amount of months: ";
            cin.clear();
            cin.ignore(1000, '\n'); // Removes excess characters in buffer.
        }

        // This section initializes the outfilestream object for writing to the transactions file.
        // Opening the file as an outfile also has the benefit of clearing any old text that might still be there.
        // The program exits if the transactions file was unable to be opened.
        ofstream transactionsFileWrite("TobyHansen_AccountTransactions.txt");
        if (!transactionsFileWrite) {
            cout << "Error: Unable to open TobyHansen_AccountTransactions.txt";
            return 1;
        }
        transactionsFileWrite << fixed << setprecision(2);

        // For every month that has passed:
        // - Ask how much was deposited during that month, and add it to the balance.
        // - Ask how much was withdrawn during that month, and subtract it from the balance. 
        // - Calculate the monthly interest. (Monthly interest rate is the annual interest rate divided by 12).
        for (int month = 1; month < monthsPassed+1; month++) {
            // This section gets input from the user for how much money was deposited into the account each month.
            cout << "How much money was deposited during month " << month << "? ";
            while (!(cin >> thisMonthsDeposit) || thisMonthsDeposit < 0) { // Loops until valid number input.
                cout << "Invalid input. Enter a non-negative deposit: ";
                cin.clear();
                cin.ignore(1000, '\n');
            }

            // Add the monthly deposit to the balance and record the transaction (if there is one) 
            if (thisMonthsDeposit > 0) {
                balance += thisMonthsDeposit;
                transactionsFileWrite << "Month " << month << " Deposit:  +$" << thisMonthsDeposit << "; New Total: $" << balance << endl;
            }

            // This section gets input from the user for how much money was withdrawn from the account each month.
            cout << "How much money was withdrawn during month " << month << "? ";
            while (!(cin >> thisMonthsWithdraw) || thisMonthsWithdraw < 0) { // Loops until valid number input.
                cout << "Invalid input. Enter a non-negative withdraw: ";
                cin.clear();
                cin.ignore(1000, '\n');
            }

            // Subtract the monthly withdraw from the balance and record the transaction (if there is one) 
            if (thisMonthsWithdraw > 0) {
                balance -= thisMonthsWithdraw;
                transactionsFileWrite << "Month " << month << " Withdraw: -$" << thisMonthsWithdraw << "; New Total: $" << balance << endl;

                // If the balance becomes negative, close the account.
                if (balance < 0) {
                    cout << "Account has gone negative after withdrawing $" << thisMonthsWithdraw << " and is now closed.\n";
                    break;
                }
            }

            // This section adds the monthly interest to the balance and records the transaction.
            thisMonthsInterest = balance*annualInterestRate/12;
            balance += thisMonthsInterest;
            transactionsFileWrite << "Month " << month << " Interest: +$" << thisMonthsInterest << "; New Total: $" << balance << endl;
        }
        transactionsFileWrite.close();

        // This section displays the total after the given amount of time.
        cout << "\nAfter " << monthsPassed << " months, the account has $" << balance;

        
        // This section initializes the infilestream object for reading from the transactions file.
        // The program exits if the transactions file was unable to be opened.
        ifstream transactionsFileRead("TobyHansen_AccountTransactions.txt");
        if (!transactionsFileRead) {
            cout << "Error: Unable to open TobyHansen_AccountTransactions.txt";
            return 1;
        }

        // This section displays all the transactions by reading each line from the transactions file.
        cout << "\n\nAll account transactions are as follows: \n";
        string line;
        while (getline(transactionsFileRead, line)) { 
            cout << line << endl;
        }
        transactionsFileRead.close();

        // This section restarts the program if the user wants to calculate another factorial. 
        cout << "\nDo you want to do another calculation? (y/n): ";
        cin.clear();
        cin.ignore(1000, '\n');
        if (cin.get() != 'y') {
            break; // Exits the loop, ending the program.
        }
    }

    return 0;
}