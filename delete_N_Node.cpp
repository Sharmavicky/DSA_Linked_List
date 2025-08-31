#include <iostream>
#include <vector>
#include "List.h"
using namespace std;

/*
    * Problem: Delete a Node in a Linked List (LeetCode 237)

    * Given only access to a node in a singly linked list (not the head), delete that node from the list.
    * You cannot access the previous node; you must modify the given node and its next pointer.

    * Approach:
    - Copy the data from the next node into the current node.
    - Delete the next node by updating the current node's next pointer.
    - This effectively removes the given node from the list.

    Example:
        Input: Linked list = [4, 5, 1, 9], node to delete = 1
        Output: Linked list = [4, 5, 9]

    * Time Complexity: O(n) — n is the number of iteration to remove last node after copying elements.
    * Space Complexity: O(1) — No extra space is used.

    Note:
    - The main function demonstrates building a linked list, printing it, deleting a node, and printing the result.
*/

class Solution {
    public:
    void delete_Nth_Nodes(Node* head) {
        Node* temp = head;

        while (temp->next != NULL) {
            if (temp->next->next != NULL) {
                temp->data = temp->next->data;
            } else {
                temp->data = temp->next->data;
                temp->next = NULL;
                break;
            }
            temp = temp->next;
        }

        temp->next = NULL;
    }
};

// main function
int main() {
    vector<int> ar = {4, 5, 1, 9};
    List ll;

    for (int n: ar) {
        ll.pushBack(n);
    }

    // linked list before removing nth node
    ll.printLinkedList();
    cout << "\n";

    // linked list after removing nth node
    Node* head = ll.getHead();
    Node* temp = head;

    while (temp->data != 1) {
        temp = temp->next;
    }

    Solution().delete_Nth_Nodes(temp);
    ll.printLinkedList();

    return 0;
}