#include <iostream>
#include <vector>
#include "List.h"
#include <algorithm>
using namespace std;

/*
    * Problem: Sort a Linked List

    * Approaches Implemented:
    1. Brute Force:
       - Copy all node values into an array
       - Sort the array
       - Rebuild a new sorted linked list
       - Time Complexity: O(n log n)
       - Space Complexity: O(n)

    2. Optimal Approach (Merge Sort on Linked List):
       - Use slow & fast pointers to find the middle
       - Recursively split the list into two halves
       - Merge two sorted halves
       - Time Complexity: O(n log n)
       - Space Complexity: O(1) [ignoring recursion stack]

    * Key Idea:
    - Brute Force is simple but requires extra space
    - Merge Sort is the standard in-place algorithm for sorting linked lists
*/


class Solution {
    private:
    // find the middle node of a linked list
    Node* getMiddle(Node* head) {
        //Edge case: 
        if (head == NULL || head->next == NULL) return head;

        Node* slow = head;
        Node* fast = head->next;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next; // increment slow by 1
            fast = fast->next->next; // increment fast by 2
        }

        return slow; // middle node
    }

    // merge two sorted linked list
    Node* merge(Node* leftNode, Node* rightNode) {
        Node* dummyNode = new Node(0);
        Node* temp = dummyNode;

        // sort the returned list
        while (leftNode != NULL && rightNode != NULL) {
            if (leftNode->data <= rightNode->data) {
                temp->next = leftNode;
                leftNode = leftNode->next;
            } else {
                temp->next = rightNode;
                rightNode = rightNode->next;
            }
            temp = temp->next;
        }

        // attach remaining nodes of both leftNode and rightNode
        if (leftNode != NULL) temp->next = leftNode;
        if (rightNode != NULL) temp->next = rightNode;

        // return the head of our sorted linked list
        return dummyNode->next;
    }

    // merge sort function
    Node* mergeSort(Node* head) {
        if (head == NULL || head->next == NULL) return head;

        // split into two halves
        Node* mid = getMiddle(head);
        Node* rightHead = mid->next;
        mid->next = NULL;

        // recursively sort both halves
        Node* leftNode = mergeSort(head);
        Node* rightNode = mergeSort(rightHead);

        // merge both halves
        return merge(leftNode, rightNode);
    }

    public:
    Node* BruteForce(Node* head) {
        vector<int> nums = {};
        
        // copy the data of linked list in nums
        Node* temp = head;
        while (temp != NULL) {
            nums.push_back(temp->data);
            temp = temp->next;
        }

        // sort the nums array
        sort(nums.begin(), nums.end());

        // make a new sorted linked list 
        Node* dummyNode = new Node(0);
        temp = dummyNode;

        for (int i=0; i<nums.size(); i++) {
            temp->next = new Node(nums[i]);
            temp = temp->next;
        }

        // return new linked list head
        return dummyNode->next;
    }

    Node* OptimalApproach(Node* head) {
        return mergeSort(head);
    }
};

// main function
int main() {
    vector<int> ar = {4, 2, 1, 3};

    List ll;
    for (int n: ar) {
        ll.pushBack(n);
    }

    Node* head = ll.getHead();

    cout << "list before sorting: \n";
    ll.printLinkedList();

    cout << "list after sorting: \n";
    Node* result = Solution().OptimalApproach(head);

    Node* temp = result;
    while (temp != NULL) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL";

    return 0;
}