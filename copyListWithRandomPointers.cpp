#include <iostream>
#include <vector>
#include "List.h"
#include <unordered_map>
using namespace std;

/*
    * Function: copyRandomList
    * ------------------------
    * Creates a deep copy of a linked list where each node has two pointers:
    *  1. next   → points to the next node in the list
    *  2. random → points to any random node in the list (or NULL)
    
    * Approach:
    *  - First pass: Create new nodes with the same data and build the `next` chain.
    *    Store mapping (originalNode → copiedNode) in an unordered_map.
    *  - Second pass: Use the mapping to correctly assign `random` pointers for the new list.
    *  - Return the head of the new list.
    
    * Time Complexity: O(n), since we traverse the list twice (n = number of nodes).
    * Space Complexity: O(n), because we store a mapping from original to copied nodes.
*/


class Solution {
    public:
    Node* BruteForce(Node* head) {
        Node* temp = head;
        Node* copyLst = new Node(0); // dummy head;
        Node* currNode = copyLst;
        unordered_map<Node*, Node*> randomPtr = {};

        // First Pass: copy data and next pointers
        while (temp != NULL) {
            currNode->next = new Node(temp->data);
            currNode = currNode->next;

            randomPtr[temp] = currNode;
            temp = temp->next;
        }

        // Second Pass: copy random pointers
        temp = head;
        currNode = copyLst->next;

        while (temp != NULL) {
            currNode->random = randomPtr[temp->random];
            temp = temp->next;
            currNode = currNode->next;
        }

        // return deep copy head
        return copyLst->next;
    }
};

// main function
int main() {

}