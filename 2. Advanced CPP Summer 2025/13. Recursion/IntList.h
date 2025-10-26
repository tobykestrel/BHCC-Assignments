/*=====================================
| Toby Hansen, August 18 2025.        |
| Recursion Lab, CSC-237-200.         |
| This program uses a linked list to  |
| organize and manage an integer set. |
=====================================*/

// Specification file for the IntList class.
#ifndef INTLIST_H
#define INTLIST_H
#include <string>

class IntList {
private:
   // Declare a structure for the list
   struct ListNode {
      int value;              // The value in this node
      struct ListNode *next;  // To point to the next node
   }; 
   ListNode *head;            // List head pointer

public:
   // Constructor
   IntList() { head = nullptr; }
      
   // Destructor
   ~IntList();
      
   // Linked list operations
   void appendNode(int);   // Append a node at the end of the list.
   void insertNode(int);   // Insert a node into the list, maintaining a sorted order.
   void deleteNode(int);   // Delete a node from the linked list.
   void displayListLen() const;  // Display the length of the linked list.
   void displayListSum() const;  // Display the total sum of the linked list.
   void displayMaxValue() const; // Display the largest node in the linked list.
   int getLen() const;  // Get the number of nodes in the linked list.
   int getSum() const;  // Get the sum of all nodes in the linked list.
   void printList() const;                      // Print the contents of the list to the console.
	void printListRecursively() const;           // Print the list contents. (recursively)
	void printListBackwardsRecursively() const;  // Print the list contents backwards. (recursively)
	void printNodesRecursively(ListNode*) const;          // Print the list node by node. (recursively)
	void printNodesBackwardsRecursively(ListNode*) const; // Print the list node by node backwards. (recursively)
   void displayListLenRecursively() const;   // Display the length of the linked list. (recursively)
   void displayListSumRecursively() const;   // Display the total sum of the linked list. (recursively)
   void displayMaxValueRecursively() const;  // Display the largest node in the linked list. (recursively)
   int getLenRecursively(ListNode*) const;      // Get the number of nodes in the linked list. (recursively)
   int getSumRecursively(ListNode*) const;      // Get the sum of all nodes in the linked list. (recursively)
   int getMaxRecursively(ListNode*, int) const; // Get the sum of all nodes in the linked list. (recursively)
};
#endif