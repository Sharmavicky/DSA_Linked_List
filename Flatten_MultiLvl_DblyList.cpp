#include <iostream>
#include <vector>
#include "DoublyList.h"
using namespace std;

/*
    * Provides a method to flatten a multilevel doubly linked list.
    * In this list, each node has 'next', 'prev', and an optional 'child' pointer
    * that may point to another doubly linked list. The flattening process converts
    * the structure into a single-level doubly linked list by:
    *
    * 1. Recursively flattening any child lists.
    * 2. Inserting the flattened child list between the current node and its next node.
    * 3. Maintaining correct 'prev' and 'next' links throughout.
    * 4. Setting all 'child' pointers to NULL after merging.
    *
    * After flattening, the result is a standard doubly linked list that can be
    * traversed linearly using 'next' pointers only.
*/

class Solution {
    public:
    Node* flattenDblyList(Node* head) {
        if (head == NULL) return head;

        Node* curr = head;
        while (curr != NULL) {
            // if child node exist
            if (curr->child != NULL) {
                // flatten the list
                Node* next = curr->next;
                curr->next = flattenDblyList(curr->child);
                curr->next->prev = curr;
                curr->child = NULL;

                // find the tail
                while (curr->next != NULL) {
                    curr = curr->next;
                }

                // attach the tail with next ptr
                if (next != NULL) {
                    curr->next = next;
                    next->prev = curr;
                }
            }

            // if child node doesn't exist than update curr to next node
            curr = curr->next;
        }

        // return head of flatten list
        return head;
    }
};