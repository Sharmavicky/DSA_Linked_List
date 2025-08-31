#include <iostream>
#include <vector>
#include "List.h"
using namespace std;

/*
    * BruteForce Approach:
    - Create a completely new linked list while skipping nodes with value = val.
    - For each node in the original list:
        - If its data != val, create a new node and attach it to the new list.
        - Otherwise, skip it.
    - Finally, return the head of the newly created list.

    * Time Complexity: O(n)   // traverse the list once
    * Space Complexity: O(n)  // new list is created with up to n nodes

    * Optimal Approach:
    - Instead of creating a new list, modify the existing one in-place.
    - First, skip all leading nodes that have data == val.
    - Then, iterate through the remaining list:
        - If current node != val, connect it to the result list.
        - Otherwise, skip it.
    - Ensure the final node points to NULL to avoid dangling links.
    - Return the filtered list starting from dummy->next.

    * Time Complexity: O(n)   // traverse the list once
    * Space Complexity: O(1)  // no new nodes created, only pointers used
*/

class Solution {
    public:
    Node* BruteForce(Node* head, int val) {
        if (head == NULL) return head;

        Node* dummyNode = new Node(0);
        Node* dummyTemp = dummyNode;


        while (head != NULL) {
            if (head->data != val) {
                dummyTemp->next = new Node(head->data);
                dummyTemp = dummyTemp->next;
            }

            // move ahead in the original list
            head = head->next;
        }

        return dummyNode->next;
    }

    Node* OptimalApproach(Node* head,  int val) {
        if (head == NULL) return head;

        // skip all nodes which have value equal to val
        while (head != NULL && head->data == val) {
            head = head->next;
        }

        Node* dummyNode = new Node(0);
        Node* prev = dummyNode;

        while (head != NULL) {
            if (head->data != val) {
                prev->next = head;
                prev = head;
            }
            head = head->next;
        }

        // set the next of last node to NULL
        prev->next = NULL;

        // return the next of dummyNode
        return dummyNode->next;
    }
};

// main functin
int main() {
    vector<int> values = {1, 2, 6, 3, 4, 5, 6};
    int val = 6;

    // created a linked-list
    List ll;
    for (int n: values) {
        ll.pushBack(n);
    }

    // get the head of linked-list
    Node* head = ll.getHead();
    Node* newHead = Solution().OptimalApproach(head, val);

    // print the modified linked-list
    for (Node* temp = newHead; temp != NULL; temp = temp->next) {
        cout << temp->data << "->";
    }
    cout << "NULL" << endl;

    return 0;
}