#include <iostream>
#include <vector>
#include "List.h"
using namespace std;

/*
    * Reverses a portion of a singly linked list between two given positions (left and right).
    * The reversal is done in-place using pointer manipulation:
    *   1. Use a dummy node to handle edge cases (like reversing from the head).
    *   2. Traverse to the node just before 'left'.
    *   3. Reverse nodes between 'left' and 'right'.
    *   4. Reconnect the reversed sublist back into the original list.
    
    * Time Complexity: O(n)  (single pass through the list)
    * Space Complexity: O(1) (no extra data structures used)
    
    * Example:
    * Input:  1 → 2 → 3 → 4 → 5, left = 2, right = 4
    * Output: 1 → 4 → 3 → 2 → 5
*/


class Solution {
    public:
    Node* ReveerseList_2(Node* head, int left, int right) {
        if (head == NULL || left == right) return head;

        Node* dummyNode = new Node(0);
        dummyNode->next = head;
        Node* prev = dummyNode;

        for (int i=1; i<left; i++) {
            prev = prev->next;
        }

        Node* curr = prev->next;
        Node* next = NULL;

        // reverse [left, right]
        Node* subTail = curr;
        Node* revPrev = NULL;

        for (int i=0; i <= right - left; i++) {
            next = curr->next;
            curr->next = revPrev;
            revPrev = curr;
            curr = next;
        }

        // reconnect
        prev->next = revPrev;
        subTail->next = curr;

        return dummyNode->next;
    }
};

// main function
int main() {
    vector<int> nums = {1, 2, 3, 4, 5};

    List ll;
    Node* head = ll.createLink_ListfromArray(nums);

    cout << "list before reversing: \n";
    ll.printLinkedList();

    cout << "list after reversing: \n";

    Node* result = Solution().ReveerseList_2(head, 2, 4);

    Node* temp = result;

    while (temp != NULL) {
        cout << temp->data << " -> ";
        temp = temp->next;
    }
    cout << "NULL";

    return 0;
}