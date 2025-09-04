#include "DoublyList.h"
#include <vector>
using namespace std;

/*
    Doubly Linked List Implementation in C++

    This class implements a basic doubly linked list data structure 
    with the following operations:

    ✔ Constructors:
        - Node(int val): creates a new node with given data.
        - DoublyList(): initializes an empty list (head = tail = NULL).

    ✔ Core Operations:
        - pushFront(int val): insert node at the beginning.
        - pushBack(int val): insert node at the end.
        - popFront(): remove node from the beginning.
        - popBack(): remove node from the end.
        - insertNode(int val, int idx): insert node at given index.
        - searchNode(int key): return index of key if found, else -1.
        - getHead(): return pointer to head node.
        - getTail(): return pointer to tail node.
        - getLength(): return length of list.

    ✔ Utility Functions:
        - createList(vector<int>): build a list from an array of values.
        - printForward(Node* head): print list left-to-right.
        - printBackward(Node* tail): print list right-to-left.

    ✔ Complexity:
        - Insertion/Deletion at head/tail: O(1)
        - Search / Insertion at index: O(n)
        - Printing: O(n)

    This implementation is useful for learning and practicing 
    fundamental linked list operations in C++. 
*/


// Node constructor
Node::Node(int val) {
    data = val;
    next = prev = NULL;
}

// List constructor
DoublyList::DoublyList() {
    head = tail = NULL;
}

// returns the head of list
Node* DoublyList::getHead() {
    return head;
}

// return the tail of list
Node* DoublyList::getTail() {
    return tail;
}

// return the length of list
int DoublyList::getLength() {
    Node* temp = head;
    int length = 0;

    while (temp != NULL) {
        length++;
        temp = temp->next;
    };

    return length;
}

// add newNode in front of headNode and update head
void DoublyList::pushFront(int val) {
    Node* newNode = new Node(val);

    // if list is empty
    if (head == NULL) {
        head = tail = newNode;
        return;
    }
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
}

// add newNode next to tail and update tail
void DoublyList::pushBack(int val) {
    Node* newNode = new Node(val);

    // if list is empty
    if (head == NULL) {
        head = tail = newNode;
        return;
    }
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}

// remove headNode and update head.
void DoublyList::popFront() {
    // edge case: if list is empty
    if (head == NULL) return;

    // update head node
    Node* temp = head;
    head = temp->next;

    // remove connection
    if (head != NULL) head->prev = NULL;
    else tail = NULL;

    // free memory
    delete temp;
}

// remove tailNode and update tail
void DoublyList::popBack() {
    if (head == NULL) return; // list is empty

    // update tail
    Node* temp = tail;
    tail = tail->prev;

    // remove connection
    if (tail != NULL) tail->next = NULL;
    else head = NULL; // list became empty

    // free memory
    delete temp;
}

// insert node at given idx
void DoublyList::insertNode(int val, int idx) {
    int length = getLength();

    if (idx < 0 || idx > length) {
        cout << "Invalid idxition\n";
        return;
    }

    if (idx == 0) {
        pushFront(val);
        return;
    }

    if (idx == length) {
        pushBack(val);
        return;
    }

    // insert in the middle
    Node* newNode = new Node(val);
    Node* temp = head;

    // move to (idx - 1)-th node
    for (int i = 0; i < idx - 1; i++) {
        temp = temp->next;
    }

    Node* nextNode = temp->next;

    // update connections
    temp->next = newNode;
    newNode->prev = temp;
    newNode->next = nextNode;
    nextNode->prev = newNode;
}

// return the index of key
int DoublyList::searchNode(int key) {
    int idx = 0;

    for (Node* temp = head; temp != NULL; temp=temp->next) {
        if (temp->data == key) return idx;
        idx++;
    }

    return -1; // key is not present in list.
}

// creates a doublylinked list and returns head
Node* DoublyList::createList(vector<int> nums) {
    Node* dummyNode = new Node(0);
    Node* temp = dummyNode;

    for(int n: nums) {
        Node* newNode = new Node(n);
        temp->next = newNode;
        newNode->prev = temp;
        temp = temp->next;
    }

    head = dummyNode->next;
    if (head != NULL) head->prev = NULL;

    delete dummyNode; // prevents memory leak
    return head; // return head
}

// print forward
void DoublyList::printForward(Node* head) {
    cout << "Forward: ";
    for (Node* temp = head; temp != NULL; temp = temp->next) {
        cout << temp->data;
        if (temp->next != NULL) cout << " <-> "; // show link
    }
    cout << "\n";
}

// print backward
void DoublyList::printBackward(Node* tail) {
    cout << "Backward: ";
    for (Node* temp = tail; temp != NULL; temp = temp->prev) {
        cout << temp->data;
        if (temp->prev != NULL) cout << " <-> "; // show link
    }
    cout << "\n";
}