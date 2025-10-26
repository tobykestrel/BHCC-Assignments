/*======================================
| Toby Hansen, July 17 2025.           |
| Mortgage Lab, CSC-237-200.           |
| This program calculates the monthly/ |
| total payment for a fixed-rate loan. |
======================================*/

#include "Mortgage.h"
#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
using namespace std;

// Constructor
Mortgage::Mortgage() {
    cout << "INFO: Executing CONSTRUCTOR for Mortgage class.\n";
    setObjVariables();
}

// Deconstructor
Mortgage::~Mortgage() {
    cout << "INFO: Executing DESTRUCTOR for Mortgage class (loan amount = " << loanAmount << ").\n";
}

// Setter functions
void Mortgage::setLoanAmount(double newLoanAmount) { loanAmount = newLoanAmount; }
void Mortgage::setAnnualInterestRate(double newAnnualInterestRate) { annualInterestRate = newAnnualInterestRate; }
void Mortgage::setTotalYearsToRepay(double newTotalYearsToRepay) { numberOfYears = newTotalYearsToRepay; }

// Getter functions
double Mortgage::getLoanAmount() const { return loanAmount; }
double Mortgage::getAnnualInterestRate() const { return annualInterestRate; }
double Mortgage::getNumberOfYears() const { return numberOfYears; }
double Mortgage::getMonthlyPayment() const { return (loanAmount*getMonthlyInterestRate()*getPowerFactor())/(getPowerFactor()-1); }
double Mortgage::getTotalPayment() const { return getMonthlyPayment()*getNumberOfPayments(); }
double Mortgage::getNumberOfPayments() const { return numberOfYears*12; }
double Mortgage::getMonthlyInterestRate() const { return annualInterestRate/12; }
double Mortgage::getPowerFactor() const { return pow((1+getMonthlyInterestRate()), getNumberOfPayments()); }

// Logic functions
void Mortgage::setObjVariables() {
    // This section takes a user's input on what the output file should be.
    cout << "Enter output file name: ";
    getline(cin, outputFileName);

    // This section takes a user's input on the loan amount.
    cout << "Enter the amount of the loan: ";
    while (!(cin >> loanAmount)) { // While the input is invalid:
        cin.clear(); 
        cin.ignore(10000, '\n'); 
        cout << "Invalid input. Enter again: "; // Let the user know and ask again.
    }
    cin.ignore(10000, '\n');

    // This section takes a user's input on the annual interest rate.
    cout << "Enter the annual interest rate in decimal form (example .075): ";
    while (!(cin >> annualInterestRate)) { // While the input is invalid:
        cin.clear(); 
        cin.ignore(10000, '\n'); 
        cout << "Invalid input. Enter again: "; // Let the user know and ask again.
    }
    cin.ignore(10000, '\n');

    // This section takes a user's input on the number of years.
    cout << "Enter the length of the loan in years: ";
    while (!(cin >> numberOfYears)) { // While the input is invalid:
        cin.clear(); 
        cin.ignore(10000, '\n'); 
        cout << "Invalid input. Enter again: "; // Let the user know and ask again.
    }
    cin.ignore(10000, '\n');
}
void Mortgage::outputPaymentSchedule() const {
    // This section opens a file for writing to.
    ofstream out(outputFileName);

    // This section outputs the file header.
    out << fixed << setprecision(2) << "\nLoan Amount: $" << loanAmount
        << fixed << setprecision(4) << "\nAnnual Interest Rate: " << annualInterestRate
        << fixed << setprecision(0) << "\nYears to Repay: " << numberOfYears
        << fixed << setprecision(2) << "\nMonthly Payment: " << getMonthlyPayment()
        << fixed << setprecision(2) << "\nTotal Pay Back: " << getTotalPayment() << "\n\n";

    // This section outputs the payment schedule header.
    out << setw(5) << "Pmt#" 
        << setw(17) << "Payment Amount" 
        << setw(11) << "Interest" 
        << setw(23) << "Contrib to principal" 
        << setw(20) << "Remaining balance" << endl;

    // This section outputs the payment schedule.
    double remainingBalance = loanAmount;
    double interest, contribToPrincipal;
    for (int pmt = 1; remainingBalance > 0.01; pmt++) {
        interest = (getMonthlyInterestRate()*remainingBalance);
        contribToPrincipal = (getMonthlyPayment()-(getMonthlyInterestRate()*remainingBalance));
        remainingBalance -= contribToPrincipal;
        out << right << setw(5) << pmt
            << fixed << setprecision(2)
            << setw(17) << getMonthlyPayment()
            << setw(11) << interest
            << setw(23) << contribToPrincipal
            << setw(20) << remainingBalance << endl;
    }

    // This section closes the file.
    out.close();
}