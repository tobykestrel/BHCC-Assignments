/*=====================================
| Toby Hansen, September 7 2025.      |
| Week 1 HW Extra Credit, CSC-242.    |
| This program creates a linked list  |
| to read a specific list of numbers. |
=====================================*/

#include <iostream>
using namespace std;

// This is the main function.
int main() {

    // This code banner is printed before the code is run.
    cout<< "/*=====================================\n"
        << "| Toby Hansen, September 7 2025.      |\n"
        << "| Week 1 HW Extra Credit, CSC-242.    |\n"
        << "| This program creates a linked list  |\n"
        << "| to read a specific list of numbers. |\n"
        << "=====================================*/\n\n";

	// This section is the Node structure containing an int and a pointer to another node.
	struct Node {
		int num;
		Node* next;
	};

	// This section creates a linked list from a root node LS, with values 2, 8, 12, 20.
	Node* LS = new Node{2, new Node{8, new Node{12, new Node{20, nullptr}}}};

	// This section reads the linked list to the console
	Node* current = LS;
	while (current != nullptr) {
		cout << current->num << endl;
		current = current->next;
	}
	cout << endl;

	// This section pauses the program for the user to see the list contents, and then exits on key press.
	system("pause"); 
	return 0;
}
