/*
Module Twelve Group Project.
Toby Hansen, April 27 2025, CSC-120-WBL.
This program accesses and analyzes student data from a file.
*/

#include <iostream>
#include <fstream> // For writing to file.
#include <iomanip>  // For aligned output.
using namespace std;

// This section is for declaring function prototypes and global variables.
const int g_studentAmount = 4;
const string g_studentGradeFile = "studentgrade.txt";
bool areAllIDsUnique(int idArray[]);
int getIndexFromID(int idArray[], int inputID);

// This is the main function.
int main() {

    // This code banner is printed before the code is run.
    cout<< "Module Twelve Group Project.\n"
        << "Toby Hansen, April 27 2025, CSC-120-WBL.\n"
        << "This program accesses and analyzes student data from a file.\n\n";

    // This do-while loop ensures that the program is repeatable.
    // I chose the do-while loop specifically so that the program will always run at least once.
    do {
        
        // This section opens the studentgrade.txt file for writing to.
        ifstream studentData(g_studentGradeFile);
        if (!studentData) {
            cout << "Error opening studentgrade.txt";
            return 1;
        }
        string headerLine;
        getline(studentData, headerLine); // This skips the first line which just holds the column headers.
    

        // This section initializes the variables used throughout the program.
        int studentID[g_studentAmount], quiz1[g_studentAmount], quiz2[g_studentAmount], midterm[g_studentAmount], final[g_studentAmount]; // File read in values.
        int totalQuiz1 = 0, totalQuiz2 = 0, totalMidterm = 0, totalFinal = 0, totalStudent[g_studentAmount] = {}; // Totals by quiz/exam and each student.
        int highestFinal = -1, highestFinalIDs[g_studentAmount] = {}, amountOfHighestFinalIDs = 0; // Highest scores on the final exam.
        int lowestFinal = 101, lowestFinalIDs[g_studentAmount] = {}, amountOfLowestFinalIDs = 0; // Lowest scores on the final exam.
        int inpID, inpIndex; // Student score search variables.

        // This section gets input from the student grade file for each student's ID and scores, and then prints it to console.
        cout << setw(5) << "StuID" << setw(9) << right << "Quiz1" << setw(9) << right << "Quiz2" << setw(9) << right << "Midterm" << setw(9) << right << "Final\n";
        for (int i = 0; i < g_studentAmount; i++) {

            // This section gets each student's ID and detects invalid id input.
            if (!(studentData >> studentID[i]) || to_string(studentID[i]).length() != 3 || !areAllIDsUnique(studentID)) {
                cout << "Invalid ID detected on line " << i+2 << " in file " << g_studentGradeFile;
                exit(0);
            }

            // This section gets each student's quiz 1 score and detects invalid score input.
            if (!(studentData >> quiz1[i]) || quiz1[i] < 0 || quiz1[i] > 100) {
                cout << "Invalid Quiz 1 score detected on line " << i+2 << " in file " << g_studentGradeFile;
                exit(0);
            }
            totalQuiz1 += quiz1[i];
            totalStudent[i] += quiz1[i];

            // This section gets each student's quiz 2 score and detects invalid score input.
            if (!(studentData >> quiz2[i]) || quiz2[i] < 0 || quiz2[i] > 100) {
                cout << "Invalid Quiz 2 score detected on line " << i+2 << " in file " << g_studentGradeFile;
                exit(0);
            }
            totalQuiz2 += quiz2[i];
            totalStudent[i] += quiz2[i];
            
            // This section gets each student's midterm score and detects invalid score input.
            if (!(studentData >> midterm[i]) || midterm[i] < 0 || midterm[i] > 100) {
                cout << "Invalid Midterm score detected on line " << i+2 << " in file " << g_studentGradeFile;
                exit(0);
            }
            totalMidterm += midterm[i];
            totalStudent[i] += midterm[i];

            // This section gets each student's final score and detects invalid score input.
            if (!(studentData >> final[i]) || final[i] < 0 || final[i] > 100) {
                cout << "Invalid Final score detected on line " << i+2 << " in file " << g_studentGradeFile;
                exit(0);
            }
            totalFinal += final[i];
            totalStudent[i] += final[i];

            // This section displays each student's ID and all their quiz and exam scores.
            cout<< setw(5) << studentID[i] << setw(9) << quiz1[i] << setw(9) << quiz2[i] << setw(9) << midterm[i] << setw(8) << final[i] << "\n";
        }

        // This section calculates and displays the averages for each exam up to two decimals.
        cout<< "\n   Test   Average" << fixed << setprecision(1)
            << "\n Quiz 1      " << (double)totalQuiz1/g_studentAmount
            << "\n Quiz 2      " << (double)totalQuiz2/g_studentAmount
            << "\nMidterm      " << (double)totalMidterm/g_studentAmount
            << "\n  Final      " << (double)totalFinal/g_studentAmount << "\n\n";

        // This section calculate and displays the total and average score for each student.
        cout << setw(5) << "StuID" << setw(9) << right << "Total" << setw(9) << right << "Average\n";
        for (int i = 0; i < g_studentAmount; i++) cout << setw(5) << studentID[i] << setw(9) << totalStudent[i] << setw(8) << (double)totalStudent[i]/4 << "\n";

        // This section calculates and displays the lowest and highest scores on the final exam.
        for (int i = 0; i < g_studentAmount; i++) {
            if (final[i] > highestFinal) {
                highestFinal = final[i];
                for (int j = 0; j < g_studentAmount; j++) highestFinalIDs[i] = 0;
                amountOfHighestFinalIDs = 0;
                highestFinalIDs[amountOfHighestFinalIDs++] = studentID[i];
            } else if (final[i] == highestFinal) {
                highestFinalIDs[amountOfHighestFinalIDs++] = studentID[i];
            }
            if (final[i] < lowestFinal) {
                lowestFinal = final[i];
                for (int j = 0; j < g_studentAmount; j++) lowestFinalIDs[i] = 0;
                amountOfLowestFinalIDs = 0;
                lowestFinalIDs[amountOfLowestFinalIDs++] = studentID[i];
            } else if (final[i] == lowestFinal) {
                lowestFinalIDs[amountOfLowestFinalIDs++] = studentID[i];
            }
        }
        cout << "\nHighest score on the final exam: " << highestFinal << "% by ";
        for (int i = 0; highestFinalIDs[i] != 0; i++) {
            if (i != 0) cout << ", ";
            cout << highestFinalIDs[i];
        }
        cout << "\n Lowest score on the final exam: " << lowestFinal << "% by ";
        for (int i = 0; lowestFinalIDs[i] != 0; i++) {
            if (i != 0) cout << ", ";
            cout << lowestFinalIDs[i];
        }

        // This section prompts the user to enter a student ID to display that students's scores.
        do {
            // This section gets input from the user on the ID of the student they wish to view the score of.
            cout << "\n\nEnter a student ID to view their score: ";
            while (!(cin >> inpID) || getIndexFromID(studentID, inpID) == -1) { // Loops until valid ID input.
                cout << "Invalid ID input. Try again: ";
                cin.clear();
                cin.ignore(1000, '\n'); // Removes excess characters in buffer.
            }
            cin.clear();
            cin.ignore(1000, '\n'); // Removes excess characters in buffer.
            inpIndex = getIndexFromID(studentID, inpID);

            // This section displays the student's score based on the ID given beforehand.
            cout<< "\n    Test    Scores" 
                << "\n  Quiz 1       " << quiz1[inpIndex]
                << "\n  Quiz 2       " << quiz2[inpIndex]
                << "\n Midterm       " << midterm[inpIndex]
                << "\n   Final       " << final[inpIndex];

            // This section allows the user to chose to view another student's score.
            cout << "\n\nDo you want to see another student's score? (y/n): ";
        } while (cin.get() == 'y');
        cin.clear();
        cin.ignore(1000, '\n');

        studentData.close();

        // This section restarts the program if the user wants to.
        cout << "\nDo you want to run the program again? (y/n): ";
    } while (cin.get() == 'y');

    return 0;
}

// This function takes the studentID array as the input parameter 
// and returns a boolean of whether or not all the IDs are unique.
bool areAllIDsUnique(int idArray[]) {
    for (int i = 0; i < g_studentAmount - 1; i++) {
        for (int j = i + 1; j < g_studentAmount; j++) {
            if (idArray[i] == idArray[j]) return false; // Duplicate ID was found.
        }
    }
    return true; // No duplicate IDs were found.
}

// This function takes two paramters, the students array, and an id to validate.
// An int is returned of the index that the id was found in. If the id wasn't found, -1 is returned.
int getIndexFromID(int idArray[], int inputID) {
    for (int i = 0; i < g_studentAmount; i++) {
        if (idArray[i] == inputID) return i;
    }
    return -1; // ID is not valid.
}