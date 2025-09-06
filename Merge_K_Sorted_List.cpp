#include <iostream>
#include <vector>
#include "List.h"
using namespace std;

/*
    * Solution class to merge k sorted linked lists into one sorted linked list.
    * Steps:
    * 1. Concatenate all linked lists into a single list.
    * 2. Apply merge sort on the combined list using:
        * - getMiddle() → to split the list into halves,
        * - mergeSort() → recursive divide & conquer sorting,
        * - mergeList() → to merge two sorted halves.
    * Overall Time Complexity: O(N log N), Space Complexity: O(log N) (recursion stack), else it is O(1).
    * (N = total number of nodes across all lists, k = number of lists)
*/

class Solution {
    private:
    Node* getMiddle(Node* head) {
        if (head == NULL || head->next == NULL) return head;

        Node* slow = head;
        Node* fast = head->next;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        return slow; // slow is now the node before the middle
    }

    Node* mergeList(Node* left, Node* right) {
        Node* dummy = new Node(0);
        Node* temp = dummy;

        while (left != NULL && right != NULL) {
            if (left->data <= right->data) {
                temp->next = left;
                left = left->next;
            } else {
                temp->next = right;
                right = right->next;
            }
            temp = temp->next;
        }

        // attach remaining left and right nodes
        if (left != NULL) temp->next = left;
        if (right != NULL) temp->next = right;

        Node* new_head = dummy->next; // new head of sorted list
        delete dummy; // free memory
        return new_head;
    }

    Node* mergeSort(Node* head) {
        if (head == NULL || head->next == NULL) return head;

        Node* mid = getMiddle(head);
        Node* right_head = mid->next;
        mid->next = NULL;

        // sort both halves
        Node* left = mergeSort(head);
        Node* right = mergeSort(right_head);

        // merge both halves
        return mergeList(left, right);
    }

    public:
    Node* mergeKSortedLists(vector<Node*>& lists) {
        Node* dummy = new Node(0);
        Node* temp = dummy;
        int k = lists.size();

        // make a single linked lists
        for (int i = 0; i < k; i++) {
            Node* head = lists[i];
            if (head == NULL) continue; // if a linked list is empty than continue.

            temp->next = head;
            while (head->next != NULL) {
                head = head->next;
            }
            temp = head;
        }

        Node* newHead = dummy->next; // new head of our single linked list
        delete dummy;
        Node* res_head = mergeSort(newHead); // perform mergesort on linked lists for sorting
        return res_head;
    }
};

/* ============================== Helper Function ============================*/
// Function to create linked list from a vector of integers
Node* createLinkedList(const vector<int>& values) {
    if (values.empty()) return NULL;

    Node* head = new Node(values[0]);
    Node* current = head;

    for (int i = 1; i < values.size(); i++) {
        current->next = new Node(values[i]);
        current = current->next;
    }
    return head;
}

// Function to print a linked list
void printLinkedList(Node* head) {
    Node* temp = head;
    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL";
}

/* =============================== Main Function ============================*/
int main() {
    vector<vector<int>> lists = {
        {1, 3, 5, 7},
        {2, 4, 6, 8},
        {1, 2, 3},
    };

    int length = lists.size();
    vector<Node*> nested_lists; // nested linked list
    // create a nested linked list
    for (int i=0; i < length; i++) {
        nested_lists.push_back(createLinkedList(lists[i]));
    }

     // Print each linked list
    for (int i = 0; i < nested_lists.size(); i++) {
        cout << "Linked List " << i + 1 << ": ";
        printLinkedList(nested_lists[i]);
    }

    Node* res_head = Solution().mergeKSortedLists(nested_lists);
    printLinkedList(res_head);

    return 0;
};