#include <iostream>
#include <vector>
#include "List.h"
using namespace std;

/*
    * This class implements two approaches to solve the "Partition List" problem (LeetCode 86).

    * Problem: Rearrange a linked list so that all nodes with values < x come before
    * nodes with values >= x, while preserving their original relative order.

    * 1. BruteForce():
        - Creates a completely new list by copying nodes into two partitions (left: values < x, right: values >= x).
        - Finally merges them into one list.
        - Time Complexity: O(n)
        - Space Complexity: O(n) (because new nodes are created)

    * 2. OptimalApproach():
        - Reuses original nodes and rearranges pointers in-place.
        - Maintains two partitions (left and right) and merges them at the end.
        - Time Complexity: O(n)
        - Space Complexity: O(1) (no extra nodes created)

    Example:
    Input:  head = 1 -> 4 -> 3 -> 2 -> 5 -> 2,  x = 3
    Output: 1 -> 2 -> 2 -> 4 -> 3 -> 5

*/

class Solution {
    public:
    Node* BruteForce(Node* head, int val) {
        Node* left_head = new Node(0);
        Node* right_head = new Node(0);
        Node* right = right_head;
        Node* left = left_head;
        Node* temp = head;

        while (temp != NULL) {
            Node* newNode = new Node(temp->data);
            if (temp->data < val) {
                left->next = newNode;
                left = left->next;
            } else {
                right->next = newNode;
                right = right->next;
            }
            temp = temp->next;
        }

        left->next = right_head->next;
        right->next = NULL;

        Node* newHead = left_head->next;

        delete left_head;
        delete right_head;

        return newHead;
    }

    Node* OptimalApproach(Node* head, int val) {
            Node* left_head = new Node(0);   // dummy head for left list
        Node* right_head = new Node(0);  // dummy head for right list
        Node* left = left_head;
        Node* right = right_head;

        while (head != NULL) {
            Node* nextNode = head->next; // save next node
            head->next = NULL; // detach current node

            if (head->data < val) {
                left->next = head;// append to left list
                left = left->next;
            } else {
                right->next = head;// append to right list
                right = right->next;
            }

            head = nextNode; // move forward
        }

        // Merge two lists: left part + right part
        left->next = right_head->next;
        right->next = NULL;

        Node* newHead = left_head->next;

        // free dummy nodes
        delete left_head;
        delete right_head;

        return newHead;
    }
};

// main function
int main() {
    vector<int> ar = {1, 4, 3, 2, 5, 2};
    List ll;
    ll.createLink_ListfromArray(ar);

    cout << "list before partitioning: \n";
    ll.printLinkedList();

    cout << "List after partitioning: \n";
    Node* result = Solution().OptimalApproach(ll.getHead(), 3);

    for (Node* temp = result; temp != NULL; temp = temp->next) {
        cout << temp->data << " -> ";
    }
    cout << "NULL";

    return 0;
}