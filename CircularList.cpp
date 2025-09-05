#include <iostream>
#include "CircularList.h"
using namespace std;

/*
    * @class CircularList
    * @brief An implementation of a singly-linked circular list.
    *
    * This class manages a list of nodes where the last node's 'next' pointer
    * points back to the first node, forming a circle. The list maintains both
    * a 'head' and a 'tail' pointer for efficient access to both ends.
    
    * Key Properties:
    * - The 'head' pointer references the first node of the list.
    * - The 'tail' pointer references the last node of the list.
    * - The 'tail's 'next' pointer always points back to the 'head'.
    *
    * Method Explanations and Time Complexities:

    * 1.  **insertAtHead(int val)**
    * - **Explanation:** Creates a new node and places it at the beginning of the list. It handles the special case of an empty list and updates the 'head' pointer and the 'tail's 'next' pointer to maintain the circular structure.
    * - **Time Complexity:** O(1) - This is a constant-time operation because it only involves a few pointer manipulations, regardless of the list's size.

    * 2.  **insertAtTail(int val)**
    * - **Explanation:** Creates a new node and appends it to the end of the list. It also handles the empty list case and updates the 'tail' pointer and its 'next' pointer to point to the new node and then back to the 'head'.
    * - **Time Complexity:** O(1) - Similar to `insertAtHead`, this is a constant-time operation due to direct access to the 'tail' pointer.

    * 3.  **deleteAtHead()**
    * - **Explanation:** Removes the first node of the list. It handles edge cases like an empty list or a list with a single node. The 'head' pointer is moved to the next node, and the old head is deallocated to free memory.
    * - **Time Complexity:** O(1) - This is a constant-time operation because it only requires updating a couple of pointers.

    * 4.  **deleteAtTail()**
    * - **Explanation:** Removes the last node of the list. To do this, it must traverse the entire list from the 'head' to find the node located just before the 'tail'. This "second-to-last" node then becomes the new 'tail'.
    * - **Time Complexity:** O(n) - This is a linear-time operation because, in a singly linked list, finding the preceding node requires iterating through the list, which takes time proportional to the number of nodes (n).

    * 5.  **printCircularList()**
    * - **Explanation:** Traverses the entire list starting from the 'head' and prints the data of each node until it returns to the 'head' again, confirming the circular path.
    * - **Time Complexity:** O(n) - Linear time is required to visit and print every single node in the list.
*/

// Node constructor
Node::Node(int val) {
    data = val;
    next = NULL;
}

CircularList::CircularList() {
    head = tail = NULL;
}

void CircularList::insertAtHead(int val) {
    Node* newNode = new Node(val);

    if (tail == NULL) {
        head = tail = newNode;
        tail->next = head;
    }
    newNode->next = head;
    head = newNode;
    tail->next = head; // update head
}

void CircularList::insertAtTail(int val) {
    Node* newNode = new Node(val);

    if (tail == NULL) {
        head = tail = newNode;
        tail->next = head;
    }
    tail->next = newNode;
    tail = newNode;
    tail->next = head;
}

void CircularList::printCircularList() {
    if (tail == NULL) {
        cout << "List is empty\n";
        return;
    }

    Node* temp = tail->next; // head;
    while (temp != tail) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << temp->data << " -> "; // tail data;
    cout << "'head'";
}

void CircularList::deleteAtHead() {
    if (tail == NULL) {
        cout << "list is empty.\n";
        return;
    }

    if (head == tail) {// single node
        delete tail;
        head = tail = NULL;
        return;
    }

    Node* toDelete = head;
    head = head->next;
    toDelete->next = NULL;
    tail->next = head;
    delete toDelete;
}

void CircularList::deleteAtTail() {
    if (tail == NULL) { // list is empty
        cout << "list is empty!!\n";
        return;
    }

    if (head == tail) { // list contains single node
        delete tail;
        head = tail = NULL;
        return;
    }

    Node* newTail = tail->next; // head;
    while (newTail->next != tail) {
        newTail = newTail->next;
    }

    Node* toDelete = tail;
    tail = newTail;
    tail->next = head;
    delete toDelete;
}