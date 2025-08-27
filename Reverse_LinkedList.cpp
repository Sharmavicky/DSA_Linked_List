#include <iostream>
#include "List.h"
using namespace std;

/*
    * Time Complexity: O(n), where n is the length of the linked list.

    * Space Complexity: O(1)
*/

class reverseLinkedList {
    public:
    Node* reverseLinkedlist(Node* Head) {
        Node* prev = NULL;
        Node* current = Head;
        Node* next = NULL;
    
        while (current != NULL) {
            next = current->next;
            current->next = prev;
            prev = current;
            current = next;
        }
    
        return prev; // new Head after reversing linked-list;
    }
};

// main function
int main() {
    List myList;

    myList.pushFront(2);
    myList.pushFront(4);
    myList.pushFront(6);

    Node* head = myList.getHead();
    
    // reverse a list
    Node* result = reverseLinkedList().reverseLinkedlist(head);

    cout << result->data;

    return 0;
}