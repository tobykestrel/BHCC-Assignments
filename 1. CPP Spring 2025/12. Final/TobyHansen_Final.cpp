/*
Final Project. Individual Contribution.
Toby Hansen, May 9 2025, CSC-120-WBL.
This program calcaulates a student's final grade for a 
course with assignment weight taken into consideration.
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <vector>
using namespace std;

// This section is for declaring function prototypes.
void loadSyllabus(ifstream &inputStream, string &fileName, vector<int> &weightages, vector<string> &courseParts);
void gradeStudent(ofstream &outputStream, vector<int> &studentScores, string &studentName, vector<int> &weightages, vector<string> &courseParts);

// This is the main function.
int main() {

    // This code banner is printed before the code is run.
    cout<< "Final Project. Individual Contribution.\n"
        << "Toby Hansen, May 9 2025, CSC-120-WBL.\n"
        << "This program calcaulates a student's final grade for a \n"
        << "course with assignment weight taken into consideration.\n\n";

    // This section is for declaring variables used throughout the program.
    ifstream inputStream;
    ofstream outputStream;
    vector<vector<int>> studentScores;
    vector<int> weightages;
    vector<string> courseParts, studentNames;
    string fileName, line;
    int amountOfStudents;

    // This section opens the syllabus file for reading from.
    cout << "Enter the filename of the syllabus being used: ";
    getline(cin, fileName);
    loadSyllabus(inputStream, fileName, weightages, courseParts);

    // This section gets each student's information from their score files and reads into the appropriate vectors.
    cout << "How many students do you have? ";
    while (!(cin >> amountOfStudents) || amountOfStudents > 3 || amountOfStudents < 1) {
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid input. Enter an amount of students 1-3: ";
    }
    for (int i = 0; i < amountOfStudents; i++) {
        inputStream.open("Student#" + to_string(i+1) + ".txt");
        if (!inputStream) {
            cout << "Student " << i+1 << "'s scores could not be opened. Skipping.\n";
        } else {
            cout << "\nStudent#" << i+1 << ".txt is being analyzed.\n";

            // This section adds the name at the top of each student's file to the ordered name vector.
            getline(inputStream, line);
            while(line[0] == ' ' || line[0] == '\t') line.erase(0,1); // This erases any trailing whitespace like spaces and tabs.
            studentNames.push_back(line); 

            // This section adds the scores from each student's file to the ordered scores vector.
            studentScores.push_back({});
            while (getline(inputStream, line)) {
                if (!line.empty()) {
                    studentScores[i].push_back(stoi(line));
                }
            }

            // This section grades the student, and outputs their report to a corresponding file.
            gradeStudent(outputStream, studentScores[i], studentNames[i], weightages, courseParts);
            cout << studentNames[i] << " has been graded, which can be seen in their corresponding file.\n";
        }

        // Close the student's score file.
        inputStream.close();
    }
    cout << "Press enter to continue . . . ";
    cin.ignore();
    cin.get();
    return 0;
}

// This function takes a string as input, and loads a syllabus with the filename of that string.
// If the file doesn't exist, the user is continuously prompted to enter a valid filename.
// After a valid syllabus file is opened, the weightages are read into the global weightages vector.
// Input: input stream for reading from a file, file name of the file to read from, 
// int vector for grading weight percentages, string vector for course part titles.
void loadSyllabus(ifstream &inputStream, string &fileName, vector<int> &weightages, vector<string> &courseParts) {

    // This function opens the syllabus file for reading from. 
    // If the user gives a filename that cannot be opened, they are prompted again until a valid filename is given.
    inputStream.open(fileName);
    while (!inputStream) {
        cout << "A syllabus file with that name could not be found.\nEnter the filename of the syllabus being used: ";
        getline(cin, fileName);
        inputStream.open(fileName);
    } 
    cout << fileName << " opened successfully. Syllabus is being analyzed.\n";

    // This section reads the weightages from the syllabus file and puts them in the global weightages vector.
    string line;
    while (getline(inputStream, line)) {
        if (!line.empty()) {
            // This section finds the position of the '%' character.
            int percentIndex = -1;
            for (int i = 0; i < line.length(); i++) if (line[i] == '%') percentIndex = i;
    
            // If the % symbol could not be found, let the user know and exit the program.
            if (percentIndex == -1) {
                cout << fileName << " is not a properly formatted syllabus. A % symbol is required at the end of each line to denote the amount each section contributes to the overall grade.";
                exit(0);
            } else { // If the % symbol was found, move backward to find the beginning of the number and store it in the global weightages vector.
                int numberIndex = percentIndex - 1;
                while (numberIndex - 1 < 0 || isdigit(line[numberIndex - 1])) numberIndex--;
                weightages.push_back(stoi(line.substr(numberIndex, percentIndex - numberIndex)));
            }
    
            // This section saves the course part title.
            string coursePart = "";
            for (int i = 0; i < line.length(); i++) {
                if (line[i] == ' ' || line[i] == '\t') {
                    if (line[i+1] != ' ' && line[i+1] != '\t') break;
                } else {
                    coursePart += line[i];
                }
            }
            courseParts.push_back(coursePart);
        }
    }

    // Close the syllabus file.
    inputStream.close();
    cout << "This course has " << weightages.size() << " parts.\n\n";
}

// This function grades a student. It outputs the information to a file with the student's name as the filename.
// Input: output stream for writing to a file, student scores to grade in an int vector, the student's name as a string,
// int vector for grading weight percentages, and the corresponding string vector for course part titles.
void gradeStudent(ofstream &outputStream, vector<int> &studentScores, string &studentName, vector<int> &weightages, vector<string> &courseParts) {
    outputStream.open(studentName + ".txt");
    outputStream << studentName << "'s results\n\n\t" << left << setw(20) << "COURSE PART" << right << setw(8) << "WEIGHT" << setw(8) << "GRADE" << setw(18) << "POINTS EARNED\n\n";
    double courseGrade = 0;
    for (int i = 0; i < courseParts.size(); i++) {
        double pointsEarned = ((double)weightages[i]/100.0)*studentScores[i];
        courseGrade += pointsEarned;
        outputStream<< "\t" << left << setw(20) << courseParts[i] 
                    << right << setw(5) << weightages[i] << "%" 
                    << setw(9) << studentScores[i] 
                    << setw(13) << fixed << setprecision(1) << pointsEarned << "\n";

    }
    
    // The student passes the course if they get a 70 or higher for their overall course grade.
    outputStream << "\nCourse grade is " << courseGrade << "%\n";
    if (courseGrade >= 70) {
        outputStream << studentName << " PASSED this course";
    } else {
        outputStream << studentName << " FAILED this course";
    }
    outputStream.close();
}