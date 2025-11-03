#include <bits/stdc++.h>
#include "List.h"
using namespace std;

/*
    Class Name: Solution
    --------------------
    This class provides two approaches to remove specific nodes from a singly linked list
    whose values are present in a given array of integers.

    1. BruteForce Approach:
        - For each value in the array, traverses the entire linked list and marks nodes
          with matching values.
        - Constructs a new linked list excluding the marked nodes.
        - Time Complexity: O(N * M)
        - Space Complexity: O(N)
        - Simpler but inefficient for large inputs.

    2. Optimal Approach:
        - Utilizes an unordered_set for O(1) average lookup of nodes to delete.
        - Modifies the existing linked list in place, skipping and deleting unwanted nodes.
        - Time Complexity: O(N + M)
        - Space Complexity: O(M)
        - Efficient, memory-safe, and preferred for large-scale data.

    Both methods ensure safe handling of edge cases such as:
        - Empty linked list
        - All nodes to be deleted
        - No nodes to delete
*/

class Solution {
    public:
    Node* BruteForce(vector<int>& nums, Node* head) {
        if (!head) return NULL;

        // mark all node to be deleted as -1
        for (int n: nums) {
            for (Node* temp = head; temp != NULL; temp = temp->next) {
                if (temp->data == n) temp->data = -1;
            }
        }

        // create a new linked list without -1 nodes
        Node* dummy = new Node(0);
        Node* curr = dummy;

        for (Node* temp = head; temp != NULL; temp = temp->next) {
            if (temp->data != -1) {
                curr->next = new Node(temp->data);
                curr = curr->next;
            }
        }

        Node* newHead = dummy->next;
        delete dummy; // free the dummy node
        return newHead;
    }

    Node* OptimalApproach(vector<int>& nums, Node* head) {
        if (!head) return NULL;

        unordered_set<int> toDelete(nums.begin(), nums.end());

        // remove all node with data in toDelete before finding first valid node
        while (head && toDelete.find(head->data) != toDelete.end()) head = head->next;

        Node* prev = head;
        Node* curr = head ? head->next : NULL;
        Node* delNode = NULL;

        while (curr) {
            if (toDelete.find(curr->data) == toDelete.end()) {
                prev->next = curr;
                prev = curr;
                curr = curr->next;
            } else {
                delNode = curr;
                prev->next = curr->next;
                curr = curr->next;
                delete delNode;
            }
        }

        prev->next = NULL; // end the list
        return head;
    }
};

// main function
int main() {
    Solution sol;
    List ll;
    
    vector<int> nums = {1, 3, 5};
    Node* head = ll.createLink_ListfromArray({1, 2, 3, 4, 5, 3, 1, 6});
    cout << "Original List: ";
    ll.printLinkedList();

    Node* res = sol.BruteForce(nums, head);
    cout << "Modified List: ";
    
    for (Node* temp = res; temp != NULL; temp = temp->next) {
        cout << temp->data << "->";
    }

    return 0;
}