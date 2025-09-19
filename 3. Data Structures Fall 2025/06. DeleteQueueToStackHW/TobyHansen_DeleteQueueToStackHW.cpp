/*======================================
| Toby Hansen, September 18 2025.      |
| DeleteQueueToStackHW, CSC-242.       |
| This program is able to delete nodes |
| from both stack and queue structures.|
======================================*/

#include <iostream>
using namespace std;

// Node structure containing an int and a pointer to another node.
struct Node {
	int data;
	Node* next;
};

// Base LinkedList class
class LinkedList {
protected:
    Node* head;   // points to first node
    Node* tail;   // points to last node (helpful for queue)
public:
    LinkedList() : head(nullptr), tail(nullptr) {}
    ~LinkedList() { clear(); }

    void insertFront(int val) {
        Node* newNode = new Node{val, nullptr};
        if (!head) {
            head = tail = newNode;
        } else {
            newNode->next = head;
            head = newNode;
        }
    }

    void insertBack(int val) {
        Node* newNode = new Node{val, nullptr};
        if (!tail) {
            head = tail = newNode;
        } else {
            tail->next = newNode;
            tail = newNode;
        }
    }

    int removeFront() {
        if (!head) { throw runtime_error("List is empty!"); } 
        Node* temp = head;
        int val = temp->data;
        head = head->next;
        if (!head) tail = nullptr;
        delete temp;
        return val;
    }
	
	bool removeValue(int x) {
        if (!head) return false;
        if (head->data == x) {
            Node* temp = head;
            head = head->next;
            if (!head) tail = nullptr;
            delete temp;
            return true;
        }
        Node* prev = head;
        Node* curr = head->next;
        while (curr) {
            if (curr->data == x) {
                prev->next = curr->next;
                if (curr == tail) tail = prev;
                delete curr;
                return true;
            }
            prev = curr;
            curr = curr->next;
        }
        return false;
    }

    void display() {
        Node* curr = head;
        while (curr) {
            cout << curr->data << " -> ";
            curr = curr->next;
        }
        cout << "NULL\n";
    }

    void clear() {
        while (head) {
            removeFront();
        }
    }
};

// Stack class (LIFO) derived from LinkedList
class Stack : public LinkedList {
public:
    void push(int val) { insertFront(val); } // push to front/top
    int pop() { return removeFront(); } // pop from front/top
};

// Queue class (FIFO) derived from LinkedList
class Queue : public LinkedList {
public:
    void enqueue(int val) { insertBack(val); } // enqueue at back
    int dequeue() { return removeFront(); } // dequeue from front
};

// This section is for declaring function prototypes.
void enqueueToQueue(); 	// Enqueue a new node to the queue.
void pushToStack(); 	// Push a new node to the stack.
void removeFromList(); 	// Remove a node from a list.
void displayLists(); 	// Display lists' contents.
void printHelpText(); 	// Display the help text.

// This section is for global variables.
Queue q;
Stack s;

// This is the main function.
int main() {

    // This code banner is printed before the code is run.
    cout<< "/*======================================\n"
        << "| Toby Hansen, September 18 2025.      |\n"
        << "| DeleteQueueToStackHW, CSC-242.       |\n"
        << "| This program is able to delete nodes |\n"
        << "| from both stack and queue structures.|\n"
        << "======================================*/\n\n";

	// This section is a command-loop repeating the program until the user decides to quit.
	char command;
	cout << "Enter command ('h' for list of supported commands): ";
	while(true) {
		command = cin.get();
		cin.ignore(10000, '\n');
		switch (command) {
			case 'd': cout << q.dequeue() << " dequeued.\n"; break;	// Dequeues a node from the queue.
			case 'u': cout << s.pop() << " unstacked.\n"; break;	// Unstack a node from the stack.
			case 'e': enqueueToQueue(); break; 	// Enqueue a new node to the queue.
			case 'p': pushToStack(); break; 	// Push a new node to the stack.
			case 'r': removeFromList(); break; 	// Remove a node from a list.
			case 'l': displayLists(); break; 	// Display lists' contents.
			case 'h': printHelpText(); break; 	// Display the help text.
			case 'q': system("pause"); return 0;// Quit the program.
		}
		cout << "Command: ";
	}
}

// Enqueue a new node to the queue.
void enqueueToQueue() {
	// This section takes the user's input on what the int should be and queues it.
	int newNum;
    cout << "Enter value of new node to be enqueued: ";
    while (!(cin >> newNum)) { // While the input is invalid:
        cin.clear(); // Clear errors.
        cin.ignore(10000, '\n'); // Ignore all remaining characters.
        cout << "Invalid input. Enter again: "; // Let the user know and ask again.
    }
	cin.ignore(10000, '\n');
	q.enqueue(newNum);
}

// Push a new node to the stack.
void pushToStack() {
	// This section takes the user's input on what the int should be and stacks it.
	int newNum;
    cout << "Enter value of new node to be pushed: ";
    while (!(cin >> newNum)) { // While the input is invalid:
        cin.clear(); // Clear errors.
        cin.ignore(10000, '\n'); // Ignore all remaining characters.
        cout << "Invalid input. Enter again: "; // Let the user know and ask again.
    }
	cin.ignore(10000, '\n');
	s.push(newNum);
}	

// Remove a node from a list.
void removeFromList() {
    // This section takes the user's input on whether to remove from the stack or queue.
	string stackOrQueue;
    cout << "Remove a node from stack or queue? (s/q): ";
    getline(cin, stackOrQueue);
	while (stackOrQueue != "s" && stackOrQueue != "q") {
		cout << "Invalid input, enter 's' for stack or 'q' for queue: ";
		getline(cin, stackOrQueue);
	}
	
	// This section takes the user's input on what value should be removed.
	int delVal;
    cout << "Enter value of node to be removed: ";
    while (!(cin >> delVal)) { // While the input is invalid:
        cin.clear(); // Clear errors.
        cin.ignore(10000, '\n'); // Ignore all remaining characters.
        cout << "Invalid input. Enter again: "; // Let the user know and ask again.
    }
	cin.ignore(10000, '\n');

	// This section removes the node from the specified list.
	switch (stackOrQueue[0]) {
		case 's': s.removeValue(delVal); break;
		case 'q': q.removeValue(delVal); break;
	}
}

// Display lists' contents.
void displayLists() {
	cout << "Queue: ";
	q.display();
	cout << "Stack: ";
	s.display();
}	

// This function displays the help text with the supported commands.
void printHelpText() {
	cout<< "Supported commands: \n"
		<< "     e    Enqueue a new node to the queue.\n" 
		<< "     d    Dequeue a node from the queue.\n" 
		<< "     p    Push a new node to the stack.\n" 
		<< "     u    Unstack a node from the stack.\n" 
		<< "     r    Remove a node from a list.\n" 
		<< "     l    Display lists' contents.\n" 
		<< "     h    Display the help text.\n"
		<< "     q    Quit the program.\n";
}
