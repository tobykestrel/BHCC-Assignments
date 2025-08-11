/*=====================================
| Toby Hansen, August 11 2025.        |
| Linked Lists Lab, CSC-237-200.      |
| This program uses a linked list to  |
| organize and manage an integer set. |
=====================================*/

// Implementation file for the IntList class (Expanded upon from given NumberList class).
#include <iostream>  // For cout
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
		} else { cout << "Data value " << num << " not found."; }
	}
}

//**************************************************
// displayList shows the value                     *
// stored in each node of the linked list          *
// pointed to by head.                             *
//**************************************************
void IntList::printList() const {
	cout << " head=" << setw(16) << setfill('0') << hex << uppercase << (unsigned long long)(size_t)head << endl;
	
	// While nodePtr points to a node, traverse the list.
	ListNode* nodePtr = head;
	while (nodePtr) {
		// Display the pointer memory location of the node.
		cout << setw(16) << setfill('0') << hex << uppercase << (unsigned long long)(size_t)head;

		// Display the value of the node.
		cout << setw(10) << ":  value= " << setw(10) << setfill(' ') << dec << left << nodePtr->value << setw(5) << "next=";

		// Display the pointer memory location of the next node.
		cout << setw(16) << setfill('0') << hex << uppercase << (unsigned long long)(size_t)head->next << endl;

		// Move to the next node.
		nodePtr = nodePtr->next;
	}
}

// Get the largest node in the linked list.
void IntList::displayMaxValue() const {

	// This section ensures that the list is not empty.
	if (head == nullptr) {
		cout << "List is empty.\n"; 
		return;
	}

	// nodePtr starts at the head and moves through the list to find the max value.
	int max = head->value;
	ListNode* nodePtr = head->next;

	// While nodePtr points to a node, traverse the list.
	while (nodePtr) {
		// If the node is higher than the current highest, save it.
		if (nodePtr->value > max) max = nodePtr->value;

		// Move to the next node.
		nodePtr = nodePtr->next;
	}
	cout << "Maximum value in list: " << max << endl;
} 

// Get the number of nodes in the linked list.
int IntList::getLength() const {
	// nodePtr starts at the head and moves through the list to find the highest.
	int length = 0;
	ListNode* nodePtr = head;

	// While nodePtr points to a node, traverse the list.
	while (nodePtr) {
		// Increment the length counter.
		length++;

		// Move to the next node.
		nodePtr = nodePtr->next;
	}
	return length;
}     

// Get the sum of all nodes in the linked list.
int IntList::getSum() const {
	// nodePtr starts at the head and moves through the list to find the highest.
	int sum = 0;
	ListNode* nodePtr = head;

	// While nodePtr points to a node, traverse the list.
	while (nodePtr) {
		// Increment the length counter.
		sum += nodePtr->value;

		// Move to the next node.
		nodePtr = nodePtr->next;
	}
	return sum;
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