#include <iostream>
#include <vector>
#include "List.h"
using namespace std;

/*
    * Function: RotateLst
    * --------------------
    * Rotates a singly linked list to the right by k positions.
    
    * Example:
    *    Input:  1 -> 2 -> 3 -> 4 -> 5, k = 2
    *    Output: 4 -> 5 -> 1 -> 2 -> 3
    
    * Approach:
    *    1. Find the length of the linked list.
    *    2. Connect the last node back to the head (making it circular).
    *    3. Compute the effective rotation: k = k % length.
    *    4. Find the new head at position (length - k).
    *    5. Break the circular link and return the new head.
    
    * Time Complexity: O(n)   // one pass to calculate length, one pass to rotate
    * Space Complexity: O(1)  // only constant extra pointers used
*/


class Solution {
    public:
    Node* RotateLst(Node* head, int k) {
        if (!head || !head->next || k == 0) return head;

        // Step 1: Find length
        int length = 1;
        Node* temp = head;
        while (temp->next != NULL) {
            temp = temp->next;
            length++;
        }

        // Step 2: Connect last node to head (make it circular)
        temp->next = head;

        // Step 3: Find new head position
        k = k % length; // handle k > length
        int stepsToNewHead = length - k;

        temp = head;
        for (int i = 0; i < stepsToNewHead - 1; i++) {
            temp = temp->next;
        }

        // Step 4: Break the circle
        Node* newHead = temp->next;
        temp->next = NULL;

        return newHead;
    }
};

// main function 
int main() {
    vector<int> ar = {1, 2};
    int k = 1;

    List ll;
    for(int n: ar) {
        ll.pushBack(n);
    }

    cout << "list before rotation: \n";
    ll.printLinkedList();
    cout << "\n";

    cout << "list after rotation: \n";
    Node* head = ll.getHead();
    Node* result = Solution().RotateLst(head, k);

    Node* temp = result;

    while (temp != NULL) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;

    return 0;
}