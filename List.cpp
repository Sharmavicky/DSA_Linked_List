#include "List.h"
#include <vector>

// Node constructor
Node::Node(int value) {
    data = value;
    next = NULL;
    random = NULL;
}

// List constructor
List::List() {
    Head = Tail = NULL;
}

Node* List::getHead() { // return the head of a linked list
    return Head;
}

Node* List::getTail() { // return the tail of a linked list
    return Tail;
}

int List::getLength(Node* head) {// return length of linkedlist
    int length = 0;
    Node* temp = head;

    while (temp != NULL) {
        length++;
        temp = temp->next;
    }

    return length;
}

void List::insertNode(int value, int pos) {
    if (pos < 0) {
        cout << "Invalid index\n";
        return;
    }

    if (pos == 0) {
        pushFront(value);
        return;
    }

    Node* temp = Head;
    Node* newNode = new Node(value);

    for (int i = 0; i < pos - 1; i++) {
        if (temp == NULL) {
            cout << "Invalid pos\n";
            return;
        }
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;
}

void List::pushFront(int value) {
    Node* newNode = new Node(value);
    if (Head == NULL) {
        Head = Tail = newNode;
        return;
    }
    newNode->next = Head;
    Head = newNode;
}

void List::pushBack(int value) {
    Node* newNode = new Node(value);
    if (Head == NULL) {
        Head = Tail = newNode;
        return;
    }
    Tail->next = newNode;
    Tail = newNode;
}

void List::popFront() {
    if (Head == NULL) {
        cout << "linked_list is empty\n";
        return;
    }
    Node* temp = Head;
    Head = Head->next;
    if (Head == NULL) Tail == NULL;
    delete temp;
}

void List::popBack() {
    if (Head == NULL) {
        cout << "linked_list is empty\n";
        return;
    }
    Node* temp = Head;

    if (Head == Tail) { // only one element
        delete Head;
        Head = Tail = NULL;
        return;
    }

    while (temp->next != Tail) {
        temp = temp->next;
    }

    delete Tail;
    Tail = temp;
    Tail->next = NULL;
}

int List::search(int keyValue) {
    Node* temp = Head;
    int index = 0;

    while (temp != NULL) {
        if (temp->data == keyValue) return index;
        temp = temp->next;
        index++;
    }
    return -1;
}

void List::printLinkedList() {
    Node* temp = Head;
    while (temp != NULL) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

Node* List::createLink_ListfromArray(vector<int> nums) {
    int length = nums.size();
    Node* dummyNode = new Node(0);
    Node* temp = dummyNode;

    for (int n: nums) {
        temp->next = new Node(n);
        temp = temp->next;
    }

    Head = dummyNode->next;
    Tail = temp;

    delete dummyNode;
    return Head;
}
