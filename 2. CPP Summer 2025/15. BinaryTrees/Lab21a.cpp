// CSC-237:  Lab21a - Binary Tree
// This program implements a linked-node Binary Tree.
// This is a working program, with several features 
// incomplete -- to be implemented by the student.

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <cstdlib>
#include "IntBinaryTree.h"

using namespace std;


//  Function Prototypes:

void outputHelpMessage();
void quitProgram(int exitStatus);



int main()
{
	// Local variables for 'main' function:	
	string command;			//	command string, input by user

	IntBinaryTree *testTreePtr = nullptr;
	string inputText;

	while (true)
	{

		// Prompt for command input.
		cout << "\nCommand: ";
		getline(cin, command);

		cout << fixed << setprecision(2);

		if (command == "")
		{
			// ignore empty command
		}
		else if (command == "C" || command == "clobber")
		{
			if (testTreePtr)
			{
				cout << "root=" << testTreePtr->getRoot() << " (before clobber operation)" << endl;
				testTreePtr->userRemoveAllNodes();
				cout << "root=" << testTreePtr->getRoot() << " (after clobber operation)" << endl;
			}
			else
			{
				cout << "Run \"r\" command first." << endl;
			}

		}
		else if (command == "d" || command == "inorder")
		{
			if (testTreePtr) {
				cout << "     INorder traversal: " << endl;
				cout << "root=" << testTreePtr->getRoot() << endl;
				testTreePtr->displayInOrder();
			}
			else
			{
				cout << "Run \"r\" command first." << endl;
			}
		}
		else if (command == "D")
		{
			if (testTreePtr)
			{
				cout << "root=" << testTreePtr->getRoot() << endl;
				testTreePtr->enhancedTreeDisplay();
			}
			else
			{
				cout << "Run \"r\" command first." << endl;
			}
		}
		else if (command == "h" || command == "help")
		{
			// Output help text
			outputHelpMessage();
		}
		else if (command == "H" || command == "height")
		{
			if (testTreePtr) {

				testTreePtr->displayTreeHeight();
			}
			else
			{
				cout << "Run \"r\" command first." << endl;
			}
		}
		else if (command == "i" || command == "I")
		{
			if (testTreePtr)
			{
				testTreePtr->userInsertNode();
			}
			else
			{
				cout << "Run \"r\" command first." << endl;
			}
		}
		else if (command == "n" || command == "N")
		{
			if (testTreePtr)
			{
				testTreePtr->displayNumberOfNodes();
			}
			else
			{
				cout << "Run \"r\" command first." << endl;
			}
		}
		else if (command == "pre" || command == "preorder")
		{
			if (testTreePtr)
			{
				cout << "     PREorder traversal: " << endl;
				cout << "root=" << testTreePtr->getRoot()
					<< endl;
				testTreePtr->displayPreOrder();
			}
			else
			{
				cout << "Run \"r\" command first." << endl;
			}
		}
		else if (command == "post" || command == "postorder")
		{
			if (testTreePtr)
			{
				cout << "     POSTorder traversal: " << endl;
				cout << "root=" << testTreePtr->getRoot()
					<< endl;
				testTreePtr->displayPostOrder();
			}
			else
			{
				cout << "Run \"r\" command first." << endl;
			}
		}
		else if (command == "q" || command == "quit")
		{
			// Quit program
			quitProgram(0);  // exit status = SUCCESS 
		}
		else if (command == "r")
			// If there is a binary tree object defined, delete it;
		{
			if (testTreePtr) {
				delete testTreePtr;
			}

			testTreePtr = new IntBinaryTree();
			if (testTreePtr->openInputFile() == true)
			{
				int lineCount;
				lineCount = testTreePtr->readFile();
				cout << lineCount << " lines read from input file." << endl;
				testTreePtr->closeInputFile();
			}
		}
		else if (command == "R")
		{
			if (testTreePtr)
			{
				testTreePtr->userRemoveNode();
			}
			else
			{
				cout << "Run \"r\" command first." << endl;
			}
		}
		else if (command == "s")
		{
			if (testTreePtr)
			{
				testTreePtr->userSearchNode();
			}
			else
			{
				cout << "Run \"r\" command first." << endl;
			}
		}
		else if (command == "v" || command == "verbose")
		{
			if (IntBinaryTree::getVerboseMode() == true)
			{
				cout << "Clearing verboseMode." << endl;
				IntBinaryTree::setVerboseMode(false);
			}
			else
			{
				cout << "Setting verboseMode." << endl;
				IntBinaryTree::setVerboseMode(true);
			}
		}
		else
			cout << "Invalid command:  " << command << endl;

	}  // (end 'while')

	return 0;
}  // (end function 'main')

/*=============================================================================
*	Function:	outputHelpMessage - Output short description of commands.
*
*  Inputs:     none
*
*  Outputs:
*      Outputs help text to the cout stream
*
*  Desciption:
*		Output (to the screen) a short description of each interactive command
*      supported by the program.
*
*---------------------------------------------------------------------------*/
void outputHelpMessage()
{
	// Help text.
	cout << "Supported commands: \n"
		<< "	C       Remove ALL nodes from binary tree (clobber)\n"
		<< "	d       display binary tree by INorder traversal.\n"
		<< "	D       Enhanced display of binary tree (lab exercise).\n"
		<< "	h       print this help text.\n"
		<< "	H       display Maximum tree Height (lab exercise).\n"
		<< "	i       Insert node to binary tree\n"
		<< "	n or N  display number of nodes in the tree.\n"
		<< "	post    display binary tree by POSTorder traversal.\n"
		<< "	pre     display binary tree by PREorder traversal.\n"
		<< "	q       quit (end the program).\n"
		<< "	r       open input file, read into binary tree.\n"
		<< "	R       Remove node from binary tree\n"
		<< "	s       Search for node in binary tree\n"
		<< "	v       Set or Clear VERBOSE mode\n"
		<< endl;

} // (end function 'outputHelpMessage')

/*=============================================================================
*	Function:	quitProgram  -	 Exit the program, returning status from caller
*
*  Inputs:
*      exitStatus =         Exit code to be returned to operating system.
*
*  Outputs:
*      exits the program, passing status value from caller
*
*
*  Desciption:
*		Exit the program
*
*---------------------------------------------------------------------------*/
void quitProgram(int exitStatus)
{
	cout << "Exiting program with status = " << exitStatus << endl;
	exit(exitStatus);

} // (end function 'quitProgram')


