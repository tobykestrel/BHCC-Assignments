/*
Variable Assignment by Toby Hansen, Feb 14 2025
This program initializes three variables: an integer, float, and double.
It then calculates and prints the sum, difference, product, and division of the integer and float.
*/

#include <iostream>
using namespace std;

int main() {
    // This code banner is printed before the code is run.
    cout << "Variable Assignment by Toby Hansen, Feb 14 2025\n"
    << "This program initializes three variables: an integer, float, and double.\n"
    << "It then calculates and prints the sum, difference, product, and division of the integer and float.\n\n";

    // Initialize number variables (Arizona Tea is my favorite thing in the world).
    int myInteger = 6; // This is the amount of Arizona Iced Teas in a six-pack.
    float myFloat = 0.99; // This is the cost of an Arizona Iced Tea.
    double myDouble = 2.98; // This is the cost of a gallon jug of Arizona Iced Tea.

    // Initialize calculation variables.
    float mySum, myDifference, myProduct, myQuotient;

    // Initialize edge case variable in case myFloat is equal to zero.
    bool isFloatZero = false;

    // Check whether myFloat is equal to zero. If it is, let isFloatZero reflect that.
    if (myFloat == 0) {
        isFloatZero = true;
    }

    // Calculate the results of the sum, difference, and product.
    mySum = myInteger + myFloat;
    myDifference = myInteger - myFloat;
    myProduct = myInteger * myFloat;

    // Only perform the division operation if myFloat is not equal to zero.
    if (!isFloatZero) {
        myQuotient = myInteger / myFloat;
    }

    // Display the results of the sum, diffference, and product.
    cout << "Sum of myInteger and myFloat: " <<  mySum << "\n";
    cout << "Difference of myInteger and myFloat: " << myDifference << "\n";
    cout << "Product of myInteger and myFloat: " << myProduct << "\n";

    // Only print the result of the quotient if myFloat is not equal to zero.
    // If myFloat is equal to zero, print why the operation was not possible.
        if (!isFloatZero) {
            cout << "Division of myInteger and myFloat: " << myQuotient;
        } else {
            cout << "myFloat is equal to zero, making it ineligible as a denominator";
        }
        
    return 0;
}