#include <iostream>
#include <vector>
#include "List.h"
using namespace std;

/*  
    * Problem: Delete the Middle Node of the Linked List and return the head;
    * Provides a method to delete the middle node of a singly linked list.

    * Approach:
    *   - Uses the slow & fast pointer technique:
    *       * Slow moves one step at a time.
    *       * Fast moves two steps at a time.
    *   - When fast reaches the end, slow points to the middle node.
    *   - Keep track of the node before slow (prev), then bypass and delete slow.
    
    * Time Complexity: O(n)
    * Space Complexity: O(1)
*/


class Solution {
    public:
    Node* deleteMiddleNode(Node* head) {
        if (head == NULL || head->next == NULL) return NULL;

        Node* slow = head;
        Node* fast = head;
        Node* prev = NULL;

        while (fast != NULL && fast->next != NULL) {
            prev = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        prev->next = slow->next;

        delete slow;

        return head;
    }
};

// main function 
int main() {
    vector<int> nums = {1, 3, 4, 7, 1, 2, 6};
    List ll;
    ll.createLink_ListfromArray(nums);
    cout << "list before delet middle node: \n";
    ll.printLinkedList();
    cout << "\n";

    Node* result = Solution().deleteMiddleNode(ll.getHead());
    cout << "list after deleting middle Node: \n";
    for (Node* temp = result; temp != NULL; temp = temp->next) {
        cout << temp->data << " -> ";
    }
    cout << "NULL";
    return 0;
}