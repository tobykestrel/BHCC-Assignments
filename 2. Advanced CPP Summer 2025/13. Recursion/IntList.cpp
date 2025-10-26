/*=====================================
| Toby Hansen, August 18 2025.        |
| Recursion Lab, CSC-237-200.         |
| This program uses a linked list to  |
| organize and manage an integer set. |
=====================================*/

// Implementation file for the IntList class.
#include <iostream> 
#include <iomanip>
#include "IntList.h"
using namespace std;

//**************************************************
// appendNode appends a node containing the        *
// value pased into num, to the end of the list.   *
//**************************************************
void IntList::appendNode(int num) {
	ListNode* newNode;  // To point to a new node
	ListNode* nodePtr;  // To move through the list

	// Allocate a new node and store num there.
	newNode = new ListNode;
	newNode->value = num;
	newNode->next = nullptr;

	// If there are no nodes in the list, make newNode the first node.
	// Otherwise, insert newNode at end.
	if (!head) head = newNode;
	else  {
		// Initialize nodePtr to head of list.
		nodePtr = head;

		// Find the last node in the list.
		while (nodePtr->next) nodePtr = nodePtr->next;

		// Insert newNode as the last node.
		nodePtr->next = newNode;
	}
}

//**************************************************
// The insertNode function inserts a node with     *
// num copied to its value member.                 *
//**************************************************
void IntList::insertNode(int num) {
	ListNode* newNode;					// A new node
	ListNode* nodePtr;					// To traverse the list
	ListNode* previousNode = nullptr;	// The previous node

	// Allocate a new node and store num there.
	newNode = new ListNode;
	newNode->value = num;

	// If there are no nodes in the list, make newNode the first node.
	// Otherwise, insert newNode.
	if (!head) {
		head = newNode;
		newNode->next = nullptr;
	} else {
		// Position nodePtr at the head of list.
		nodePtr = head;

		// Initialize previousNode to nullptr.
		previousNode = nullptr;

		// Skip all nodes whose value is less than num.
		while (nodePtr != nullptr && nodePtr->value < num) {
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		// If the new node is to be the 1st in the list, insert it before all other nodes.
		// Otherwise insert after the previous node.
		if (previousNode == nullptr) {
			head = newNode;
			newNode->next = nodePtr;
		} else {
			previousNode->next = newNode;
			newNode->next = nodePtr;
		}
	}
}

//**************************************************
// The deleteNode function searches for a node     *
// with num as its value. The node, if found, is   *
// deleted from the list and from memory.          *
//**************************************************
void IntList::deleteNode(int num)
{
	ListNode* nodePtr;       // To traverse the list
	ListNode* previousNode = nullptr;  // To point to the previous node

	// If the list is empty, do nothing.
	if (!head) return;

	// Determine if the first node is the one.
	if (head->value == num) {
		nodePtr = head->next;
		delete head;
		head = nodePtr;
	} else {
		// Initialize nodePtr to head of list
		nodePtr = head;

		// Skip all nodes whose value member is 
		// not equal to num.
		while (nodePtr != nullptr && nodePtr->value != num) {
			previousNode = nodePtr;
			nodePtr = nodePtr->next;
		}

		// If nodePtr is not at the end of the list, 
		// link the previous node to the node after
		// nodePtr, then delete nodePtr.
		if (nodePtr) {
			previousNode->next = nodePtr->next;
			delete nodePtr;
		} else { cout << "Data value " << num << " not found.\n"; }
	}
}

// This function prints the list contents.
void IntList::printList() const {
	cout << "head=" << setw(16) << setfill('0') << hex << uppercase << (unsigned long long)(size_t)head << dec << endl;
	
	// While nodePtr points to a node, traverse the list.
	ListNode* nodePtr = head;
	while (nodePtr) {
		// Display the pointer memory location of the node.
		cout << setw(16) << setfill('0') << hex << uppercase << (unsigned long long)(size_t)nodePtr << dec;

		// Display the value of the node.
		cout << setw(10) << ":  value= " << setw(10) << setfill(' ') << left << nodePtr->value << right << setw(5) << "next=";

		// Display the pointer memory location of the next node.
		cout << setw(16) << setfill('0') << hex << uppercase << (unsigned long long)(size_t)nodePtr->next << dec << endl;

		// Move to the next node.
		nodePtr = nodePtr->next;
	}
}

// This function prints the list contents.
void IntList::printListRecursively() const {
	cout << "Recursive print of list, head=" << setw(16) << setfill('0') << hex << uppercase << (unsigned long long)(size_t)head << dec << endl;
	printNodesRecursively(head);
}
// This function prints the list contents node by node recursively.
void IntList::printNodesRecursively(ListNode* nodePtr) const {
	if (nodePtr) {
		// Display the pointer memory location of the node.
		cout << setw(16) << setfill('0') << hex << uppercase << (unsigned long long)(size_t)nodePtr << dec;

		// Display the value of the node.
		cout << setw(10) << ":  value= " << setw(10) << setfill(' ') << left << nodePtr->value << right << setw(5) << "next=";

		// Display the pointer memory location of the next node.
		cout << setw(16) << setfill('0') << hex << uppercase << (unsigned long long)(size_t)nodePtr->next << dec << endl;

		// Move to the next node.
		printNodesRecursively(nodePtr->next);
	}
}

// This function prints the list contents backwards.
void IntList::printListBackwardsRecursively() const {
	cout << "Recursive print of list backwards, head=" << setw(16) << setfill('0') << hex << uppercase << (unsigned long long)(size_t)head << dec << endl;
	printNodesBackwardsRecursively(head);
}
// This function prints the list contents node by node recursively backwards.
void IntList::printNodesBackwardsRecursively(ListNode* nodePtr) const {
	// Move to the next node.
	if (nodePtr->next) printNodesBackwardsRecursively(nodePtr->next);

	// Display the pointer memory location of the node.
	cout << setw(16) << setfill('0') << hex << uppercase << (unsigned long long)(size_t)nodePtr << dec;

	// Display the value of the node.
	cout << setw(10) << ":  value= " << setw(10) << setfill(' ') << left << nodePtr->value << right << setw(5) << "next=";

	// Display the pointer memory location of the next node.
	cout << setw(16) << setfill('0') << hex << uppercase << (unsigned long long)(size_t)nodePtr->next << dec << endl;
}

// This function displays the length of nodes in the list.
void IntList::displayListLen() const {
	cout << "Length of list: " << IntList::getLen() << " nodes\n";
}
// This function returns the number of nodes in the linked list.
int IntList::getLen() const {
	// nodePtr starts at the head and moves through the list to find the highest.
	int length = 0;
	ListNode* nodePtr = head;

	// While nodePtr points to a node, traverse the list.
	while (nodePtr) {
		length++; // Increment the length counter.
		nodePtr = nodePtr->next; // Move to the next node.
	}
	return length;
}     

// This function displays the length of nodes in the list.
void IntList::displayListLenRecursively() const {
	cout << "Length of list: " << IntList::getLenRecursively(head) << " nodes\n";
}
// This function uses recursion to return the length of the list.
int IntList::getLenRecursively(ListNode* nodePtr) const {
	if (!nodePtr) return 0; // Node is empty
	return 1 + getLenRecursively(nodePtr->next); // Otherwise, add 1 to the total and try the next.
}

// This function displays the total sum of all list values.
void IntList::displayListSum() const {
	cout << "Sum of all list values: " << IntList::getSum() << endl;
}
// This function returns the sum of all nodes in the linked list.
int IntList::getSum() const {
	// nodePtr starts at the head and moves through the list to find the highest.
	int sum = 0;
	ListNode* nodePtr = head;

	// While nodePtr points to a node, traverse the list.
	while (nodePtr) {
		sum += nodePtr->value; // Increment the length counter.
		nodePtr = nodePtr->next; // Move to the next node.
	}
	return sum;
}   

// This function displays the sum of all nodes in the list.
void IntList::displayListSumRecursively() const {
	cout << "Sum of all list values: " << IntList::getSumRecursively(head) << endl;
}
// This function uses recursion to return the sum of the list.
int IntList::getSumRecursively(ListNode* nodePtr) const {
	if (!nodePtr) return 0; // Node is empty
	return nodePtr->value + getSumRecursively(nodePtr->next); // Otherwise, add the value to the total and try the next.
}

// This function displays the largest node in the linked list.
void IntList::displayMaxValue() const {
	// This section ensures that the list is not empty.
	if (!head) { cout << "List is empty.\n"; return; }

	// While nodePtr points to a node, traverse the list.
	int max = head->value;
	ListNode* nodePtr = head->next;
	while (nodePtr) {
		if (nodePtr->value > max) max = nodePtr->value; // Update the max value if necessary.
		nodePtr = nodePtr->next; // Move to the next node.
	}
	cout << "Maximum value in list: " << max << endl; // Display the max.
} 

// This function displays the largest node in the linked list. (recursively)
void IntList::displayMaxValueRecursively() const {
	if (!head) { cout << "List is empty.\n"; return; } // Ensures the list is not empty.
	cout << "Maximum value in list: " << getMaxRecursively(head->next, head->value) << endl; // Displays the max.
}
// This function uses recursion to return the max value of the list.
int IntList::getMaxRecursively(ListNode* nodePtr, int currentMax) const {
	if (!nodePtr) return currentMax; // If node is empty, return the maximum.
	if (nodePtr->value > currentMax) currentMax = nodePtr->value; // Update the currentMax value if necessary.
	return getMaxRecursively(nodePtr->next, currentMax); // Try the next node in the list.
}     

//**************************************************
// Destructor                                      *
// This function deletes every node in the list.   *
//**************************************************
IntList::~IntList() {
	ListNode* nodePtr;   // To traverse the list
	ListNode* nextNode;  // To point to the next node

	// Position nodePtr at the head of the list.
	nodePtr = head;

	// While nodePtr is not at the end of the list...
	while (nodePtr != nullptr) {
		// Save a pointer to the next node.
		nextNode = nodePtr->next;

		// Delete the current node.
		delete nodePtr;

		// Position nodePtr at the next node.
		nodePtr = nextNode;
	}
}