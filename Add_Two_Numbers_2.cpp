#include <iostream>
#include <vector>
#include "List.h"
using namespace std;

/*
    * Class Solution implements the Reverse-List Approach for
    * "Add Two Numbers II" (LeetCode 445 style problem).
    *
    * Steps:
    * 1. Reverse both linked lists to get least-significant digit at the head.
    * 2. Add digits one by one with carry (like normal addition).
    * 3. Build the result list by inserting at the head (restoring forward order).
    *
    * Time Complexity: O(m + n)  → traversing and reversing both lists.
    * Space Complexity: O(1)    → no extra space except output list.
*/

class Solution {
    Node* Reverse(Node* head) {
        Node* prev = NULL;
        Node* curr = head;
        Node* next = NULL;

        while (curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev; // reverse head
    }

public:
    Node* addTwoNum(Node* h1, Node* h2) {
        // reverse both linked list
        h1 = Reverse(h1);
        h2 = Reverse(h2);

        int carry = 0;
        Node* head = NULL;
        while (h1 || h2 || carry) {
            int sum = carry;

            if (h1) {
                sum += h1->data;
                h1 = h1->next;
            }

            if (h2) {
                sum += h2->data;
                h2 = h2->next;
            }

            carry = sum / 10;
            Node* newNode = new Node(sum % 10);
            newNode->next = head;
            head = newNode;
        }

        return head;
    }
};

// main function
int main() {
    vector<int> n1 = {7, 2, 4, 3};
    vector<int> n2 = {5, 6, 4};

    List ll1;
    List ll2;

    Node* h1 = ll1.createLink_ListfromArray(n1);
    Node* h2 = ll2.createLink_ListfromArray(n2);

    Node* res = Solution().addTwoNum(h1, h2);

    for (Node* temp = res; temp != NULL; temp = temp->next) {
        cout << temp->data << " -> ";
    }
    cout << "NULL";

    return 0;
}