#include <iostream>
#include "List.h"
#include <algorithm>
using namespace std;

/*
    * @class reverseLinkedList
    * @brief Provides two approaches to reverse a singly linked list.
    *
    * This class demonstrates both a brute force and an optimal method for
    * reversing a linked list:
    *
    * 1. BruteForce:
    *    - Stores all node values in a vector.
    *    - Reverses the vector.
    *    - Constructs a new linked list using the reversed values.
    *    - Time Complexity: O(n)
    *    - Space Complexity: O(n)
    *
    * 2. OptimalApproach:
    *    - Reverses the linked list in-place using three pointers (prev, current, next).
    *    - Modifies the original list without using extra memory.
    *    - Time Complexity: O(n)
    *    - Space Complexity: O(1)
    *
    * The class highlights trade-offs between extra space usage and in-place
    * manipulation while ensuring correctness in both methods.
*/

class reverseLinkedList {
    public:
    Node* BruteForce(Node* Head) {
        vector<int> rev;

        for (Node* temp = Head; temp != NULL; temp = temp->next) {
            rev.push_back(temp->data);
        }

        // reverse the array
        int left = 0, right = rev.size()-1;

        while (left < right) {
            swap(rev[left++], rev[right--]);
        }

        // make a new linked list
        Node* dummy = new Node(0);
        Node* temp  = dummy;

        for (int n: rev) {
            Node* newNode = new Node(n);
            temp->next = newNode;
            temp = temp->next;
        }

        Node* newHead = dummy->next;
        // delete dummyNode to prevent memory leak
        delete dummy;
        return newHead;
    }

    Node* OptimalApproach(Node* Head) {
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
    Node* result = reverseLinkedList().BruteForce(head);

    cout << result->data;

    return 0;
}