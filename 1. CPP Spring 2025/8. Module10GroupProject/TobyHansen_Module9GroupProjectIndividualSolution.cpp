/*
Module Nine Group Project. Individual Solution.
Toby Hansen, April 13 2025, CSC-120-WBL.
This program acts as a Math Tutor, preparing
quizzes for the user based on their input.
*/

#include <iostream>
#include <fstream> // For writing to file.
#include <cstdlib> // For rand() and srand().
#include <ctime>   // For time().
using namespace std;

// This section is for declaring function prototypes.
void dualPrintOutput(ostream& out2, string message);
string cleanDouble(double num);

// This is the main function.
int main() {

    // This code banner is printed before the code is run.
    cout<< "Module Nine Group Project. Individual Solution.\n"
        << "Toby Hansen, April 13 2025, CSC-120-WBL.\n"
        << "This program acts as a Math Tutor, preparing\n"
        << "quizzes for the user based on their input.\n\n";

    // This section opens the report.txt file for writing to.
    ofstream report("report.txt");
    if (!report) {
        cout << "Error opening report.txt";
        return 1;
    }

    // This do-while loop ensures that the program is repeatable.
    // I chose the do-while loop specifically so that the program will always run at least once.
    do {

        // This section gets the user to input which type of quiz should be prepared.
        cout<< "Which of the following areas do you want to focus on?\n"
            << " 1]  Addition\n"
            << " 2]  Subtraction\n"
            << " 3]  Multiplication\n"
            << " 4]  Integer Division\n"
            << " 5]  Real Division\n"
            << " 6]  Modulo\n"
            << " 7]  Addition and Subtraction\n"
            << " 8]  Addition, Subtraction, and Multiplication\n"
            << " 9]  Addition, Subtraction, Multiplication, and Integer Division\n"
            << "10]  All Operators\n"
            << "11]  End Program\n";
        int focus = 0;
        while (!(cin >> focus) || focus < 1 || focus > 11) { // Loops until valid number input.
            cout << "Invalid input. Enter a menu option between 1-11: ";
            cin.clear();
            cin.ignore(1000, '\n'); // Removes excess characters in buffer.
        }
        cin.clear();
        cin.ignore(1000, '\n'); // Removes excess characters in buffer.

        // This section exits the program if the user inputted 11 (End Program option)
        if (focus == 11) {
            cout << "End of Program.";
            return 0;
        }

        // This section gets the user to input how many questions should be in the quiz.
        cout<< "How many questions should the quiz have?\n";
        int totalQuestions = 0;
        while (!(cin >> totalQuestions) || totalQuestions < 1 || totalQuestions > 100) { // Loops until valid number input.
            cout << "Invalid input. Enter an amount of questions between 1-100: ";
            cin.clear();
            cin.ignore(1000, '\n'); // Removes excess characters in buffer.
        }
        cin.clear();
        cin.ignore(1000, '\n'); // Removes excess characters in buffer.

        // This section generates the quiz with random questions.
        // A switch satement while loop was used despite the primitivity because using arrays and enums are not yet allowed.
        string questionOperators = "";
        srand(time(0));
        while (questionOperators.size() < totalQuestions) {
            int randomType = rand() % 6; // Random number from 0 to 5
            switch (randomType) {
                case 1: // Addition
                    if (focus == 1 || focus > 6) questionOperators += '+';
                    break;
                case 2: // Subtraction
                    if (focus == 2 || focus > 6) questionOperators += '-';
                    break;
                case 3: // Multiplication
                    if (focus == 3 || focus > 7) questionOperators += '*';
                    break;
                case 4: // Integer Division
                    if (focus == 4 || focus > 8) questionOperators += '/';
                    break;
                case 5: // Real Division
                    if (focus % 5 == 0) questionOperators += 'd';
                    break;
                case 6: // Modulo
                    if (focus == 6 || focus == 10) questionOperators += '%';
                    break;
            }
        }

        // This section asks each question, and tallies up the score.
        int totalCorrectAnswers = 0;
        int totalPartiallyCorrectAnswers = 0;
        time_t currentTime = time(0);
        dualPrintOutput(report, "\n" + string(asctime(localtime(&currentTime))) + "====== Start of Quiz ======\n");
        for (int i = 0; i < totalQuestions; i++) {

            // This section picks two operands and calculates the answer.
            // A switch statement is used here despite the primitivity because using arrays are not yet allowed.
            int operand1 = (rand() % 99) + 1; // Random number from 1 to 99
            int operand2 = (rand() % 99) + 1; // Random number from 1 to 99
            double correctAnswer;
            string questionType;
            switch(questionOperators[i]) {
                case '+': // Addition
                    correctAnswer = operand1 + operand2;
                    questionType = "Addition";
                    break;
                case '-': // Subtraction
                    correctAnswer = operand1 - operand2;
                    questionType = "Subtraction";
                    break;
                case '*': // Multiplication
                    correctAnswer = operand1 * operand2;
                    questionType = "Multiplication";
                    break;
                case '/': // Integer Division
                    correctAnswer = int(operand1 / operand2);
                    questionType = "Integer Division";
                    break;
                case 'd': // Real Division
                    correctAnswer = operand1 / double(operand2);
                    correctAnswer = int(correctAnswer * 100) / 100.0;  // Truncate answer to 2 decimal places.
                    questionType = "Real Division, truncate answer to two decimals";
                    break;
                case '%': // Modulo
                    correctAnswer = operand1 % operand2;
                    questionType = "Modulo";
                    break;
            }

            /* This section outputs the question.
            Intended question design:
            "Question 10/10 (Question Type):"
            "                10   "
            "              + 10   "
            "             ______  "
            "First attempt:  "
            */
            dualPrintOutput(report, "\n> Question " + to_string(i + 1) + "/" + to_string(totalQuestions) + " (" + questionType + "):\n"
                + "                " + to_string(operand1) + "   \n"
                + "              " + questionOperators[i] + " " + to_string(operand2) + "   \n"
                + "             ______  \n"
                + "First attempt:  "
            );
            
            // This section gets the user's answer.
            double userAnswer;
            while (!(cin >> userAnswer)) { // Loops until valid number input.
                cout << "Invalid input, enter an answer to the question above.\nFirst attempt:  ";
                cin.clear();
                cin.ignore(1000, '\n'); // Removes excess characters in buffer.
            }
            cin.clear();
            cin.ignore(1000, '\n'); // Removes excess characters in buffer.
            report << userAnswer << "\n";

            // This section compares the user's answer to the correct answer. 
            // If the answer is incorrect, the user can answer again for partial credit.
            if (userAnswer == correctAnswer) {
                dualPrintOutput(report, "Congrats, that is the correct answer!\n");
                totalCorrectAnswers++;
            } else {
                dualPrintOutput(report, "Sorry, that's not the correct answer.\nSecond attempt: ");
                while (!(cin >> userAnswer)) { // Loops until valid number input.
                    cout << "Invalid input, enter an answer to the question above.\nSecond attempt: ";
                    cin.clear();
                    cin.ignore(1000, '\n'); // Removes excess characters in buffer.
                }
                cin.clear();
                cin.ignore(1000, '\n'); // Removes excess characters in buffer.
                report << userAnswer << "\n";

                if (userAnswer == correctAnswer) {
                    dualPrintOutput(report, "Good, that is the correct answer! Partial credit has been earned.\n");
                    totalPartiallyCorrectAnswers++;
                } else {
                    dualPrintOutput(report, "Not quite, the correct answer was actually: " + cleanDouble(correctAnswer) + "\n");
                }
            }
        }
        dualPrintOutput(report, "----- Results Section -----\nTotal Amount of Questions: " + to_string(totalQuestions) + "\n"
            + "First Try Correct Answers: " + to_string(totalCorrectAnswers) + "\n"
            + "Partially Correct Answers: " + to_string(totalPartiallyCorrectAnswers) + "\n"
            + "Overall Percent (%) Grade: " + cleanDouble(int(10000 * ((totalCorrectAnswers + 0.5 * totalPartiallyCorrectAnswers) / totalQuestions)) / 100.0) 
            + "%\n======= End of Quiz =======\n"
        );

        // This section restarts the program if the user wants to take another quiz
        cout << "\nDo you want to take another quiz? (y/n): ";
    } while (cin.get() == 'y');

    report.close();
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

// This function formats a doubles to be clean for printing.
// It takes one parameter, the double to be formatted, and returns the cleanly formatted version as a string.
// Exs:     50.0 -> 50,     12.255 -> 12.25,     0.001 -> 0,     15.60 -> 15.6
string cleanDouble(double num) {
    num = int(num * 100) / 100.0; // Truncate to 2 decimal places.
    string strNum = to_string(num); // Convert to string.

    // This section gets the index of the decimal (if applicable).
    int decimalIndex = -1;
    for (int i = 0; i < strNum.size(); i++) {
        if (strNum[i] == '.') {
            decimalIndex = i;
            break;
        }
    }

    // If there is a decimal, this section removes trailing zeroes and the decimal itself if necessary.
    if (decimalIndex != -1) {
        int endIndex = strNum.size() - 1;
        while (endIndex > decimalIndex && strNum[endIndex] == '0') {
            endIndex--;
        }
        if (endIndex == decimalIndex) {
            endIndex--;  // Remove the decimal point if nothing remains after.
        }
        strNum = strNum.substr(0, endIndex + 1);
    }

    return strNum;
}
