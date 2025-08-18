/*
Toby Hansen, July 8 2025.
Project 1, CSC-237-200.
This program packs and unpacks text
files from and into unsigned integers.
*/

#include <iostream>
#include <fstream>
using namespace std;

// This section is for declaring function prototypes.
void pack();
void unpack();
void help();

// This is the main function.
int main() {

    // This code banner is printed before the code is run.
    cout<< "Toby Hansen, July 8 2025.\n"
        << "Project 1, CSC-237-200.\n"
        << "This program packs and unpacks text\n"
        << "files from and into unsigned integers.\n\n";

	// This section is a command-loop repeating the program until the user decides to quit.
	while(true) {
		cout << "Command: ";
		switch (cin.get()) {
			case 'p': pack(); break; // Packs text to data file.
			case 'u': unpack(); break; // Unpacks packed data to text.
			case 'h': help(); break; // Displays the help text.
			case 'q': system("pause"); return 0; // Quits the program.
		}
	}
}

// This function packs text files to data files.
void pack() {
	// This section asks the user for the input file and opens it for reading from.
    ifstream inputFile;
	string inputFileName;
	cout << "Enter the input filename: ";
	cin >> inputFileName;
	inputFile.open(inputFileName);
	while (!inputFile) { // While the input file is invalid:
		cin.clear(); 
		cin.ignore(10000, '\n'); 
		cout << "Error opening \"" << inputFileName << "\"!\n"; 
		cout << "Enter the input filename: "; 
		cin >> inputFileName; 
		inputFile.open(inputFileName); 
	} 
	
	// This section asks the user for the output file and opens it for writing to.
    ofstream outputFile;
	string outputFileName;
	cout << "Enter the output filename: ";
	cin >> outputFileName;
	outputFile.open(outputFileName);
	while (!outputFile) { // While the output file is invalid:
		cin.clear(); 
		cin.ignore(10000, '\n'); 
		cout << "Error opening \"" << outputFileName << "\"!\n"; 
		cout << "Enter the output filename: "; 
		cin >> outputFileName; 
		outputFile.open(outputFileName); 
	} 

	// This section reads each line from the inputFile to the outputFile as packed data.
	string inputLine;
	unsigned int outputLine = 0;
	while (getline(inputFile, inputLine)) {
		cout << "Input text (length=" << inputLine.length() << "): " << inputLine << endl;
		inputLine += "\n";
		for (int linePos = 0; linePos < inputLine.length(); linePos++) {
			outputLine <<= 8;
			outputLine |= inputLine[linePos];
			if (linePos % 4 == 3) {
				outputFile << outputLine << endl;
				outputLine = 0;
			} else if (linePos == inputLine.length()-1) {
				while (linePos % 4 != 3) {
					outputLine <<= 8;
					outputLine |= 0x00;
					linePos++;
				}
				outputFile << outputLine << endl;
			}
		}
		outputFile << endl;
	}
	cout << endl;

	// This section closes the input and output files.
	inputFile.close();
	outputFile.close();
}

// This function unpacks data files to text files.
void unpack() {
	// This section asks the user for the input file and opens it for reading from.
    ifstream inputFile;
	string inputFileName;
	cout << "Enter the input filename: ";
	cin >> inputFileName;
	inputFile.open(inputFileName);
	while (!inputFile) { // While the input file is invalid:
		cin.clear(); 
		cin.ignore(10000, '\n'); 
		cout << "Error opening \"" << inputFileName << "\"!\n"; 
		cout << "Enter the input filename: "; 
		cin >> inputFileName; 
		inputFile.open(inputFileName); 
	} 
	
	// This section asks the user for the output file and opens it for writing to.
    ofstream outputFile;
	string outputFileName;
	cout << "Enter the output filename: ";
	cin >> outputFileName;
	outputFile.open(outputFileName);
	while (!outputFile) { // While the output file is invalid:
		cin.clear(); 
		cin.ignore(10000, '\n'); 
		cout << "Error opening \"" << outputFileName << "\"!\n"; 
		cout << "Enter the output filename: "; 
		cin >> outputFileName; 
		outputFile.open(outputFileName); 
	} 

	// This section reads each line from the inputFile to the outputFile as unpacked text.
	string inputLine, outputLine;
	while (getline(inputFile, inputLine)) {
		if (inputLine != "") {
			for (int i = 24; i >= 0; i -= 8) {
				unsigned int outputUI = (unsigned int)stoul(inputLine) >> i & 0xFF;
				if (outputUI != 0x00) outputFile << (char)(outputUI);
			}
		}
	}
	cout << endl;

	// This section closes the input and output files.
	inputFile.close();
	outputFile.close();

}

// This function outputs the help menu with the supported commands.
void help() {
	cout<< "Supported commands: \n"
		<< "     p    Pack a data file from text.\n" 
		<< "     u    Unpack a text file from packed data.\n" 
		<< "     h    Print this help text.\n" 
		<< "     q    Quit the program.\n\n";
}