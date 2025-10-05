#include <iostream>
#include <vector>
#include "List.h"
using namespace std;

/**
    * @class Solution
    * @brief Reorders a singly linked list in-place to follow the pattern:
    *        L0 → Ln → L1 → Ln-1 → L2 → Ln-2 → ...
    *
    * This class implements the optimal O(n) time and O(1) space solution
    * using three key steps:
    *   1. Find the middle node using slow–fast pointer technique.
    *   2. Reverse the second half of the linked list.
    *   3. Merge both halves alternately to achieve the required order.
    *
    * Helper Functions:
    *   - getMiddleNode(Node* head): Returns the middle node of the list.
    *   - reverseList(Node* head): Reverses the linked list and returns new head.
    *
    * @complexity
    *   Time:  O(n)
    *   Space: O(1)
    *
    * @example
    *   Input:  1 → 2 → 3 → 4 → 5
    *   Output: 1 → 5 → 2 → 4 → 3
*/

class Solution {
    Node* getMiddleNode(Node* head) {
        Node* slow = head;
        Node* fast = head;

        while (fast->next != NULL && fast->next->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow; // slow point to middle node
    }

    Node* reverseList(Node* head) {
        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;

        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev; // prev is the head of our reversed list
    }
public:
    void reorderList(Node*& head) {
        // find middle of the list
        Node* middleNode = getMiddleNode(head);

        Node* secondHead = middleNode->next; 
        middleNode->next = NULL; // break the connection b/w first & second half
        
        // reverse the second half of the list
        Node* secondHalf = reverseList(secondHead);

        // Merge two halves alternatively
        Node* first = head;
        Node* second = secondHalf;
        while (second != NULL) {
            Node* temp_1 = first->next;
            Node* temp_2 = second->next;

            first->next = second;
            second->next = temp_1;

            first = temp_1;
            second = temp_2;
        }
    }
};

// main function
int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3, 4, 5};
    
    // create a linked list
    List ll;
    Node* head = ll.createLink_ListfromArray(nums);

    // print before running function
    ll.printLinkedList();

    sol.reorderList(head);

    for (Node* temp = head; temp != NULL; temp = temp->next) {
        cout << temp->data << " -> ";
    }
    cout << "NULL";
    return 0;
}