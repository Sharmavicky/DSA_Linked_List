#include <iostream>
#include <vector>
#include "List.h"
using namespace std;

/*
    * Swap Nodes in Pairs (Linked List)

    * Approach:
        - Iterate through the list two nodes at a time.
        - For each adjacent pair (first, second), update pointers so that: second → first → third
        - Maintain a 'prev' pointer to connect the previous swapped pair with the current one.
        - Update the head after the first swap since the second node becomes the new head.

    Example:
    Input:  1 → 2 → 3 → 4 → 5
    Output: 2 → 1 → 4 → 3 → 5

    Time Complexity: O(n)   (each node is visited once)
    Space Complexity: O(1)  (in-place swapping, no extra data structures)
*/


class Solution {
    public:
    Node* swapNodes(Node* head) {
        if (head == NULL || head->next == NULL) return head;

        Node* first = head;
        Node* second = head->next;
        Node* prev = NULL;

        while (first != NULL && second != NULL) {
            Node* third = second->next;

            // swap nodes
            second->next = first;
            first->next = third;

            // connect with prev node after swapping
            if (prev != NULL) prev->next = second;
            else head = second;

            // move forward
            prev = first;
            first = third;
            if (third != NULL) second = third->next;
            else second = NULL;
        }

        // return new head;
        return head;
    }
};

// main funcion 
int main() {
    vector<int> ar = {1, 2, 3, 4};

    List ll;
    for (int n: ar) {
        ll.pushBack(n);
    };

    cout << "linked list before swapping: \n";
    ll.printLinkedList();

    cout << "linked list after swapping: \n";
    Node* head = ll.getHead();

    Node* result = Solution().swapNodes(head);

    Node* temp = head;

    while (temp != NULL) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL";

    return 0;
}