#ifndef CIRCULARLIST_H
#define CIRCULARLIST_H

#include <iostream>
#include <vector>
using namespace std;

/*
    * @class CircularList
    * @brief A a singly-linked circular list implementation.
    
    * This class provides a container for managing a list of nodes where the last node
    * points back to the first, creating a circular structure. This design allows for
    * efficient insertion and deletion at both the head and tail.
    
    * @note This implementation uses both a 'head' and a 'tail' pointer, which enables
    * O(1) complexity for inserting and deleting at either end of the list.
    * The only exception is `deleteAtTail`, which requires a full traversal.
    
    * ## Method Descriptions and Time Complexities
    * - **CircularList()**: The constructor that initializes an empty list by setting
    * the 'head' and 'tail' pointers to `NULL`.
    
    * - **insertAtHead(int val)**: Creates and adds a new node to the front of the list.
    * This is an **O(1)** operation.
    
    * - **insertAtTail(int val)**: Creates and appends a new node to the end of the list.
    * This is an **O(1)** operation.
    
    * - **printCircularList()**: Iterates through the entire list from head to tail,
    * printing the data of each node. This is an **O(n)** operation, where 'n' is
    * the number of nodes.
    
    * - **deleteAtHead()**: Removes the first node from the list and updates the 'head'
    * and 'tail' pointers accordingly. This is an **O(1)** operation.
    
    * - **deleteAtTail()**: Removes the last node from the list. Since it must
    * find the node before the tail, it requires a full traversal. This is an
    * **O(n)** operation.
*/

class Node {
    public:
    int data;
    Node* next;

    Node(int val);
};

class CircularList {
    Node* head;
    Node* tail;

    public:
    CircularList();
    void insertAtHead(int val);
    void insertAtTail(int val);
    void printCircularList();
    void deleteAtHead();
    void deleteAtTail();
};

#endif