/*
Module Nine Individual Assignment.
Toby Hansen, April 4 2025, CSC-120-WBL.
This program Calculates the area of 
various shapes using multiple functions. 
*/

#include <iostream>
#include <iomanip> // For double precision
#include <cmath> // For pi
using namespace std;

double calculateRectangleArea(double length, double width);
double calculateTriangleArea(double base, double height);
double calculateCircleArea(double radius);
double calculateTrapezoidArea(double topLength, double bottomLength, double height);

int main() {

    // This code banner is printed before the code is run.
    cout<< "Module Nine Individual Assignment.\n"
        << "Toby Hansen, April 4 2025, CSC-120-WBL.\n"
        << "This program Calculates the area of \n"
        << "various shapes using multiple functions.\n\n";

    // This do-while loop ensures that the program is repeatable.
    // I chose the do-while loop specifically so that the program will always run at least once.
    do {

        // This section gets the user to input which shape they would like to calculate the area of.
        cout<< "Which of the following areas do you want to calculate?\n"
            << " - Rectangle (r)\n"
            << " - Triangle (t)\n"
            << " - Circle (c)\n"
            << " - Trapezoid (z)\n"
            << "Enter r, t, c, or z: ";

        char areaChosen = cin.get();
        while (areaChosen != 'r' && areaChosen != 't' && areaChosen != 'c' && areaChosen != 'z') {
            cout << "Invalid input. Enter r, t, c, or z: ";
            cin >> areaChosen;
        }

        // This section calculates the area of the given shape and then displays it (with a precision of two decimals).
        cout << fixed << setprecision(2);
        switch (areaChosen) {
            case 'r': // Rectangle

                cout<< "To calculate the area of a rectangle, you need the length and the width.\n"
                    << "These two measurements are multiplied.\n";
                
                // This section gets input from the user for what the length of the rectangle is.
                double length;
                cout << "What is the length of the rectangle? ";
                while (!(cin >> length) || length <= 0) { // Loops until valid number input.
                    cout << "Invalid input. Enter a positive length: ";
                    cin.clear();
                    cin.ignore(1000, '\n'); // Removes excess characters in buffer.
                }
                cin.clear();
                cin.ignore(1000, '\n'); // Removes excess characters in buffer.

                // This section gets input from the user for what the length of the rectangle is.
                double width;
                cout << "What is the width of the rectangle? ";
                while (!(cin >> width) || width <= 0) { // Loops until valid number input.
                    cout << "Invalid input. Enter a positive width: ";
                    cin.clear();
                    cin.ignore(1000, '\n'); // Removes excess characters in buffer.
                }
                cin.clear();
                cin.ignore(1000, '\n'); // Removes excess characters in buffer.

                // This section calculates and displays the rectangle's area.
                cout << "The area of a rectangle with length " << length << " and width " << width << " is: " << calculateRectangleArea(length, width);

                break;
            case 't': // Triangle

                cout<< "To calculate the area of a triangle, you need the base and the height.\n"
                    << "These two measurements are multiplied and then halved.\n";
                
                    // This section gets input from the user for what the base of the triangle is.
                double base;
                cout << "What is the base of the triangle? ";
                while (!(cin >> base) || base <= 0) { // Loops until valid number input.
                    cout << "Invalid input. Enter a positive base: ";
                    cin.clear();
                    cin.ignore(1000, '\n'); // Removes excess characters in buffer.
                }
                cin.clear();
                cin.ignore(1000, '\n'); // Removes excess characters in buffer.

                // This section gets input from the user for what the height of the triangle is.
                double heightT;
                cout << "What is the height of the triangle? ";
                while (!(cin >> heightT) || heightT <= 0) { // Loops until valid number input.
                    cout << "Invalid input. Enter a positive height: ";
                    cin.clear();
                    cin.ignore(1000, '\n'); // Removes excess characters in buffer.
                }
                cin.clear();
                cin.ignore(1000, '\n'); // Removes excess characters in buffer.

                // This section calculates and displays the triangle's area.
                cout << "The area of a triangle with base " << base << " and height " << heightT << " is: " << calculateTriangleArea(base, heightT);
                break;
            case 'c': // Circle

                cout<< "To calculate the area of a circle, you need the radius.\n"
                    << "This measurement is squared and then multiplied by pi.\n";

                // This section gets input from the user for what the radius of the circle is.
                double radius;
                cout << "What is the radius of the circle? ";
                while (!(cin >> radius) || radius <= 0) { // Loops until valid number input.
                    cout << "Invalid input. Enter a positive radius: ";
                    cin.clear();
                    cin.ignore(1000, '\n'); // Removes excess characters in buffer.
                }
                cin.clear();
                cin.ignore(1000, '\n'); // Removes excess characters in buffer.

                // This section calculates and displays the circle's area.
                cout << "The area of a circle with radius " << radius << " is: " << calculateCircleArea(radius);

                break;
            case 'z': // Trapezoid

                cout<< "To calculate the area of a trapezoid, you need the top length, bottom length, and height.\n"
                    << "The lengths are added together, then multiplied by the height and halved.\n";

                // This section gets input from the user for what the topLength of the trapezoid is.
                double topLength;
                cout << "What is the top length of the trapezoid? ";
                while (!(cin >> topLength) || topLength <= 0) { // Loops until valid number input.
                    cout << "Invalid input. Enter a positive top length: ";
                    cin.clear();
                    cin.ignore(1000, '\n'); // Removes excess characters in buffer.
                }
                cin.clear();
                cin.ignore(1000, '\n'); // Removes excess characters in buffer.

                // This section gets input from the user for what the bottomLength of the trapezoid is.
                double bottomLength;
                cout << "What is the bottom length of the trapezoid? ";
                while (!(cin >> bottomLength) || bottomLength <= 0) { // Loops until valid number input.
                    cout << "Invalid input. Enter a positive bottom length: ";
                    cin.clear();
                    cin.ignore(1000, '\n'); // Removes excess characters in buffer.
                }
                cin.clear();
                cin.ignore(1000, '\n'); // Removes excess characters in buffer.

                // This section gets input from the user for what the height of the trapezoid is.
                double heightZ;
                cout << "What is the height of the trapezoid? ";
                while (!(cin >> heightZ) || heightZ <= 0) { // Loops until valid number input.
                    cout << "Invalid input. Enter a positive height: ";
                    cin.clear();
                    cin.ignore(1000, '\n'); // Removes excess characters in buffer.
                }
                cin.clear();
                cin.ignore(1000, '\n'); // Removes excess characters in buffer.

                // This section calculates and displays the trapezoid's area.
                cout<< "The area of a trapezoid with top length " << topLength 
                    << ", bottom length " << bottomLength 
                    << ", and height " << heightZ 
                    << " is: " << calculateTrapezoidArea(topLength, bottomLength, heightZ);

                break;
        }

        // This section restarts the program if the user wants to calculate another shape's area. 
        cout << "\nDo you want to do another calculation? (y/n): ";
        cin.clear();
        cin.ignore(1000, '\n');
    } while (cin.get() == 'y');

    return 0;
}

// This function calculates the area of a rectangle given the length and width parameters as doubles, and returns the area as a double.
double calculateRectangleArea(double length, double width) {
    return length * width; // Formula for area of a rectangle: A = l * w
}

// This function calculates the area of a triangle given the base and height parameters as doubles, and returns the area as a double.
double calculateTriangleArea(double base, double height) {
    return base * height / 2; // Formula for area of a triangle: A = b * h / 2
}

// This function calculates the area of a circle given the radius parameter as a double, and returns the area as a double.
double calculateCircleArea(double radius) {
    return radius * radius * M_PI; // Formula for area of a rectangle: A = pi * r^2
}

// This function calculates the area of a trapezoid given the topLength, bottomLength, and height parameters as doubles, and returns the area as a double.
double calculateTrapezoidArea(double topLength, double bottomLength, double height) {
    return (topLength + bottomLength) * height / 2; // Formula for area of a trapezoid: A = (s1 + s2) * h / 2
}

/*
Additional Questions: 
- Why did you choose the specific type of loops for this task?
    I chose a do-while loop for the all-encompassing loop so that no matter what the program would run at least once.
    After the first execution, the while conditional checks the user's input to see if the program should run again.
    
- How does your code handle edge cases?
    My program handles edge cases seamlessly through a rudementary while loop system. After every user input, the while 
    loop checks that the input is valid, and if it ins't than it asks for a new input. This happens infinitely until 
    a valid input is given. In the case of this program, a valid input will always constitute a positive number.
    
- What challenges did you encounter in writing this program, and how did you overcome them?
    A minor challenge I encountered while writing this program was resisting the urge to use features not yet covered
    in class. The four functions for calculating area could easily be turned into a single function with an enum before
    the other parameters. Another function could also be introduced to crack down on all of the validation code. More
    than 50% of the used lines in the program are dedicated to input validation. The same code block is used over and
    over and over again with just a little change. With enums, this could easily become a viable function.
*/