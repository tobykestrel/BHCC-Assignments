/*
Module Twelve Group Project.
Toby Hansen, April 27 2025, CSC-120-WBL.
This program checks lottery numbers
to see if they are winning numbers.
*/

#include <iostream>
#include <vector>
using namespace std;

// This section is for declaring function prototypes and global variables.
bool isDuplicate(const vector<int>& vec, int num);
void bubbleSort(vector<int>& vec);

// This is the main function.
int main() {

    // This code banner is printed before the code is run.
    cout<< "Module Thirteen Group Project.\n"
        << "Toby Hansen, May 4 2025, CSC-120-WBL.\n"
        << "This program checks lottery numbers\n"
        << "to see if they are winning numbers.\n\n";

    // This do-while loop ensures that the program is repeatable.
    // I chose the do-while loop specifically so that the program will always run at least once.
    do {

        // This section initializes the variables used throughout the program.
        vector<int> luckyTickets = {13579, 26791, 26792, 33445, 55555, 62483, 77777, 79422, 85647, 93121};
        vector<int> winningTickets;
        int winningNumber;
        bool matchFound = false;

        // This section makes the user input 10 winning lottery numbers.
        // If invalid input is given, then the user is continuously prompted until valid input is given.
        cout << "Enter this week's 10 winning 5-digit numbers.\n";
        for (int i = 1; i < 11; i++) {
            cout << "Winning Number " << i << ": ";
            while(!(cin >> winningNumber) || winningNumber < 10000 || winningNumber > 99999 || isDuplicate(winningTickets, winningNumber)) {
                cin.clear();
                cin.ignore(10000, '\n');
                cout << "Invalid input. Enter a unique 5-digit number: ";
            }
            winningTickets.push_back(winningNumber);
        }
        
        // This section sorts both number vecotrs, and finds any matches.
        bubbleSort(luckyTickets);
        bubbleSort(winningTickets);
        cout << "\nMatching ticket numbers: ";
        for (int i = 0; i < luckyTickets.size(); i++) { // For every lucky ticket number:
            for (int j = 0; j < winningTickets.size(); j++) { // For every winning ticket number:
                if (luckyTickets[i] == winningTickets[j]) { // Compare the lucky ticket number to the winning ticket number. If there is a match:
                    cout << luckyTickets[i] << " "; // Display the match that was found.
                    matchFound = true; // Let it be known that a match was found.
                    break; // Start checking the next lucky number.
                }
            }
        }
        if (!matchFound) cout << "No matching ticket numbers found.\n";

        // This section restarts the program if the user wants to.
        cout << "\n\nDo you want to run the program again? (y/n): ";
        cin.clear();
        cin.ignore(10000, '\n');
    } while (cin.get() == 'y');

    return 0;
}

// This function checks for a duplicate in the vector number set.
// Input: vector passed by reference, and an int to be compared.
// Output: bool of whether or not there is a duplicate of the int in the vector.
bool isDuplicate(const vector<int>& vec, int num) {
    for (int val : vec) { // For every number in the vector:
        if (val == num) return true; // Compare it to the given number. If they are the same, then return true (the number is a duplicate).
    }
    return false; // Otherwise, return false (the number is not a duplicate).
}

// This function performs a bubble sort on a vector number set.
// Input: vector passed by reference to have its values sorted.
// Basically, this sort algorithm works by looking at each item in the vector, and comparing it to all items above it until it reaches an item that is greater than it.
// This effectively sorts the vector in ascending order from smallest to biggest.
void bubbleSort(vector<int>& vec) {
    for (int i = 0; i < vec.size() - 1; i++) { // This for loop ensures that the following operation occurs as many times as there are items in the vector.
        for (int j = 0; j < vec.size() - 1 - i; j++) { // This for loop runs through the entire vector beginning to end (except the last item).
            if (vec[j] > vec[j + 1]) { // If the current item is greater than the next item, then swap the two items' indexes.
                int temp = vec[j]; 
                vec[j] = vec[j + 1];
                vec[j + 1] = temp;
            }
        }
    }
}