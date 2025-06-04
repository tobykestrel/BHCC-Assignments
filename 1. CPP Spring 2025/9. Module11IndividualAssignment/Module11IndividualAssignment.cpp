/*
Module Eleven Individual Assignment.
Toby Hansen, April 19 2025, CSC-120-WBL.
This program uses arrays to store and retrieve
information on the students in a class.
*/

#include <iostream>
#include <fstream> // For writing to file.
using namespace std;

// This section is for declaring function prototypes.
bool areAllIDsUnique(string studentArray[][3]);
bool containsNonNumbers(string s);
void dualPrintOutput(ostream& out2, string message);
int getIndexFromID(string (&studentArray)[5][3], string id);

// This is the main function.
int main() {

    // This code banner is printed before the code is run.
    cout<< "Module Eleven Individual Assignment.\n"
        << "Toby Hansen, April 19 2025, CSC-120-WBL.\n"
        << "This program uses arrays to store and retrieve\n"
        << "information on the students in a class.\n\n";

    // This section opens the studentgrade.txt file for writing to.
    ofstream studentData("studentgrade.txt");
    if (!studentData) {
        cout << "Error opening studentgrade.txt";
        return 1;
    }

    // This do-while loop ensures that the program is repeatable.
    // I chose the do-while loop specifically so that the program will always run at least once.
    do {

        // This section initializes the variables used throughout the program.
        int inpIndex, score, totalScoresSum = 0, lowestScore = 100, highestScore = 0, maxNameChars = 10;
        string inpID, lowestScoreName, highestScoreName, students[5][3] = {
            {"id", "name", "score"},
            {"id", "name", "score"},
            {"id", "name", "score"},
            {"id", "name", "score"},
            {"id", "name", "score"},
        };

        // This section gets input from the user for each student's information.
        for (int i = 0; i < sizeof(students) / sizeof(students[0]); i++) {

            // This section gets each student's ID.
            cout << "\nWhat is the ID of student " << i+1 << "? ";
            while (!(cin >> students[i][0]) || students[i][0].length() != 3 || containsNonNumbers(students[i][0]) || !areAllIDsUnique(students)) { // Loops until valid id input.
                cout << "Invalid input. Enter a unique three digit ID: ";
                cin.clear();
                cin.ignore(1000, '\n'); // Removes excess characters in buffer.
            }
            cin.clear();
            cin.ignore(1000, '\n'); // Removes excess characters in buffer.

            // This section gets each student's name.
            cout << "What is the name of student " << i+1 << "? ";
            while (!(cin >> students[i][1]) || students[i][1].length() < 1 || students[i][1].length() > maxNameChars) { // Loops until valid name input.
                cout << "Invalid input. Enter a name between 2-" << maxNameChars << "characters: ";
                cin.clear();
                cin.ignore(1000, '\n'); // Removes excess characters in buffer.
            }
            cin.clear();
            cin.ignore(1000, '\n'); // Removes excess characters in buffer.

            // This section gets each student's score.
            cout << "What is the score of student " << i+1 << "? ";
            while (!(cin >> score) || score < 0 || score > 100) { // Loops until valid score input.
                cout << "Invalid input. Enter a score between 0-100: ";
                cin.clear();
                cin.ignore(1000, '\n'); // Removes excess characters in buffer.
            }
            students[i][2] = to_string(score);
            totalScoresSum += score;
            cin.clear();
            cin.ignore(1000, '\n'); // Removes excess characters in buffer.

           // This section calculates the lowest and highest scores.
            if(score < lowestScore) { // This section calculates the lowest score.
                lowestScore = score;
                lowestScoreName = students[i][1];
            } else if(score > highestScore) { // This section calculates the highest score.
                highestScore = score;
                highestScoreName = students[i][1];
            }

        }

        // This section outputs the student's information to the console as well as the student data text file.
        dualPrintOutput(studentData, "\nStudent information is as follows: \n");
        for (int i = 0; i < sizeof(students) / sizeof(students[0]); i++) {
            dualPrintOutput(studentData, students[i][0] + " - " + students[i][1] + string(maxNameChars - students[i][1].length(), ' ') + " - " + students[i][2] + "%\n");
        }
        cout << "Average score: " << totalScoresSum / (sizeof(students)/sizeof(students[0])) << "%\n";
        cout << "Lowest score: " << lowestScore << "% by " << lowestScoreName << "\n";
        cout << "Highest score: " << highestScore << "% by " << highestScoreName << "\n\n";

        // This section prompts the user to enter a student ID to display that students's name and score.
        do {
            // This section gets input from the user on the ID of the student they wish to view the score of.
            cout << "Enter a student ID to view their score: ";
            while (!(cin >> inpID) || getIndexFromID(students, inpID) == -1) { // Loops until valid ID input.
                cout << "Invalid ID input. Try again: ";
                cin.clear();
                cin.ignore(1000, '\n'); // Removes excess characters in buffer.
            }
            cin.clear();
            cin.ignore(1000, '\n'); // Removes excess characters in buffer.
            inpIndex = getIndexFromID(students, inpID);

            // This section displays the student's score based on the ID given beforehand.
            cout << students[inpIndex][1] << ": " << students[inpIndex][2] << "%\n";

            // This section restarts the program if the user wants to input information for 5 more students.
            cout << "\nDo you want to see another student's score? (y/n): ";
        } while (cin.get() == 'y');
        cin.clear();
        cin.ignore(1000, '\n');

        // This section restarts the program if the user wants to input information for 5 more students.
        cout << "\nDo you want to input information for another 5 students? (y/n): ";
    } while (cin.get() == 'y');

    studentData.close();
    return 0;
}

// This function takes two input parameters, and does not return anything.
//    P1. An output stream to output the message alongside cout.
//    P2. The string message to be output.
// I was not expecting this to work, but apparently streams can be passed as variables to functions.
void dualPrintOutput(ostream& out2, string message) {
    cout << message;
    out2 << message;
}

// This function takes the input of a string and returns a
// bool of whether or not the string contains non-numbers.
bool containsNonNumbers(string s) {
    for (char c : s) {
        if (!isdigit(c)) return true;
    }
    return false;
}

// This function takes the students array as the input parameter 
// and returns a boolean of whether or not all the IDs are unique.
bool areAllIDsUnique(string studentArray[][3]) {
    for (int i = 0; i < sizeof(studentArray) / sizeof(studentArray[0]); i++) {
        for (int j = 0; j < sizeof(studentArray) / sizeof(studentArray[0]); j++) {
            if (studentArray[i][0] == studentArray[j][0]) return false; // Duplicate ID was found.
        }
    }
    return true; // No duplicate IDs were found.
}

// This function takes two paramters, the students array, and an id to validate.
// An int is returned of the index that the id was found in. If the id wasn't found, -1 is returned.
int getIndexFromID(string (&studentArray)[5][3], string inputID) {
    for (int i = 0; i < sizeof(studentArray) / sizeof(studentArray[0]); i++) {
        if (studentArray[i][0] == inputID) return i;
    }
    return -1; // Id is not valid.
}