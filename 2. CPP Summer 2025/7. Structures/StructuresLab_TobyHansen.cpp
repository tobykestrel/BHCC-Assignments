/*
Toby Hansen, July 15 2025.
Structures Lab, CSC-237-200.
This program uses dynamic memory allocation 
to control an array of movie data structs.
*/

#include <iostream>
#include <iomanip>
using namespace std;

// This struct contains data for a movie including title, director, release year, and runtime.
struct MovieData {
	string title; // Movie Title.
	string director; // Movie Director.
	int yearReleased; // Year Released.
	double runningTime; // Running time in minutes.
};

// This section is for declaring function prototypes.
void displayMovie(MovieData *moviePtr);
void populateMovieDataArray(MovieData *arrayPtr, int arraySize);
void displayMovieDataArray(MovieData *arrayPtr, int arraySize);
MovieData *findLongestMovie(MovieData *arrayPtr, int arraySize);

// This is the main function.
int main() {

    // This code banner is printed before the code is run.
    cout<< "Toby Hansen, July 15 2025.\n"
        << "Structures Lab, CSC-237-200.\n"
        << "This program uses dynamic memory allocation\n"
        << "to control an array of movie data structs.\n\n";

    // This section creates an array of the user's desired size.
    int arraySize;
    cout << "Enter desired array size: ";
    while (!(cin >> arraySize)) { // While the input is invalid:
        cin.clear(); // Clear error message.
        cin.ignore(10000, '\n');
        cout << "Invalid input. Enter again: "; // Let the user know and ask again.
    }
    cin.ignore(10000, '\n');
	MovieData* arrayPtr = new MovieData[arraySize];
	cout << "arrayPtr = " << setw(16) << setfill('0') << hex << uppercase << (unsigned long long)(size_t)arrayPtr << endl;

	// This section populates and displays the movie data array.
	populateMovieDataArray(arrayPtr, arraySize);
	displayMovieDataArray(arrayPtr, arraySize);

	// This section finds and displays the longest movie.
	cout << "\nLongest Movie in the list:";
	MovieData *longestMovie = findLongestMovie(arrayPtr, arraySize);
	displayMovie(longestMovie);
	cout << "\nLongest Movie is: " << longestMovie->runningTime << " minutes long\n";

	// De-allocate the memory of arrayPtr.
	delete[] arrayPtr;
	cout << "DELETED array at arrayPtr = " << setw(16) << setfill('0') << hex << uppercase << (unsigned long long)(size_t)arrayPtr << "\n\n";

    // Finishes up the program.
    system("pause"); // Wait for user input.
    return 0; // End the program
}

// This function displays the data of a single movie.
void displayMovie(MovieData *moviePtr) {
	cout<< "\nTitle   : " << moviePtr->title
		<< "\nDirector: " << moviePtr->director
		<< "\nReleased: " << moviePtr->yearReleased
		<< "\nRuntime : " << moviePtr->runningTime << " minutes\n";
}

// This functions populates the movie array with entries and their title, director, release year, and run time.
void populateMovieDataArray(MovieData *arrayPtr, int arraySize) {
	for (int i = 0; i < arraySize; i++) {
		// This section gets the title of the movie.
		cout << "Enter Title " << i << ": ";
		getline(cin, arrayPtr[i].title);
		
		// This section gets the director of the movie.
		cout << "Enter Director " << i << ": ";
		getline(cin, arrayPtr[i].director);

		// This section gets the release year of the movie.
		cout << "Enter Year Released " << i << ": ";
		while (!(cin >> arrayPtr[i].yearReleased)) { // While the input is invalid:
			cin.clear(); 
			cin.ignore(10000, '\n');
			cout << "Invalid input. Enter again: "; // Let the user know and ask again.
		}
		cin.ignore(10000, '\n');

		// This section gets the running time in minutes of the movie.
		cout << "Enter running time (minutes) " << i << ": ";
		while (!(cin >> arrayPtr[i].runningTime)) { // While the input is invalid:
			cin.clear(); 
			cin.ignore(10000, '\n');
			cout << "Invalid input. Enter again: "; // Let the user know and ask again.
		}
		cin.ignore(10000, '\n');
	}
}

// This function displays all the movies in the movies array.
void displayMovieDataArray(MovieData *arrayPtr, int arraySize) {
	for (int i = 0; i < arraySize; i++) {
		cout << endl << setw(16) << setfill('0') << hex << uppercase << (unsigned long long)(size_t)&arrayPtr[i];
		cout << ": arrayPtr[" << setfill(' ') << dec << i << "] = ";
		displayMovie(&arrayPtr[i]);
	}
}

// This function finds and returns the longest movie in the movies array.
MovieData *findLongestMovie(MovieData *arrayPtr, int arraySize) {
	MovieData *longestSoFar = &arrayPtr[0];
	for (int i = 1; i < arraySize; i++) {
		if (arrayPtr[i].runningTime > longestSoFar->runningTime) {
			*longestSoFar = arrayPtr[i];
		}
	}
	return longestSoFar;
}