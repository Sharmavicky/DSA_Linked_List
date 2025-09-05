#ifndef LIST_H
#define LIST_H

#include <iostream>
#include <vector>
using namespace std;

/*
    Linked List Implementation in C++

    * A linked list is a linear data structure where elements (nodes) are stored in separate objects, each containing a value and a pointer to the next node in the sequence. Unlike arrays, linked lists allow efficient insertion and deletion of elements without shifting other elements.

    This code defines:
    - Node class: Represents an element in the list, storing data and a pointer to the next node.
    - List class: Manages the linked list, supporting operations such as:
        * gethead(): returns the Head of the linked list.
        * getTail(): returns  the Tail of the linked list.
        * getLength(): returns the length of the linked list.
        * pushFront(value): Insert a value at the front.
        * pushBack(value): Insert a value at the end.
        * insertNode(value, pos): Insert a value at a specific position.
        * popFront(): Remove the first element.
        * popBack(): Remove the last element.
        * search(keyValue): Find the index of a value.
        * printLinkedList(): Print all elements in the list.
        * createLink_ListfromArray(vector<int> nums): takes an array as argument and create a linked list using it's value and return head.
*/

class Node {
public:
    int data;
    Node* next;
    Node* random;

    Node(int value);
};

class List {
    Node* Head;
    Node* Tail;

public:
    List();
    Node* getHead();
    Node* getTail();
    int getLength(Node* head);
    void insertNode(int value, int pos);
    void pushFront(int value);
    void pushBack(int value);
    void popFront();
    void popBack();
    int search(int keyValue);
    void printLinkedList();
    Node* createLink_ListfromArray(vector<int> nums);
};

#endif
