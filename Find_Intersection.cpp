#include <iostream>
#include <vector>
#include "List.h"
using namespace std;

/*
    * Problem: Find the intersection point of two singly linked lists.

    * Approach:
        * Use two pointers to traverse both linked lists.
        * When a pointer reaches the end of a list, redirect it to the head of the other list.
        * If the lists intersect, the pointers will meet at the intersection node after at most 2 passes.
        * If the lists do not intersect, both pointers will eventually become NULL at the same time.

    * Time Complexity: O(n + m), where n and m are the lengths of the two linked lists.
    * Space Complexity: O(1)
*/

class Solution {
    public:
    Node* getIntersection(Node* headA, Node* headB) {
        // Edge case: if either list is empty
        if (headA == NULL || headB == NULL) {
            return NULL;
        }

        Node* tempA = headA;
        Node* tempB = headB;

        // traverse both lists
        while (tempA != tempB) {
            tempA = (tempA == NULL) ? headB : tempA->next;
            tempB = (tempB == NULL) ? headA : tempB->next;
        }

        return tempA; // or tempB, both are at same intersection point.
    }
};

// main function
int main() {
    Node* headA = new Node(4);
    headA->next = new Node(1);
    headA->next->next = new Node(8);
    headA->next->next->next = new Node(4);
    headA->next->next->next->next = new Node(5);

    Node* headB = new Node(5);
    headB->next = new Node(0);
    headB->next->next = new Node(1);
    headB->next->next->next = headA->next->next; // Intersection at node with value 8

    Node* intersectionNode = Solution().getIntersection(headA, headB);

    if (intersectionNode != NULL) {
        cout << "Intersection at node with value: " << intersectionNode->data << endl;
    } else {
        cout << "No intersection." << endl;
    }

    return 0;
}