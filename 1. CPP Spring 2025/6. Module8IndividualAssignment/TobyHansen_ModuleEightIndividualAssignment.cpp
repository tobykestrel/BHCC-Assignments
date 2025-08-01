/*
Module Eight Individual Assignment.
Toby Hansen, March 30 2025, CSC-120-WBL.
This program reads a file of student scores and outputs the: 
highest, lowest, average, and amounts of valid/invalid scores. 

Algorithm Design:
- Read student_scores.txt file using a while loop.
    - If the score is invalid (not a number 0-100) then skip it and add 1 to invalidScores. Otherwise:
        - Add the score to the totalPoints counted, and add 1 to the the totalScores counted.
        - If it's higher than the current highestScore, make it the new highestScore.
        - If it's lower than the current lowestScore, make it the new lowestScore.
- Get the averageScore by dividing the totalPoints by the totalScores.
- Output the totalScores, highestScore, lowestScore, averageScore, and invalidScores to summary_report.txt file.
*/

#include <iostream>
#include <fstream>
using namespace std;

int main() {

    // This code banner is printed before the code is run.
    cout<< "Module Eight Individual Assignment.\n"
        << "Toby Hansen, March 30 2025, CSC-120-WBL.\n"
        << "This program reads a file of student scores and outputs the:\n"
        << "highest, lowest, average, and amounts of valid/invalid scores.";

    // This do-while loop ensures that the program is repeatable.
    // I chose the do-while loop specifically so that the program will always run at least once.
    do {

        // This section declares the variables used throughout the program.
        double averageScore;
        int highestScore = 0, lowestScore = 100, validScores = 0, invalidScores = 0, totalPoints = 0, currentScore;
        string fileName;
        fstream fileReaderWriter;

        // This section validates that the student scores file was opened correctly. 
        // If not, the user is asked for the correct file until it opens successfully.
        fileName = "student_scores.txt";
        fileReaderWriter.open(fileName);
        while (!fileReaderWriter) {
            cout << "Error: Unable to open " << fileName << " Please enter the correct file name: ";
            cin >> fileName;
            fileReaderWriter.clear(); // Clear the unsuccessfully opened file.
            fileReaderWriter.open(fileName); // Attempt to open the new file.
        }

        // This section reads all the student scores from the designated file and calculates:
        // The highest, lowest, amount of valid scores, and amount of invalid scores.
        string line;
        while (getline(fileReaderWriter, line)) { 
            currentScore = stoi(line);
            // If the current score is invalid, add 1 to the total invalid scores and skip to the next score.
            if (currentScore < 0 || currentScore > 100) {
                invalidScores++;
            } else { // Otherwise...
                // Add 1 to the total valid scores and add the score's points 
                // to the total tally in order to calculate the average later.
                validScores++;
                totalPoints += currentScore;
                // If the current score is higher than the current highest score,
                // then set the highest score to the current score.
                if (currentScore > highestScore) {
                    highestScore = currentScore;
                }
                // If the current score is lower than the current lowest score,
                // then set the lowest score to the current score.
                if (currentScore < lowestScore) {
                    lowestScore = currentScore;
                }
            }
        }
        fileReaderWriter.close();

        // This section validates that the summary report file was opened correctly. 
        // If not, the user is asked for the correct file until it opens successfully.
        fileName = "summary_report.txt";
        fileReaderWriter.open(fileName);
        while (!fileReaderWriter) {
            cout << "Error: Unable to open " << fileName << " Please enter the correct file name: ";
            cin >> fileName;
            fileReaderWriter.clear(); // Clear the unsuccessfully opened file.
            fileReaderWriter.open(fileName); // Attempt to open the new file.
        }
        
        // This section checks that there were infact valid scores in the student scores file.
        // If there were valid scores, a summary report is written to the summary report file.
        // If there were no valid scores (or the file was empty), 
        // then a message letting the user know is written to the summary report file. 
        if (validScores > 0) {
            averageScore = totalPoints/validScores; // Calculates the average score.
            fileReaderWriter << "<-Summary Report for Student Scores->"
                            << "\nAmount of  valid  scores tallied: " << validScores
                            << "\nAmount of invalid scores ignored: " << invalidScores
                            << "\nHighest Score: " << highestScore
                            << "\nLowest  Score: " << lowestScore
                            << "\nAverage Score: " << (int)(averageScore * 100) / 100;
        } else { 
            fileReaderWriter<< "Error: There were no valid scores in the designated student scores file.";
        }
        fileReaderWriter.close();

        // This section restarts the program if the user wants to calculate another factorial. 
        cout << "\nDo you want to do another calculation? (y/n): ";
        cin.clear();
        cin.ignore(1000, '\n');
    } while (cin.get() == 'y');

    return 0;
}

/*
Additional Questions: 
- Why did you choose the specific type of loops for this task?
    I chose a do-while loop for the all-encompassing loop so that no matter what the program would run at least once.
    After the first execution, the while conditional checks the user's input to see if the program should run again.abort
    I chose to use while loops three times, each because a conditional needed to be met before the code could run even once.
    The first and third time I used a while loop it was to validate the designated reading and writing files. It would make
    no sense to send an error message and ask for a new file if the given file is working just fine, so it only triggers the
    code if something is wrong in the first place. The second time I used a while loop, it was to read in each line from the
    student scores file. It's not garunteed that there would be any lines however, so there needs to be the conditional before
    any execution of the code can occur.
- How does your code handle edge cases, such as an empty file or invalid scores?
    Invalid scores are ignored in the final tallies with an if statement checking that the score is between 0-100.
    In case of an empty file or no valid scores, an error message is sent to the summary report file in place of a report.
- What challenges did you encounter in writing this program, and how did you overcome them?
    I ran into a problem when I was trying to figure out how to calculate the average score when I realized that built 
    in functions were not allowed like min() and max(). Specifically I was going to use round() to get the double rounded
    to two decimals, but then I remembered something I did in a previous assignment to calculate accurate double modulo
    without the built in modulo function: type casting and standard arithemtic operations. Just like how I used (int) to
    floor in that past assignment, I could use it here to floor the average score multiplied by a hundred, then divide it
    again by a hundred to get a perfectly truncated average of just two decimal places.
*/