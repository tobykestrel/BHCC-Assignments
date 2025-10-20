/*===================================
| Toby Hansen, October 19 2025.     |
| ReadBinaryTreeHW, CSC-242.        |
| This program reads a binary tree. |
===================================*/

#include <iostream>
#include <iomanip>
#include <list>
using namespace std;

// Node structure containing an int and pointers to the left and right.
struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = nullptr;
        right = nullptr;
    }
};

// This section is for declaring function prototypes.
void printHelpText();               // Prints the list of commands.
void addNode(Node* &root);          // Adds a new node to the tree.
void removeNode(Node* &root);       // Remove a node from the tree.
void printTree(Node* &root);        // Print the nodes in the tree.
int getTreeHeight(Node* nodePtr);   // Gets the height of the tree.
int getMaxNodeWidth(Node* nodePtr); // Gets the maximum node width.
Node* insert(Node* nodePtr, int val);      // Insert a node into the tree.
Node* deleteNode(Node* nodePtr, int val);  // Delete a node from the tree.

// This is the main function.
int main() {
    Node* root = nullptr;

    // This code banner is printed before the code is run.
    cout<< "/*===================================\n"
        << "| Toby Hansen, October 19 2025.     |\n"
        << "| ReadBinaryTreeHW, CSC-242.        |\n"
        << "| This program reads a binary tree. |\n"
        << "===================================*/\n\n";

	// This section is a command-loop repeating the program until the user decides to quit.
	char command;
	cout << "Enter command ('h' for list of supported commands): ";
	while(true) {
		command = cin.get();
		cin.ignore(10000, '\n');
		switch (command) {
			case 'a': addNode(root); break;	                // Adds a new node to the tree.
			case 'r': removeNode(root); break;	            // Remove a node from the tree.
			case 'p': printTree(root); cout << endl; break; // Print the nodes in the tree.
			case 'h': printHelpText(); break;               // Prints the list of commands.
			case 'q': system("pause"); return 0;            // Quits program on user input.
		}
		cout << "Command: ";
	}
}

// This function takes the user's input and adds a node to the tree.
void addNode(Node* &root) {

    // This section takes the user's input on what the new node's value should be.
    int val;
    cout << "Enter the value of the new node: ";
    while (!(cin >> val)) { // While the input is invalid:
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid input. Enter again: ";
    }
	cin.ignore(10000, '\n');

    root = insert(root, val);
}

// This function inserts a node into the binary tree.
Node* insert(Node* nodePtr, int val) {
    if (nodePtr == nullptr ) { nodePtr = new Node(val); } else 
    if (val < nodePtr->data) { nodePtr->left = insert(nodePtr->left, val); } else 
    if (val > nodePtr->data) { nodePtr->right = insert(nodePtr->right, val); }
    return nodePtr;
}

// This function takes the user's input and removes a node from the tree.
void removeNode(Node* &root) {

    // This section takes the user's input on what the node to remove.
    int val;
    cout << "Enter the value of the node to delete: ";
    while (!(cin >> val)) { // While the input is invalid:
        cin.clear();
        cin.ignore(10000, '\n');
        cout << "Invalid input. Enter again: ";
    }
	cin.ignore(10000, '\n');

    root = deleteNode(root, val);
}

// This function deletes a node from the binary tree.
Node* deleteNode(Node* nodePtr, int val) {

    // Traverse the tree
    if (nodePtr == nullptr) return nodePtr;
    if (val < nodePtr->data) { nodePtr->left = deleteNode(nodePtr->left, val); }
    else if (val > nodePtr->data) { nodePtr->right = deleteNode(nodePtr->right, val); }
    else { // Node found.

        // Case 1: No child (leaf node)
        if (nodePtr->left == nullptr && nodePtr->right == nullptr) {
            delete nodePtr;
            return nullptr;

        // Case 2: One child
        } else if (nodePtr->left == nullptr) { 
            Node* temp = nodePtr->right;
            delete nodePtr;
            return temp;
        } else if (nodePtr->right == nullptr) {
            Node* temp = nodePtr->left;
            delete nodePtr;
            return temp;

        // Case 3: Two children
        } else {
            Node* min = nodePtr->right;
            while (min && min->left) min = min->left;
            nodePtr->data = min->data; // Copy value
            nodePtr->right = deleteNode(nodePtr->right, min->data); // Delete duplicate
        }
    }

    return nodePtr;
}

// This function prints the nodes in the tree.
void printTree(Node* &root) {

    // This section gets the tree height, max number of nodes in the tree, and node width.
    int nodeWidth = getMaxNodeWidth(root);
    if (nodeWidth % 2 == 0) nodeWidth++;
    int treeHeight = getTreeHeight(root);
    int maxNodes = 1;
    for (int i = 0; i < treeHeight; i++) maxNodes *= 2;
    maxNodes -= 1;

    // This section prints the tree in level order traversal.
    list<Node*> q = {root};
    for (int level = 1; level <= treeHeight; level++) {

        // This section gets the level's first spacing.
        int firstSpace = 1;
        for (int i = treeHeight - level; i > 0; i--) firstSpace *= 2;
        firstSpace--;
        firstSpace *= nodeWidth;
        for (int i = 0; i < firstSpace; i++) cout << " ";

        // This section gets the level's between spacing.
        int btwnSpace = maxNodes;
        for (int i = 1; i < level; i++) btwnSpace /= 2;
        btwnSpace *= nodeWidth;

        // This section prints the nodes in the current level.
        int levelNodes = 1;
        for (int i = 1; i < level; i++) levelNodes *= 2;
        for (int i = 0; i < levelNodes; i++) {
            Node* curr = q.front(); 
            q.pop_front(); 
            if (curr && level < treeHeight) {
                int currW = to_string(curr->data).length();
                if (currW % 2 == 0) {
                    cout << " "; currW++; }
                for (int j = 0; j < (nodeWidth-currW)/2; j++) cout << " "; 
                cout << curr->data;
                for (int j = 0; j < (nodeWidth-currW)/2; j++) cout << " "; 
                q.push_back(curr->left);
                q.push_back(curr->right);
            } else {
                for (int j = 0; j < nodeWidth; j++) cout << " "; 
                q.push_back(nullptr);
                q.push_back(nullptr);
            }
            for (int j = 0; j < btwnSpace; j++) cout << " ";
        }
        cout << endl;
    }
}

// This function gets width that the nodes will be printed in.
int getMaxNodeWidth(Node* nodePtr) {
    if (nodePtr == nullptr ) return 1;
    int currWidth = to_string(nodePtr->data).length();
    int leftWidth = getMaxNodeWidth(nodePtr->left);
    int rightWidth = getMaxNodeWidth(nodePtr->right);
    if (currWidth >= leftWidth && currWidth >= rightWidth) return currWidth;
    if (leftWidth >= currWidth && leftWidth >= rightWidth) return leftWidth;
    if (rightWidth >= leftWidth && rightWidth >= currWidth) return rightWidth;
}

// This function gets the height of the tree, how many levels there are.
int getTreeHeight(Node* nodePtr) {
	int treeHeight = 0;
	if (nodePtr) {
		int leftTreeHeight = getTreeHeight(nodePtr->left);
		int rightTreeHeight = getTreeHeight(nodePtr->right);
		if (leftTreeHeight > rightTreeHeight) 
             { treeHeight = leftTreeHeight + 1; } 
        else { treeHeight = rightTreeHeight + 1; }
	}
	return treeHeight;
}

// This function displays the help text with the supported commands.
void printHelpText() {
	cout<< "Supported commands: \n"
		<< "     a    Adds a new node to the tree.\n" 
		<< "     r    Remove a node from the tree.\n" 
		<< "     p    Print the nodes in the tree.\n" 
		<< "     h    Prints the list of commands.\n"
		<< "     q    Quit the program.\n";
}