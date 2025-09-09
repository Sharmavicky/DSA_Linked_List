#include <iostream>
#include <vector>
#include "List.h"
using namespace std;

/*
    * Problem: Given two linked lists head_1 and head_2, and two indices a and b,
    * remove nodes from index a to b in head_1 and insert the entire list head_2 in that place.
    
    * Steps:
        * 1. Traverse to node before index 'a'.
        * 2. Find node at index 'b'.
        * 3. Connect (a-1)-th node to head_2.
        * 4. Traverse to the end of head_2.
        * 5. Connect last node of head_2 to (b+1)-th node.
    
    * Time Complexity:
        * O(a + (b - a) + length of head_2) → simplifies to O(n + m) (n = length of list1, m = length of list2).

    * Space Complexity: O(1) → only uses pointers, no extra memory.
*/


class Solution {
    public:
    Node* mergeInBetween(Node* head_1, int a, int b, Node* head_2) {
        Node* temp = head_1; // temp points to head_1
        for (int i=1; i < a; i++) {
            temp = temp->next;
        } // after this loop 'temp' points to node before ath node

        Node* to_remove = temp->next; // points to ath node
        for (int i = 1; i < b - a + 1; i++) {
            to_remove = to_remove->next;
        } // after this loop 'to_remove' points to bth node

        temp->next = head_2; // joins both list;
        while (temp->next != NULL) {
            temp = temp->next;
        } // after this loop 'temp' points to last node of second list

        temp->next = to_remove->next; // attach the next node from bth node in the last of second lst

        return head_1; // return head of first list;
    }
};

// main function
int main() {
    vector<int> nums_1 = {10, 1, 13, 1, 2, 5};
    vector<int> nums_2 = {14, 15, 16};

    List ll_1;
    List ll_2;

    ll_1.createLink_ListfromArray(nums_1);
    ll_2.createLink_ListfromArray(nums_2);

    cout << "both list before removing nodes: \n";
    ll_1.printLinkedList();
    cout << "\n";
    ll_2.printLinkedList();

    cout << "\n";

    cout << "list after removing nodes: \n";
    Node* result = Solution().mergeInBetween(ll_1.getHead(), 3, 4, ll_2.getHead());

    for (Node* temp = result; temp != NULL; temp = temp->next) {
        cout << temp->data << " -> ";

    }
    cout << "NULL";

    return 0;
}