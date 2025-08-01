/*======================================
| Toby Hansen, July 17 2025.           |
| Mortgage Lab, CSC-237-200.           |
| This program calculates the monthly/ |
| total payment for a fixed-rate loan. |
======================================*/

#include "Mortgage.h"
#include <iostream>
using namespace std;
#include <filesystem>
// This section is for declaring function prototypes.
// returnType functionName(varType varName, type &refVarName);

// This is the main function.
int main() {
   cout << "Current working directory: " << filesystem::current_path() << endl;

   // This code banner is printed before the code is run.
   cout<< "/*======================================\n"
       << "| Toby Hansen, July 17 2025.           |\n"
       << "| Mortgage Lab, CSC-237-200.           |\n"
       << "| This program calculates the monthly/ |\n"
       << "| total payment for a fixed-rate loan. |\n"
       << "======================================*/\n\n";
   
   while (true) {
      // This section creates the mortgage object and outputs the payment schedule.
      Mortgage* m = new Mortgage();
      m->outputPaymentSchedule();

      // This section outputs the mortgage info.
      cout  << fixed << setprecision(2) << "\nLoan Amount: $" << m->getLoanAmount()
            << fixed << setprecision(4) << "\nAnnual Interest Rate: " << m->getAnnualInterestRate()
            << fixed << setprecision(0) << "\nYears to Repay: " << m->getNumberOfYears()
            << fixed << setprecision(2) << "\nMonthly Payment: " << m->getMonthlyPayment()
            << fixed << setprecision(2) << "\nTotal Pay Back: " << m->getTotalPayment()
            << "\n\nDo you wish to process another loan? ";
      
      // This section deconstructs the mortgage object and checks the user input on whether to process another loan.
      if (cin.get() != 'y') {
         delete m;
         break; // Exits the loop, ending the program.
      }
      delete m;
      cin.ignore(10000, '\n'); 
   }

   // Finishes up the program.
   system("pause"); // Wait for user input.
   return 0; // End the program
}

/*
   // Example: If you borrow $250,000 in a 30-year fixed rate mortgage, at 4.75 % interest per year:
   // loanAmount           = 250000                                  = 250000
   // annualInterestRate   = 0.0475                                  = 0.0475
   // numberOfYears        = 30                                      = 30
   // numberOfPayments     = 30*12                                   = 360
   // monthlyInterestRate  = 0.0475/12                               = 0.00395833
   // powerFactor          = (1+0.00395833)^360                      = 4.14618
   // monthlyPayment       = (250000*0.00395833*4.14618)/(4.14618-1) = 1304.12
   // totalPayment         = 1304.12*360                             = 469482.6
   double loanAmount, annualInterestRate, numberOfYears;
   double numberOfPayments = numberOfYears*12;
   double monthlyInterestRate = annualInterestRate/12;
   double powerFactor = pow((1+monthlyInterestRate), numberOfPayments);
   double monthlyPayment = (loanAmount*monthlyInterestRate*powerFactor)/(powerFactor-1);
   double totalPayment = monthlyPayment*numberOfPayments;
*/