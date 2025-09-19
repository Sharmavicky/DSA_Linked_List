#include <iostream>
#include <vector>
#include <algorithm>
#include "List.h"
using namespace std;

/*
    * Provides two methods to sort a singly linked list:
    *
    * 1. BruteForce(Node* head):
    *    - Extracts all node values into a vector.
    *    - Sorts the vector using STL's sort function.
    *    - Builds a new sorted linked list from the sorted values.
    *    - Time: O(n log n), Space: O(n).
    *
    * 2. OptimalApproach(Node* head):
    *    - Sorts the linked list in-place using insertion sort.
    *    - Iteratively inserts each node into its correct position
    *      in a new sorted list (built with a dummy head).
    *    - Time: O(n^2) in the worst case, Space: O(1).
    *
    * These methods demonstrate two different strategies:
    * one that uses extra space for simplicity (BruteForce),
    * and one that sorts the list directly in-place (Optimal).
*/

class Solution {
    public:
    Node* BruteForce(Node* head) {
        vector<int> ar;

        // store all element of linkedlist to ar
        Node* temp = head;
        while (temp != NULL) {
            ar.push_back(temp->data);
            temp = temp->next;
        }

        // sort the array
        sort(ar.begin(), ar.end());

        // create new linked list & return it's new head
        Node* dummy = new Node(0);
        Node* curr = dummy;

        for (int i = 0; i < ar.size(); i++) {
            Node* newNode = new Node(ar[i]);
            curr->next = newNode;
            curr = curr->next;
        }

        Node* newHead = dummy->next;
        delete dummy;
        return newHead;
    }

    Node* OptimalApproach(Node* head) {
        if (head == NULL || head->next == NULL) return head;

        Node* dummy = new Node(INT32_MIN);

        while (head != NULL) {
            Node* next = head->next;
            Node* prev = dummy;

            // find the current position of the node 
            while (prev->next != NULL && prev->next->data < head->data) {
                prev = prev->next;
            }

            // insert current node into sorted list
            head->next = prev->next;
            prev->next = head;

            // move head ptr
            head = next;
        }

        Node* newHead = dummy->next;
        delete dummy; // delete dummy node to prevent memory leaks
        return newHead;
    }
};

// main function
int main() {
    vector<int> nums = {4, 3, 1, 2};
    List ll;

    Node* head = ll.createLink_ListfromArray(nums);

    cout << "list before sorting: \n";
    ll.printLinkedList();
    cout << "\n";

    Node* res = Solution().OptimalApproach(head);
    cout << "list after sorting: \n";

    for (Node* temp = res; temp != NULL; temp = temp->next) {
        cout << temp->data << " -> ";
    }
    cout << "NULL";

    return 0;
}