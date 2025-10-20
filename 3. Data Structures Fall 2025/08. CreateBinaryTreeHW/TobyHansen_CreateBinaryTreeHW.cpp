/*===================================
| Toby Hansen, October 19 2025.     |
| CreateBinaryTreeHW, CSC-242.      |
| This program is able to add nodes |
| to a binary tree data structure.  |
===================================*/

#include <iostream>
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
void printHelpText();           // Print the help text.
void addNode(Node* &root);       // Add a node to the tree.
void printTree(Node* root);     // Print the nodes in the tree.
Node* insert(Node* root, int val);      // Insert a node into the tree.

// This is the main function.
int main() {
    Node* root = nullptr;

    // This code banner is printed before the code is run.
    cout<< "/*===================================\n"
        << "| Toby Hansen, October 19 2025.     |\n"
        << "| CreateBinaryTreeHW, CSC-242.      |\n"
        << "| This program is able to add nodes |\n"
        << "| to a binary tree data structure.  |\n"
        << "===================================*/\n\n";

	// This section is a command-loop repeating the program until the user decides to quit.
	char command;
	cout << "Enter command ('h' for list of supported commands): ";
	while(true) {
		command = cin.get();
		cin.ignore(10000, '\n');
		switch (command) {
			case 'a': addNode(root); break;	                // Add a node to the tree.
			case 'p': printTree(root); cout << endl; break; // Print the nodes in the tree.
			case 'h': printHelpText(); break;               // Display the help text.
			case 'q': system("pause"); return 0;            // Quit the program.
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
Node* insert(Node* root, int val) {
    if (root == nullptr ) { root = new Node(val); } else 
    if (val < root->data) { root->left = insert(root->left, val); } else 
    if (val > root->data) { root->right = insert(root->right, val); }
    return root;
}

// This function prints the nodes in the tree.
void printTree(Node* root) {
    if (root != nullptr) {
        printTree(root->left);
        cout << root->data << " ";
        printTree(root->right);
    }
}

// This function displays the help text with the supported commands.
void printHelpText() {
	cout<< "Supported commands: \n"
		<< "     a    Add a node to the tree.\n" 
		<< "     p    Print the nodes in the tree.\n" 
		<< "     h    Display the help text.\n"
		<< "     q    Quit the program.\n";
}