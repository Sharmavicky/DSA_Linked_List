#include <iostream>
#include <vector>
#include "List.h"
using namespace std;

/*
    * Time Complexity: O(n)
    * Space Complexity: O(1)
*/

class Solution {
    public:
    Node* BruteForce(Node* Head) {
        Node* slow = Head;
        Node* fast = Head;
        bool isCycle = false;

        // detect a cycle
        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            // if cycle is detected than return true and break the loop
            if (slow == fast) {
                isCycle = true;
                break;
            }
        }

        if (!isCycle) return NULL;

        // if cycle is not detected than return pointer where slow and fast pointer meet
        slow = Head;

        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }

        return slow;
    }
};

// main function
int main() {
    vector<int> ar = {1, 2, 3, 4, 5};

    List ll;

    for (int i=0; i<ar.size(); i++) {
        ll.pushFront(ar[i]);
    }

    Node* head = ll.getHead();

    Node* result = Solution().BruteForce(head);

    cout << result->data;

    return 0;
}