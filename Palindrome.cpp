#include <iostream>
#include <vector>
#include "List.h"
using namespace std;

/*
    * BruteForce Approach to check if a linked list is a palindrome:
    1. Traverse the linked list and store all values in a vector.
    2. Use two-pointer technique (left & right) to check if values are symmetric.
    3. If mismatch found -> return false, else return true.

    * Time Complexity: O(n)   (traverse list + check vector)
    * Space Complexity: O(n)  (extra space for vector)
    
-----------------------------------------------------------------------------------------------

    * Optimal Approach to check if a linked list is a palindrome:
    1. Use slow & fast pointers to find the middle of the list.
    2. Reverse the second half of the linked list.
    3. Compare the first half with the reversed second half.
    4. If all values match -> it's a palindrome.

    * Time Complexity: O(n)   (traverse list + reverse + compare)
    * Space Complexity: O(1)  (only pointers, no extra data structures)

*/

class Solution {
    public:
    bool BruteForce(Node* head) {
        vector<int> values;
        Node* temp = head;

        while (temp != NULL) {
            values.push_back(temp->data);
            temp = temp->next;
        }

        int left = 0 , right = values.size() -1;

        while (left <= right) {
            if (values[left] != values[right]) return false;
            left++;
            right--;
        }

        return true;
    }

    bool OptimalApproach(Node* head) {
        // Edge case: if list is empty or contain only one element
        if (head == NULL || head->next == NULL) return true;

        // find the middle node
        Node* slow = head;
        Node* fast = head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;
        }

        // now slow indicates to middle node

        // Reverse the second half of the linked list
        Node* prev = NULL;
        Node* curr = slow;
        Node* next = NULL;

        while (curr != NULL) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        // now prev is the head of the reverse second half
        Node* left = head;
        Node* right = prev;

        while (right != NULL) {
            if (left->data != right->data) return false;
            left = left->next;
            right = right->next;
        }

        return true;
    }
};

// main function
int main() {
    vector<int> ar = {1, 2, 2, 1};

    List ll;
    for (int n: ar) {
        ll.pushBack(n);
    }

    Node* head = ll.getHead();

    bool result = Solution().OptimalApproach(head);
    cout << result << "\n";

    return 0;
}