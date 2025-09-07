#include <iostream>
#include <vector>
#include "List.h"
#include <map>
using namespace std;

/*
    * This class provides two approaches to remove duplicate nodes from a linked list:

    * 1. BruteForce(): Works for unsorted lists.
        - Uses a map to count frequencies of each value.
        - Constructs a new list containing only nodes that appear exactly once.
        - Time: O(n log n), Space: O(n).

    * 2. OptimalApproach(): Works for sorted lists (LeetCode 82: Remove Duplicates from Sorted List II).
        - Skips over all nodes that have duplicates, keeping only distinct values.
        - Time: O(n), Space: O(1).

    * Both methods return the head of the new list containing only unique elements.

*/

class Solution {
    public:
    Node* BruteForce(Node* head) {
        map<int, int> count = {};

        // count frequency of every value and store it in count
        while (head != NULL) { 
            count[head->data]++;
            head = head->next;
        }

        // create a new linked list
        Node* dummy = new Node(0);
        Node* temp = dummy;

        for (auto it: count) {
            if (it.second == 1) {
                Node* newNode = new Node(it.first);
                temp->next = newNode;
                temp = temp->next;
            }
        }

        Node* newHead = dummy->next;
        delete dummy;
        return newHead;
    }

    Node* OptimalApproach(Node* head) {
        Node* dummy = new Node(0);
        dummy->next = head;
        Node* prev = dummy;

        while (head != NULL) {
            bool is_duplicate = false;

            while (head->next != NULL && head->data == head->next->data) {
                is_duplicate = true; // duplicate found;

                Node* temp = head;
                head = head->next;
                delete temp;

                if (is_duplicate) { // delete last duplicate node
                    Node* temp = head;
                    head = head->next;
                    delete temp;
                    prev->next = head;
                } else {
                    prev = head;
                    head = head->next;
                }
            }
        }

        Node* newHead = dummy->next;
        delete dummy;
        return newHead;
    }
};

// main function
int main() {
    vector<int> arr = {1, 2, 3, 3, 4, 4, 5};
    List ll;

    Node* head = ll.createLink_ListfromArray(arr);

    cout << "list before removing duplicates: \n";
    ll.printLinkedList();
    cout << "\n";

    cout << "list after removing duplicates: \n";
    Node* result = Solution().BruteForce(head);

    for (Node* temp = result; temp != NULL; temp = temp->next) {
        cout << temp->data << " -> ";
    }
    cout << "NULL";

    return 0;
}