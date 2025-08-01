/*
Module Three Group Project by Toby Hansen, Feb 23 2025
This program is a payroll calculator that receives input from the user about 
each employee regarding their hours worked and pay rate. Their individual 
total pay is then calculated, as well as the total and average pay for all 
employees. All information is then displayed in a well formatted table. 
*/

#include <iostream>
#include <iomanip> // Used to format output.
#include <cstdlib> // Used for random int.

using namespace std;

// This section initializes constants needed to format the display table correctly.
const int EMPLOYEEID_WIDTH = 8;
const int HOURS_WIDTH = 10;
const int PAYRATE_WIDTH = 10;
const int TOTALPAY_WIDTH = 14;
const int TABLE_WIDTH = EMPLOYEEID_WIDTH + HOURS_WIDTH + PAYRATE_WIDTH + TOTALPAY_WIDTH + 4;

int main() {
    // This code banner is printed before the code is run.
    cout << "Module Three Group Project by Toby Hansen, Feb 23 2025\n"
    << "This program is a payroll calculator that receives input from the user about\n"
    << "each employee regarding their hours worked and pay rate. Their individual\n"
    << "total pay is then calculated, as well as the total and average pay for all\n"
    << "employees. All information is then displayed in a well formatted table.\n\n";

    // This section gets input from the user to decide how many employees there will be.
    int numberOfEmployees; 
    cout << "Enter the amount of employees: ";
    while (!(cin >> numberOfEmployees) || numberOfEmployees < 1) { // Loops until valid input.
        cin.clear();
        cin.ignore(1000, '\n');
        cout << "Invalid input, not a positive integer.\nEnter the amount of employees: ";
    }

    // Initialize the arrays that will hold employee information.
    int employeeIDs[numberOfEmployees], hours[numberOfEmployees], overallTotalHours = 0;
    double payRates[numberOfEmployees], totalPays[numberOfEmployees], overallTotalPay = 0;

    // This section allows the user to input data for each employee.
    for (int i = 0; i < numberOfEmployees; i++) {
        employeeIDs[i] = rand() % 9000 + 1000; // Generates random id# between 1000 and 9999 for each employee.

        // This section allows the user to input the hours worked for each employee.
        cout << "Enter the amount of hours worked by employee #" << employeeIDs[i] << ": ";
        while (!(cin >> hours[i]) || hours[i] < 0) { // Loop until valid input.
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input, needs to be a non-negative integer.\nEnter the amount of hours worked by employee #" << employeeIDs[i] << ": ";
        }

        // This section allows the user to input the pay rate for each employee.
        cout << "Enter the hourly pay rate for employee #" << employeeIDs[i] << ": ";
        while (!(cin >> payRates[i]) || payRates[i] < 0) { // Loop until valid input.
            cin.clear();
            cin.ignore(1000, '\n');
            cout << "Invalid input, needs to be a non-negative number.\nEnter the hourly pay rate for employee #" << employeeIDs[i] << ": ";
        }

        // This section calculates the total pay for the employee, and adds it to the overall total pay.
        totalPays[i] = hours[i] * payRates[i];
        overallTotalPay += totalPays[i];
        overallTotalHours += hours[i];
    }

    // This section outputs the table header.
    cout << "\n\n" 
        << setw(EMPLOYEEID_WIDTH) << "Emp ID"
        << setw(HOURS_WIDTH) << "Hours"
        << setw(PAYRATE_WIDTH) << "Pay Rate"
        << setw(TOTALPAY_WIDTH) << "Total Pay" << "\n";
    cout << string(TABLE_WIDTH, '=') << "\n";

    // This section output employee data.
    cout << fixed << setprecision(2); // Sets the decimal precision to two decimal places.
    for (int i = 0; i < numberOfEmployees; i++) {
        cout << setw(EMPLOYEEID_WIDTH) << employeeIDs[i]
            << setw(HOURS_WIDTH) << hours[i]
            << setw(PAYRATE_WIDTH) << payRates[i]
            << setw(TOTALPAY_WIDTH) << totalPays[i] << "\n";
    }

    // This section outputs the employee totals.
    cout << string(TABLE_WIDTH, '=') << "\n";
    cout << setw(EMPLOYEEID_WIDTH) << "Totals:"
    << setw(HOURS_WIDTH) << overallTotalHours
    << setw(PAYRATE_WIDTH) << ""
    << setw(TOTALPAY_WIDTH) << overallTotalPay << "\n";

    // This section outputs the average total pay of all the employees.
    cout << string(TABLE_WIDTH, '=') << "\n";
    cout << setw(TABLE_WIDTH / 2) << "Average Total Pay: $" << overallTotalPay / numberOfEmployees << "\n\n";

    return 0;
}
