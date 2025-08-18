// Implementation file for the IntBinaryTree class
// (Adapted from the IntBinaryTree class in Chapter 21 
//  of the Gaddis textbook.)
// Portions copyright 2018, Pearson Education, Inc.
//
#include <iostream>
#include "IntBinaryTree.h"

using namespace std;

// Function prototypes:
int inputInteger(string promptText);
bool confirmYN(string promptText);
int convertStringToInteger(string inputString);

bool IntBinaryTree::verboseMode = false;

//*************************************************************
// insert accepts a TreeNode pointer and a pointer to a node. *
// The function inserts the node into the tree pointed to by  *
// the TreeNode pointer. This function is called recursively. *
//*************************************************************

void IntBinaryTree::insert(TreeNode *&nodePtr, TreeNode *&newNode)
{
	if (nodePtr == nullptr)
	{
		nodePtr = newNode;                  // Insert the node.
	}
	else if (newNode->value < nodePtr->value)
	{
		insert(nodePtr->left, newNode);     // Search the left branch
	}
	else
	{
		insert(nodePtr->right, newNode);    // Search the right branch
	}
}

//**********************************************************
// insertNode creates a new node to hold num as its value, *
// and passes it to the insert function.                   *
//**********************************************************

void IntBinaryTree::insertNode(int num)
{
	TreeNode *newNode;      // Pointer to a new node.

	// Create a new node and store num in it.
	newNode = new TreeNode;
	newNode->value = num;
	newNode->left = newNode->right = nullptr;

	// Insert the node.
	insert(root, newNode);
}

//***************************************************
// destroySubTree is called by the destructor. It   *
// deletes all nodes in the tree.                   *
//***************************************************

void IntBinaryTree::destroySubTree(TreeNode *&nodePtr)
{
	if (nodePtr)
	{
		if (nodePtr->left)
			destroySubTree(nodePtr->left);
		if (nodePtr->right)
			destroySubTree(nodePtr->right);
		makeDeletion(nodePtr);
		nodePtr = nullptr;
	}
}

//***************************************************
// searchNode determines if a value is present in   *
// the tree. If so, the function returns true.      *
// Otherwise, it returns false.                     *
//***************************************************

bool IntBinaryTree::searchNode(int num)
{
	TreeNode *nodePtr = root;

	while (nodePtr)
	{
		if (nodePtr->value == num)
			return true;
		else if (num < nodePtr->value)
			nodePtr = nodePtr->left;
		else
			nodePtr = nodePtr->right;
	}
	return false;
}

//**********************************************
// remove calls deleteNode to delete the       *
// node whose value member is the same as num. *
//**********************************************

void IntBinaryTree::remove(int num)
{
	deleteNode(num, root);
}


//********************************************
// deleteNode deletes the node whose value   *
// member is the same as num.                *
//********************************************

void IntBinaryTree::deleteNode(int num, TreeNode *&nodePtr)
{

	if (num < nodePtr->value)
	{
		if (getVerboseMode())
		{
			cout << "deleteNode(" << __LINE__ << "): searching LEFT subtree for num=" << num
				<< " (current nodePtr=" << nodePtr << ", value=" << nodePtr->value << ")" << endl;
		}
		deleteNode(num, nodePtr->left);
	}
	else if (num > nodePtr->value)
	{
		if (getVerboseMode())
		{
			cout << "deleteNode(" << __LINE__ << "): searching RIGHT subtree for num=" << num
				<< " (current nodePtr=" << nodePtr << ", value=" << nodePtr->value << ")" << endl;
		}
		deleteNode(num, nodePtr->right);
	}
	else
	{
		cout << "FOUND    ";
		displayNode(nodePtr);
		makeDeletion(nodePtr);

		cout << "AFTER    delete operation: nodePtr=" << nodePtr;
	}
}


//***********************************************************
// makeDeletion takes a reference to a pointer to the node  *
// that is to be deleted. The node is removed and the       *
// branches of the tree below the node are reattached.      *
//***********************************************************

void IntBinaryTree::makeDeletion(TreeNode *&nodePtr)
{
	// Define a temporary pointer to use in reattaching
	// the left subtree.
	TreeNode *tempNodePtr = nullptr;

	if (getVerboseMode())
	{
		cout << "makeDeletion(" << __LINE__ << "): enter with nodePtr=" << nodePtr
			<< ", value=" << nodePtr->value << endl;
	}
	if (nodePtr == nullptr)
	{
		cout << "Cannot delete empty node.\n";
	}
	else if (nodePtr->right == nullptr)
	{
		tempNodePtr = nodePtr;
		nodePtr = nodePtr->left;   // Reattach the left child
		cout << "DELETING ";
		displayNode(tempNodePtr);
		delete tempNodePtr;
		tempNodePtr = nullptr;
	}
	else if (nodePtr->left == nullptr)
	{
		tempNodePtr = nodePtr;
		nodePtr = nodePtr->right;  // Reattach the right child
		cout << "DELETING ";
		displayNode(tempNodePtr);
		delete tempNodePtr;
		tempNodePtr = nullptr;
	}
	// If the node has two children.
	else
	{
		// Move one node the right.
		tempNodePtr = nodePtr->right;
		// Go to the end left node.
		while (tempNodePtr->left)
			tempNodePtr = tempNodePtr->left;
		// Reattach the left subtree.
		tempNodePtr->left = nodePtr->left;
		tempNodePtr = nodePtr;
		// Reattach the right subtree.
		nodePtr = nodePtr->right;
		cout << "DELETING ";
		displayNode(tempNodePtr);
		delete tempNodePtr;
		tempNodePtr = nullptr;
	}
	if (getVerboseMode())
	{
		cout << "makeDeletion(" << __LINE__ << "): return with nodePtr=" << nodePtr
			<< ", tempNodePtr=" << tempNodePtr << endl;
	}
}     // end function makeDeletion

//****************************************************************
// The displayInOrder member function displays the values        *
// in the subtree pointed to by nodePtr, via inorder traversal.  *
//****************************************************************

void IntBinaryTree::displayInOrder(TreeNode *nodePtr) const
{
	if (nodePtr)
	{
		displayInOrder(nodePtr->left);
		displayNode(nodePtr);
		displayInOrder(nodePtr->right);
	}
}

//****************************************************************
// The displayPreOrder member function displays the values       *
// in the subtree pointed to by nodePtr, via preorder traversal. *
//****************************************************************

void IntBinaryTree::displayPreOrder(TreeNode *nodePtr) const
{
	if (nodePtr)
	{
		displayNode(nodePtr);
		displayPreOrder(nodePtr->left);
		displayPreOrder(nodePtr->right);
	}
}



//****************************************************************
// The displayPostOrder member function displays the values      *
// in the subtree pointed to by nodePtr, via postorder traversal.*
//****************************************************************

void IntBinaryTree::displayPostOrder(TreeNode *nodePtr) const
{
	if (nodePtr)
	{
		displayPostOrder(nodePtr->left);
		displayPostOrder(nodePtr->right);
		displayNode(nodePtr);
	}
}


/*=============================================================================
*  The displayNode member function displays the node contents
*---------------------------------------------------------------------------*/
void IntBinaryTree::displayNode(TreeNode *nodePtr) const
{
	// Display the values in this node.
	cout << "node=" << setw(16) << nodePtr
		<< " value=" << setw(8) << nodePtr->value
		<< " left=" << setw(16);
	if (nodePtr->left)
		cout << nodePtr->left;
	else
		cout << "nullptr         ";

	cout << " right=" << setw(16);
	if (nodePtr->right)
		cout << nodePtr->right;
	else
		cout << "nullptr         ";
	cout << endl;
}


/*=============================================================================
*  enhancedTreeDisplay -- display tree contents WITH current tree level
*                         This (non-recursive) version of "enhancedTreeDisplay"
*                         is called by the "main" function.   It calls the
*                         private, recursive version of "enhancedTreeDisplay",
*                         which is shown below.
*---------------------------------------------------------------------------*/
void IntBinaryTree::enhancedTreeDisplay() const
{
	enhancedTreeDisplay(root, 0);
}

/*=============================================================================
*  enhancedTreeDisplay -- display tree contents WITH current tree level
*---------------------------------------------------------------------------*/
void IntBinaryTree::enhancedTreeDisplay(TreeNode *nodePtr, int treeLevel) const
{
	// Lab exercise:  add implementation of this function.


}


/*=============================================================================
*  calculateNumberOfNodes member function calculates the population of the subtree
*---------------------------------------------------------------------------*/
int IntBinaryTree::calculateNumberOfNodes(TreeNode *nodePtr) const
{
	if (nodePtr)
	{
		int leftSubTreePopulation;
		int rightSubTreePopulation;

		leftSubTreePopulation = calculateNumberOfNodes(nodePtr->left);
		rightSubTreePopulation = calculateNumberOfNodes(nodePtr->right);
		return (leftSubTreePopulation + rightSubTreePopulation + 1);
	}
	else
	{
		return 0;
	}
}



/*=============================================================================
*  displayNumberOfNodes - calculate and display tree population
*---------------------------------------------------------------------------*/
void IntBinaryTree::displayNumberOfNodes() const
{

	int treePopulation = 0;

	treePopulation = calculateNumberOfNodes(root);
	cout << "Population of tree = " << treePopulation;

}

/*=============================================================================
*  calculateSubTreeHeight member function calculates the height of the subtree
*
*  Description:   This function returns the maximum tree height of the current
*                 binary subTree.   That is, this function treats the current node
*                 as the "root" node of a tree.  The maximum "height" of this tree
*                 is the height of its tallest SUB-tree, plus 1.
*                 Therefore, the way to calculate the maximum height of THIS tree
*                 is first to find the maximum height of each of its SUB-trees,
*                 choose the larger of the two values, and add 1 to that number.
* NOTE:           The definition of tree Height (from the lecture), requires that
*                 this function be called with the SUB TREES of the ROOT node,
*                 rather than the ROOT node itself.
*---------------------------------------------------------------------------*/
int IntBinaryTree::calculateSubTreeHeight(TreeNode *nodePtr) const
{
	// Lab exercise:   add implementation of this function.

	int subTreeHeight = 0;

	// Lab exercise:  add implementation of this function.

	return subTreeHeight;
}



/*=============================================================================
*  displayTreeHeight - calculate and display tree height
*  NOTE:   the definition of tree height (from the lecture)
*          makes this function a bit counter-intuitive, when
*          considering the easiest way to implement the
*          calculateSubTreeHeight function.
*---------------------------------------------------------------------------*/
void IntBinaryTree::displayTreeHeight() const
{

	int treeHeight = 0;
	int leftSubtreeHeight = calculateSubTreeHeight(root->left);
	int rightSubtreeHeight = calculateSubTreeHeight(root->right);

	if (leftSubtreeHeight > rightSubtreeHeight)
	{
		treeHeight = leftSubtreeHeight;
	}
	else
	{
		treeHeight = rightSubtreeHeight;
	}

	cout << "Height of tree = " << treeHeight;

}


/*=============================================================================
*  userInsertNode - input value from user and insert to tree
*---------------------------------------------------------------------------*/
void IntBinaryTree::userInsertNode()
{

	int dataValue = 0;

	dataValue = inputInteger("Enter value to insert into tree: ");
	insertNode(dataValue);

}

/*=============================================================================
*  userSearchNode - input value from user and search the tree
*---------------------------------------------------------------------------*/
void IntBinaryTree::userSearchNode()
{

	int dataValue = 0;

	dataValue = inputInteger("Enter value to search for in tree: ");
	if (searchNode(dataValue))
		cout << "node is present in tree" << endl;
	else
		cout << "node is NOT present in tree" << endl;

}

/*=============================================================================
*  userRemoveNode - input value from user and remove it from the tree
*---------------------------------------------------------------------------*/
void IntBinaryTree::userRemoveNode()
{

	int dataValue = 0;

	dataValue = inputInteger("Enter value to remove from in tree: ");
	remove(dataValue);

}


/*=============================================================================
*  userRemoveAllNodes - remove all nodes
*---------------------------------------------------------------------------*/
void IntBinaryTree::userRemoveAllNodes()
{
	bool confirm = false;
	TreeNode *treePtr;
	confirm = confirmYN("Are you sure you want to delete the entire tree? ");
	if (confirm)
	{
		treePtr = this->getRoot();
		destroySubTree(treePtr);
		this->setRoot(nullptr);
	}
}

//***************************************
// openInputFile member function
//   (returns true if file open was successful)
//***************************************
bool IntBinaryTree::openInputFile()
{
	// Input file:  prompt for filename, open file for input.
	cout << "Enter name of input file: ";
	getline(cin, inputFileName);
	inputFile.open(inputFileName, ios::in);

	// Check for file open error.
	if (inputFile.fail())
	{
		cout << "ERROR(IntBinaryTree.cpp, " << __LINE__ << ") Error opening file:  " << inputFileName << endl;
		return false;
	}
	else
	{
		return true;
	}
}

//***************************************
// closeInputFile member function
//***************************************
void IntBinaryTree::closeInputFile()
{
	inputFile.close();
}

//***************************************
// readDataLine member function
//
//    Return true if valid data has been read.
//    Return false if end of file encountered.
//***************************************
bool IntBinaryTree::readDataLine(string &recordText)
{
	bool dataValid = false;

	getline(inputFile, recordText);
	if (inputFile)
	{
		dataValid = true;
	}
	else
	{
		dataValid = false;
		if (getVerboseMode())
		{
			cout << "End of file encountered. " << endl;
		}
	}
	return dataValid;
}  // end function readDataLine



/*=============================================================================
*  Function:     readFile - read input file into IntBinaryTree object.
*  Inputs:       dataFile  =  fstream object (already open)
*  Outputs:      returns number of lines read into the binary tree
*  Desciption:   Reads lines of text from the (already open) file,
*                until the readDataLine function returns FALSE (end of file).
*                Converts the input text to an integer value.
*                Inserts the integer value into the binary tree.
*---------------------------------------------------------------------------*/
int IntBinaryTree::readFile()
{
	int lineNum;

	string inputText;
	int dataValue;
	lineNum = 0;

	// Read from (already open) inputFile, until end-of-file
	while (this->readDataLine(inputText))
	{
		lineNum++;          // read was successful
		dataValue = convertStringToInteger(inputText);
		insertNode(dataValue);
	}
	return lineNum;

} // (end function readFile)

/*=============================================================================
 *	Function:	inputInteger  -	 input integer value
 *
 *  Inputs:       promptText
 *  Outputs:      returns integer value input by user.
 *  Desciption:   Input a line of text and convert it to an integer.
 *---------------------------------------------------------------------------*/
int inputInteger(string promptText)
{
	string inputString;
	int convertedInteger = 0;
	int outputVal = 0;
	bool inputIsOK = false;

	do
	{
		try {
			// input from user 
			cout << promptText;
			getline(cin, inputString);
			convertedInteger = stoi(inputString);
			outputVal = convertedInteger;
			inputIsOK = true;
		}
		catch (invalid_argument) {
			cout << "Please enter an integer." << endl;
		}
			
	} while (inputIsOK == false);

	return outputVal;
} // (end function 'inputInteger')


/*=============================================================================
 *	Function:	     confirmYN - Ask user to confirm
 *  Inputs:          prompt string for user
 *  Outputs:         returns true or false.
 *  Desciption:      Ask the user to confirm their intention.
 *                   Check response for yes or no.
 *---------------------------------------------------------------------------*/
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

/*=============================================================================
 *	Function:     convertStringToInteger - Convert string to int
 *  Inputs:       string to be converted
 *  Outputs:      returns int value
 *  Desciption:   Convert input parameter to an integer.
 *
 *---------------------------------------------------------------------------*/
int convertStringToInteger(string inputString)
{
	int convertedInteger = 0;
	int outputVal = 0;
	bool inputIsOK = false;

	try {
		convertedInteger = stoi(inputString);
		outputVal = convertedInteger;
		inputIsOK = true;
	}
	catch (invalid_argument) {
		cout << "convertStringToInteger(" << __LINE__ << "):  "
			<< "invalid inputString \"" << inputString << "\"." << endl;
	}
	return outputVal;
} // (end function 'convertStringToInteger')


