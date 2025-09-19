#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H

#include <iostream>
#include <vector>

/*
    DoublyList.h
    -----------------
    Header file defining a basic Doubly Linked List in C++.

    Features:
      - Node structure with `data`, `next`, and `prev` pointers.
      - DoublyList class that manages head and tail pointers.
      - Core operations:
            * pushFront(int)   – Insert node at the beginning.
            * pushBack(int)    – Insert node at the end.
            * popFront()       – Remove node from the beginning.
            * popBack()        – Remove node from the end.
            * insertNode(int, int) – Insert node at a specific index.
            * searchNode(int)  – Find index of a key, or -1 if not found.
            * getHead() / getTail() – Access list endpoints.
            * getLength()  – Return length of the list.
      - Utility functions:
            * createList(vector<int>) – Build a list from given values.
            * printForward(Node*)         – Print list left to right.
            * printBackward(Node*)        – Print list right to left.

    Complexity:
      - Insertion/Deletion at head or tail: O(1)
      - Insertion/Deletion at arbitrary index: O(n)
      - Search: O(n)
      - Printing: O(n)

    This file serves as the interface for a simple, educational
    implementation of a doubly linked list in C++.
*/


class Node {
    public:
    int data;
    Node* next;
    Node* prev;
    Node* child;

    Node(int val);
};

class DoublyList {
    private:
    Node* head;
    Node* tail;
    Node* child;

    public:
    DoublyList();
    Node* getHead();
    Node* getTail();
    int getLength();
    Node* createList(vector<int> nums);
    int searchNode(int key);
    void pushBack(int val);
    void popFront();
    void pushFront(int val);
    void popBack();
    void insertNode(int val, int idx);
    void printForward(Node* head);
    void printBackward(Node* tail);
};

#endif