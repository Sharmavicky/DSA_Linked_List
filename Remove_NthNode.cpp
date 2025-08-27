#include <iostream>
#include "List.h"
#include <vector>
using namespace std;

/*
    * Problem: Remove Nth Node
        In this problem we have to remove nth node from the back of linked list.

    * Time Complexity: O(n)
    * Space Complexity: O(1);
*/

class Solution {
    public:
    int removeNthNode(Node* Head, int n) {
        int length = 0;
        Node* temp = Head;

        while (temp != NULL) {
            temp = temp->next;
            length++;
        }

        // if n == length than delete head node
        if (n == length) {
            Node* toDelete = Head;
            Head = Head->next;
            
            delete toDelete;
            return Head->data;
        }

        temp = Head;

        for(int i=0; i<length-n-1; i++) {
            temp = temp->next;
        }

        Node* toDelete = temp->next;
        temp->next = temp->next->next;

        delete toDelete;

        return Head->data;
    }
};

// main function
int main() {
    List ll;
    vector<int> ar = {1, 2, 3, 4, 5};

    // make a linked list
    for (int i=0; i<ar.size(); i++) {
        ll.pushFront(ar[i]);
    }

    Node* head = ll.getHead();
    int n=2;

    // remove node
    int result = Solution().removeNthNode(head, n);

    cout << result;
    return 0;
}