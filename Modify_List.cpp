#include <bits/stdc++.h>
#include "List.h"
using namespace std;

/*
    Class Name: Solution

    Description:
    This class provides two methods to remove nodes from a linked list 
    whose values are present in a given array of integers.

    Approaches Implemented:
    1️⃣ BruteForce():
        - Marks all nodes to be deleted by setting their values to -1.
        - Then iteratively removes nodes with data = -1.
        - Time Complexity: O(N * M), where N = size of list, M = size of nums.
        - Space Complexity: O(1)

    2️⃣ OptimalApproach():
        - Uses an unordered_set for O(1) lookups of nodes to delete.
        - Efficiently removes nodes while maintaining list integrity.
        - Time Complexity: O(N + M)
        - Space Complexity: O(M)

    Both methods ensure the final linked list is properly terminated 
    and dynamically allocated nodes are safely deleted to prevent memory leaks.
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

        // remove all node with data -1 before finding first positive node
        while (head && head->data == -1) head = head->next;

        Node* prev = head;
        Node* curr = head ? head->next : NULL;
        Node* toDelete = NULL;

        while (curr) {
            if (curr->data != -1) {
                prev->next = curr;
                prev = curr;
                curr = curr->next;
            } else {
                toDelete = curr;
                prev->next = curr->next;
                curr = curr->next;
                delete toDelete;
            }
        }

        prev->next = NULL; // end the list
        return head;
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