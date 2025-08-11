/*=====================================
| Toby Hansen, August 11 2025.        |
| Linked Lists Lab, CSC-237-200.      |
| This program uses a linked list to  |
| organize and manage an integer set. |
=====================================*/

// Specification file for the IntList class (Expanded upon from given NumberList class).
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
   void appendNode(int);      // Append a new node at the end of the list.
   void insertNode(int);      // Insert a new node into the list, maintaining a sorted order.
   void deleteNode(int);      // Remove a node from the list.
   void printList() const;    // Print the contents of the list to the console.
   void displayMaxValue() const;   // Get the largest node in the linked list.
   int getLength() const;     // Get the number of nodes in the linked list.
   int getSum() const;        // Get the sum of all nodes in the linked list.
};
#endif