/*======================================
| Toby Hansen, July 17 2025.           |
| Mortgage Lab, CSC-237-200.           |
| This program calculates the monthly/ |
| total payment for a fixed-rate loan. |
======================================*/

#ifndef MORTGAGE_H
#define MORTGAGE_H

#include <string>
using namespace std;

class Mortgage {
private:
   // Private object variables
   double loanAmount;
   double annualInterestRate;
   double numberOfYears;
   string outputFileName;

   // Private functions
   double getNumberOfPayments() const;
   double getMonthlyInterestRate() const;
   double getPowerFactor() const;
   void setObjVariables();
public:
   // Constructor
   Mortgage();

   // Deconstructor
   ~Mortgage();

   // Setter functions
   void setLoanAmount(double newLoanAmount);
   void setAnnualInterestRate(double newAnnualInterestRate);
   void setTotalYearsToRepay(double newTotalYearsToRepay);

   // Getter functions
   double getLoanAmount() const;
   double getAnnualInterestRate() const;
   double getNumberOfYears() const;
   double getMonthlyPayment() const;
   double getTotalPayment() const;

   // Logic functions
   void outputPaymentSchedule() const;
};
#endif