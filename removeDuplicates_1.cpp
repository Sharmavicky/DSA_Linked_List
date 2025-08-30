#include <iostream>
#include <vector>
#include "List.h"
using namespace std;

/*
    * Problem: Remove Duplicates from a Sorted Linked List
    * ----------------------------------------------------
    * Given the head of a sorted linked list, remove duplicate nodes so that each element appears only once. Return the modified list.
    
    * Example:
    *    Input:  1 -> 1 -> 2 -> 3 -> 3
    *    Output: 1 -> 2 -> 3
    
    * BruteForce Approach:
    *    - Create a new linked list using a dummy node.
    *    - Traverse the original list and copy nodes only when the data
    *      is different from the previously added node.
    *    - Time Complexity: O(n)
    *    - Space Complexity: O(n)   // extra nodes are created
    
    * Optimal Approach:
    *    - Use a dummy node with a sentinel value.
    *    - Traverse the list, link nodes directly when the data differs
    *      from the last added node (no need to allocate new nodes).
    *    - Time Complexity: O(n)
    *    - Space Complexity: O(1)   // no extra nodes, only pointers used
*/


class Solution {
    public:
    Node* BruteForce(Node* head) {
        int lastVisitedData = -101;
        // dummy node
        Node* dummyNode = new Node(0);

        Node* oldTemp = head;
        Node* newTemp = dummyNode;

        while (oldTemp != NULL) {
            if (oldTemp->data != lastVisitedData) {
                newTemp->next = new Node(oldTemp->data);
                newTemp = newTemp->next;
                lastVisitedData = oldTemp->data;
            }
            oldTemp = oldTemp->next;
        }

        // return newhead which is next to our dummyNode
        return dummyNode->next;
    }

    Node* OptimalApproach(Node* head) {
        Node* dummyNode = new Node(INT32_MIN);
        Node* newTemp = dummyNode;
        Node* oldTemp = head;

        while (oldTemp != NULL) {
            if (newTemp->data != oldTemp->data) {
                newTemp->next = oldTemp;
                newTemp = newTemp->next;
            }
            oldTemp = oldTemp->next;
        }

        // return next node of our dummy node as our new head
        return dummyNode->next;
    }
};

// main function
int main() {
    vector<int> ar = {1, 1, 2};

    List ll;
    for(int n: ar) {
        ll.pushBack(n);
    };

    cout << "list before removing duplicates: \n";
    ll.printLinkedList();
    cout << "\n";

    cout << "list after removing duplicates: \n";
    Node* head = ll.getHead();
    Node* result = Solution().OptimalApproach(head);

    Node* temp = result;
    while (temp != NULL) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;

    return 0;
}