// June 26, 2025 Toby Hansen

// CSC237 Lab 6a: Bitwise Operations:
// (Starter code provided)
// This progam implements a "command loop" that invokes different functions, 
// based on the command that the user enters.   The functions themselves 
// perform various bitwise operations on data entered by the user.

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

bool verboseMode; // Global variable (controls printing of "debug" output)

// Function Prototypes
void displayDataValue(unsigned int& param);
string convertToBinaryString(unsigned int param);
void set_uIntData(unsigned int& param);
void invert(unsigned int& param);
void bitwise_AND(unsigned int& param);
void bitwise_OR(unsigned int& param);
void bitwise_XOR(unsigned int& param);
void bitwise_LeftShift(unsigned int& param);
void bitwise_RightShift(unsigned int& param);
void clearHexDigit(unsigned int& param);                  // THIS ONE
void defineNewValueForHexDigit(unsigned int& param);      // AND THIS ONE
unsigned int getDigitNumber();
unsigned int getNewValue();

bool quitCommand();
bool confirmYN(string promptText);
void displayHelpText();

bool getVerboseMode();
void setVerboseMode(bool param);
void toggleVerboseMode();
void toggleBooleanVariable(bool& param);
void demonstrateVerboseMode(unsigned int uIntData, string command, bool keepRunning);


int main()
{
	setVerboseMode(false);  // Initially, verboseMode is OFF.

	cout << uppercase;   // Display HEX values with upper-case letters.
	unsigned int uIntData = 0;    // unsigned integer variable

	string command;            // command from user
	bool keepRunning = true;   // flag to control exit from program.

	while (keepRunning == true) {
		displayDataValue(uIntData); // Display decimal, octal, hex, and binary

		// Prompt for command input.
		cout << "Enter command (or 'h' for help): ";
		getline(cin, command);
		//   Based on the command that the user entered, call 
		//   the function that implements that command.
		if (command == "a") {
			bitwise_AND(uIntData);
		}
		else if (command == "c") {
			clearHexDigit(uIntData);
		}
		else if (command == "d") {
			defineNewValueForHexDigit(uIntData);
		}
		else if (command == "h") {
			displayHelpText();
		}
		else if (command == "l") { // (lower-case L)
			bitwise_LeftShift(uIntData);
		}
		else if (command == "n") {
			invert(uIntData);     // Negate (invert) all bits
		}
		else if (command == "o") {
			bitwise_OR(uIntData);
		}
		else if (command == "q" || command == "quit") {
			// If user confirms, set flag to exit program
			keepRunning = !quitCommand();
		}
		else if (command == "r") {
			bitwise_RightShift(uIntData);
		}
		else if (command == "s") {
			set_uIntData(uIntData);
		}
		else if (command == "v" || command == "verbose") {
			toggleVerboseMode();  // Set verboseMode to opposite value.
		}
		else if (command == "x") {
			bitwise_XOR(uIntData);
		}
		else if (command == "demo") {
			demonstrateVerboseMode(uIntData, command, keepRunning);
		}
		else {
			cout << "Invalid command: " << command << endl;
		}

	}  // (end 'while')

	cout << "Exit the program." << endl;
	return 0;
}  // (end function 'main')


/*____________________________________________________________
*  displayHelpText:  list the interactive commands that this
*                    program supports, with a brief explanation
*                    of each command
*/
void displayHelpText() {
	// Help text.
	cout << "Supported commands: \n"
		<< "     a    bitwise AND.\n"
		<< "     c    Clear specific Hex digit. (Needs STUDENT modifications)\n"
		<< "     d    Define new contents for specific Hex digit. (Needs STUDENT modifications)\n"
		<< "     h    Print this help text.\n"
		<< "     l    (lower-case L) bitwise LEFT SHIFT\n"
		<< "     n    Negate (invert) all bits.\n"
		<< "     o    bitwise OR.\n"
		<< "     r    bitwise RIGHT SHIFT.\n"
		<< "     s    SET data value (hex).\n"
		<< "     q    quit (end the program).\n"
		<< "     v    SET or CLEAR verboseMode (debug aids).\n"
		<< "     x    bitwise XOR.\n"
		<< "   demo   Demonstrate how to use verboseMode.\n"
		<< endl;
}
/*____________________________________________________________
*  displayDataValue:  Display data as decimal, octal, hex, and binary.
*
*  Inputs:            param = pass-by-reference parameter
*
*/
void displayDataValue(unsigned int& param) {
	string binString = "";
	binString = convertToBinaryString(param);
	cout << " Decimal: " << dec << setw(10) << param
		<< " Octal: " << oct << setw(11) << param
		<< " Hex: " << hex << setw(8) << param
		<< " Binary: " << binString << endl;
}

/*____________________________________________________________
*  convertToBinaryString:  return text format of binary data
*
*  Inputs:    param = pass-by-value parameter (32-bit unsigned int)
*  Output:    returns string containing text representation of bits.
*/
string convertToBinaryString(unsigned int param) {
	string outputString = "";  // Initially, output string is empty.
	int bitPosition = 0;

	for (bitPosition = 0; bitPosition < 32; bitPosition++) {
		//  Improve readability by inserting an underscore character 
		//  between groups of 4 bits.
		if ((bitPosition > 0) && ((bitPosition % 4) == 0)) {
			outputString.insert(0, "_");
		}
		// If param is even, insert a zero.  If odd, insert a one.
		if (param % 2 == 0) {
			outputString.insert(0, "0");
		}
		else {
			outputString.insert(0, "1");
		}
		param = param >> 1;        // shift right by one bit (divide by 2).
	} // (end for-loop)

	return outputString;
}

/*____________________________________________________________
*  set_uIntData:      Set value of data vareable:
*                     Ask the user to input hex argument for
*                     setting the parameter data.
*
*  Inputs:            param = pass-by-reference parameter
*
*/
void set_uIntData(unsigned int& param) {
	unsigned int userInput;
	unsigned int result;
	cout << "Original data value (hex) = " << hex << param << endl;
	cout << "Enter argument for new data value (hex): ";
	cin >> hex >> userInput;
	cin.ignore(10, '\n');
	result = userInput;    // Set data value 
	cout << "Modified data value (hex) = " << hex << result << endl;
	param = result;           // Pass result to caller.
}

/*____________________________________________________________
*  invert:            Negate (invert) all bits:
*                     Perform the Logical-NOT operation
*                     on the parameter data.
*
*  Inputs:            param = pass-by-reference parameter
*
*/
void invert(unsigned int& param) {
	unsigned int result;
	cout << "Original data value (hex) = " << hex << param << endl;
	result = ~param;           // Invert all bits
	cout << "Modified data value (hex) = " << hex << result << endl;
	param = result;           // Pass result to caller.
}

/*____________________________________________________________
*  bitwise_AND:       Bitwise AND operation:
*                     Ask the user to input argument for
*                     bitwise AND operation with parameter data.
*
*  Inputs:            param = pass-by-reference parameter
*
*/
void bitwise_AND(unsigned int& param) {
	unsigned int userInput;
	unsigned int result;
	cout << "Original data value (hex) = " << hex << param << endl;
	cout << "Enter hex argument for Bitwise-AND: ";
	cin >> hex >> userInput;
	cin.ignore(10, '\n');
	result = param & userInput;    // Bitwise AND
	cout << "Modified data value (hex) = " << hex << result << endl;
	param = result;           // Pass result to caller.
}
/*____________________________________________________________
*  bitwise_OR:        Bitwise OR operation:
*                     Ask the user to input argument for
*                     bitwise OR operation with parameter data.
*
*  Inputs:            param = pass-by-reference parameter
*
*/
void bitwise_OR(unsigned int& param) {
	unsigned int userInput;
	unsigned int result;
	cout << "Original data value (hex) = " << hex << param << endl;
	cout << "Enter hex argument for Bitwise-OR: ";
	cin >> hex >> userInput;
	cin.ignore(10, '\n');
	result = param | userInput;   // Bitwise OR
	cout << "Modified data value (hex) = " << hex << result << endl;
	param = result;           // Pass result to caller.
}

/*____________________________________________________________
*  bitwise_XOR:        Bitwise XOR operation:
*                     Ask the user to input argument for
*                     bitwise XOR operation with parameter data.
*
*  Inputs:            param = pass-by-reference parameter
*
*/
void bitwise_XOR(unsigned int& param) {
	unsigned int userInput;
	unsigned int result;
	cout << "Original data value (hex) = " << hex << param << endl;
	cout << "Enter hex argument for Bitwise-XOR: ";
	cin >> hex >> userInput;
	cin.ignore(10, '\n');
	result = param ^ userInput;    //   Bitwise Exclusive-OR
	cout << "Modified data value (hex) = " << hex << result << endl;
	param = result;           // Pass result to caller.
}

/*____________________________________________________________
*  bitwise_LeftShift: Bitwise LeftShift operation:
*                     Ask the user to input argument for
*                     bitwise LeftShift operation with parameter data.
*
*  Inputs:            param = pass-by-reference parameter
*
*/
void bitwise_LeftShift(unsigned int& param) {
	unsigned int userInput;
	unsigned int result;
	cout << "Original data value (hex) = " << hex << param << endl;
	cout << "Enter decimal argument for Bitwise-LeftShift: ";
	cin >> dec >> userInput;
	cin.ignore(10, '\n');
	result = param << userInput;   //    Bitwise LeftShift
	cout << "Modified data value (hex) = " << hex << result << endl;
	param = result;           // Pass result to caller.
}

/*____________________________________________________________
*  bitwise_RightShift:  Bitwise RightShift operation:
*                     Ask the user to input argument for
*                     bitwise RightShift operation with parameter data.
*
*  Inputs:            param = pass-by-reference parameter
*
*/
void bitwise_RightShift(unsigned int& param) {
	unsigned int userInput;
	unsigned int result;
	cout << "Original data value (hex) = " << hex << param << endl;
	cout << "Enter decimal argument for Bitwise-RightShift: ";
	cin >> dec >> userInput;
	cin.ignore(10, '\n');
	result = param >> userInput;    // Bitwise RightShift
	cout << "Modified data value (hex) = " << hex << result << endl;
	param = result;           // Pass result to caller.
}
/*____________________________________________________________
*  getDigitNumber:    Input digit position:
*                     Ask the user to input desired digit position 
*                     (digits are counted from the right, beginning
*                     with zero).
*
*  Outputs:            
*      returns digit position
*/
unsigned int getDigitNumber() {
	unsigned int userInput;

	cout << "Enter digit number (count from the right, begin at zero): ";
	cin >> dec >> userInput;
	cin.ignore(10, '\n');
	return userInput;
}
/*____________________________________________________________
*  clearHexDigit:     Clear specific Hex digit to all zeros:
*                     Ask the user to input the digit POSITION  
*                     (digits are counted from the right, beginning
*                     with zero).
*
*  Inputs:            param = pass-by-reference parameter
*
*/
void clearHexDigit(unsigned int& param) {
	unsigned int digitNumber;
	unsigned int result=0;
	cout << "Original data value (hex) = " << hex << param << endl;
	digitNumber = getDigitNumber();  // get digit number from user

// Add your code here.

	// This section ensures that the digit given is valid (between the max and min digits in the param).
	while (digitNumber > 7 || digitNumber < 0) { 
		cout << "The digit you have entered is invalid.\n";
		digitNumber = getDigitNumber();  // Gets a new digit number from the user.
	}

	// This section creates a mask to clear the specified hex digit.
	// 0xF is the decimal 15 in hex, which is also 1111 in binary, fully covering the 0th hex digit (nibble). 
	// So the mask will look like: - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 0000 0000 0000 0000 0000 0000 0000 1111
	// Since the mask needs to cover the given digit, the left shift operator (<<) is used to move the mask over.
	// The digitNumber is multiplied by 4 because nibbles are 4 bits. 
	// If the 3rd digit was being cleared, the mask would look like: - - - - - - - - - - - - - - - - - - - - - - - - - 0000 0000 0000 0000 1111 0000 0000 0000
	// The ~ symbol is used to invert the mask so it looks like: - - - - - - - - - - - - - - - - - - - - - - - - - - - 1111 1111 1111 1111 0000 1111 1111 1111
	// The and operator (&) returns 1 if both param and the mask are 1 in any given place, otherwise it returns 0.
	// So if the original param was 12345678, in binary it would look like:  - - - - - - - - - - - - - - - - - - - - - 0001 0010 0011 0100 0101 0110 0111 1000
	// And since the mask looks like:  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 1111 1111 1111 1111 0000 1111 1111 1111
	// After the and operator, the result looks like:  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 0001 0010 0011 0100 0000 0110 0111 1000
	// In other words, every bit remains the same EXCEPT the bits comprising the cleared digit. 12345678 -> 12340678.
    result = param & ~(0xF << (digitNumber * 4));

// End of my code.
	
	cout << "Modified data value (hex) = " << hex << result << endl;
	param = result;           // Pass result to caller.
}

/*____________________________________________________________
*  defineNewValueForHexDigit:   
*                     Ask the user to input digit position
*                     (counting from the right, beginning with zero).
*
*  Inputs:            param = pass-by-reference parameter
*
*/
void defineNewValueForHexDigit(unsigned int& param) {
	unsigned int digitNumber;
	unsigned int newValue;
	unsigned int shiftedNewValue=0;
	unsigned int result=0;
	cout << "Original data value (hex) = " << hex << param << endl;
	digitNumber = getDigitNumber();     // get digit number from user
	newValue = getNewValue();  // desired value for selected digit
	
// Add your code here.

	// This section ensures that the digit given is valid (between the max and min digits in the param).
	while (digitNumber > 7 || digitNumber < 0) { 
		cout << "The digit you have entered is invalid.\n";
		digitNumber = getDigitNumber();  // Gets a new digit number from the user.
	}

	// This section creates a mask to clear the specified hex digit before replacing it with a new one.
	// 0xF is the decimal 15 in hex, which is also 1111 in binary, fully covering the 0th hex digit (nibble). 
	// So the mask will look like: - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 0000 0000 0000 0000 0000 0000 0000 1111
	// Since the mask needs to cover the given digit, the left shift operator (<<) is used to move the mask over.
	// The digitNumber is multiplied by 4 because nibbles are 4 bits. 
	// If the 3rd digit was being cleared, the mask would look like: - - - - - - - - - - - - - - - - - - - - - - - - - 0000 0000 0000 0000 1111 0000 0000 0000
	// The ~ symbol is used to invert the mask so it looks like: - - - - - - - - - - - - - - - - - - - - - - - - - - - 1111 1111 1111 1111 0000 1111 1111 1111
	// The and operator (&) returns 1 if both param and the mask are 1 in any given place, otherwise it returns 0.
	// So if the original param was 12345678, in binary it would look like:  - - - - - - - - - - - - - - - - - - - - - 0001 0010 0011 0100 0101 0110 0111 1000
	// And since the mask looks like:  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 1111 1111 1111 1111 0000 1111 1111 1111
	// After the and operator, param looks like: - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 0001 0010 0011 0100 0000 0110 0111 1000
	// In other words, every bit remains the same EXCEPT the bits comprising the cleared digit. 12345678 -> 12340678.
    param &= ~(0xF << (digitNumber * 4));

	// This section replaces the specified digit with a new one.
	// The and comparator (&) is used to make a new value mask, which is then shifted left (<<) the digit amount.
	// The or operator (|) returns 1 if either param or the mask are 1 in any given place, otherwise it returns 0.
	// After the digit is cleared, param looks like: - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 0001 0010 0011 0100 0000 0110 0111 1000
	// And if the new value was 9, then the mask would looks like: - - - - - - - - - - - - - - - - - - - - - - - - - - 0000 0000 0000 0000 1001 0000 0000 0000
	// After the or operator, the result would look like:  - - - - - - - - - - - - - - - - - - - - - - - - - - - - - - 0001 0010 0011 0100 1001 0110 0111 1000
	// In other words, every bit remains the same EXCEPT the bits comprising the cleared digit. 12340678 -> 12349678.
	result = param | ((0xF & newValue) << (digitNumber * 4));

// End of my code.

	cout << "Modified data value (hex) = " << hex << result << endl;
	param = result;           // Pass result to caller.
}


/*____________________________________________________________
*  getNewValue:       Input new hex value:
*                     Ask the user to input desired value (hex).
*
*  Outputs:
*      returns digit position
*/
unsigned int getNewValue() {
	unsigned int newValue;

	cout << "Enter desired new value (hex): ";
	cin >> hex >> newValue;
	cin.ignore(10, '\n');
	return newValue;
}

/*____________________________________________________________________
 * Function:       quitCommand
 * Output:         returns TRUE if the user wants to exit the program.
 * Description:    Ask the user to confirm if they wish to exit the
 *                 program.  Return the answer to the caller.
 */
bool quitCommand() {

	return confirmYN("Are you sure that you want to exit the program? ");
}

/*____________________________________________________________________
 *	Function:	 confirmYN  -	Ask user to confirm
 *  Inputs:      prompt string for user
 *  Outputs:     returns true or false.
 *  Desciption:  Ask the user to confirm their intention.
 *               Check response for 'y' or 'n', and repeat
 *               the question until the user replies correctly.
 */
bool confirmYN(string promptText)
{
	string inputString;
	bool confirmationValue = false;
	bool inputIsOK = false;

	do
	{
		// input from user 
		cout << promptText;
		getline(cin, inputString);

		if (inputString == "y" || inputString == "Y")
		{
			confirmationValue = true;
			inputIsOK = true;
		}
		else if (inputString == "n" || inputString == "N")
		{
			confirmationValue = false;
			inputIsOK = true;
		}
		else
		{
			cout << "Invalid input:  " << inputString << ".  Please input y or n." << endl;
		}
	} while (inputIsOK == false);
	return confirmationValue;

} // (end function 'confirmYN')


/*____________________________________________________________________
 *	Function:	 toggleBooleanVariable - Change to opposite value
 *  Inputs:      param = boolean variable (this is a REFERENCE parameter).
 *  Outputs:     Inverse of input param (true or false)
 *  Desciption:  If input parameter is true, change to false.
 *               If input parameter is false, change to true.
 */
void toggleBooleanVariable(bool& param) {
	param = !(param);
}
/*___________________________________________________________________________
 * Debug-related functions:
 */
void setVerboseMode(bool param) {
	verboseMode = param;
}

bool getVerboseMode() {
	return verboseMode;
}

void toggleVerboseMode() {
	toggleBooleanVariable(verboseMode);
	cout << "verboseMode is now " << getVerboseMode()<< endl;
}

/*____________________________________________________________________
 *	Function:	 demonstrateVerboseMode - example code for using verboseMode
 *  Inputs:      uIntData = unsigned int value.
 *               command = string value.
 *               keepRunning = bool value.
 *  Outputs:     text to cout.
 *  Desciption:  This function provides an example of how to use
 *               the verboseMode global variable to assist you as 
 *               you debug your code.
 */
void demonstrateVerboseMode(unsigned int uIntData, string command, bool keepRunning) {
	if (getVerboseMode()) {
		cout << dec << "DEMONSTRATE verboseMode (lineNumber=" << __LINE__ << "):";
		cout << " uIntData = " << hex << uIntData << endl;
		cout << " command=" << command <<" keepRunning = " << keepRunning << endl;
	}
	else {
		cout << " verboseMode is currently FALSE." << endl;
	}
}