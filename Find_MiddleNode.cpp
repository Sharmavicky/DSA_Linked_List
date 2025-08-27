#include <iostream>
#include "List.h"
#include <vector>
using namespace std;

/*
    * BruteForce:
        time complexity: O(n), where n is the length of the linked list
        space complexity: O(1)

    * BetterApproach (Floyd's Tortoise and Hare):
        time complexity: O(n)
        space complexity: O(1)

    * Both BruteForce and BetterApproach has same "Time & Space Complexity", but "BetterApproach" is slightly better because it uses only one loop to find the middleNode.
*/

class middleNode {
    public:
    Node* BruteForce(Node* Head) {
        int count = 0, middleIdx = 0;
        Node* temp = Head;

        // count number of elements
        while (temp != NULL) {
            temp = temp->next;
            count++;
        }

        // calculate middleNode and set temp back to headNode
        middleIdx = count / 2;
        temp = Head;

        // loop from Head to MiddleNode
        for (int i=0; i<middleIdx; i++) {
            temp = temp->next;
        }

        // return middle Node
        return temp;
    }

    Node* BetterApproach(Node* Head) {
        Node* slow = Head;
        Node* fast = Head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next; // slow increment by 1
            fast = fast->next->next; // fast increment by 2
        }

        // slow points to middle of the index
        return slow;
    }
};

// main function
int main() {
    List ll;
    vector<int> arr = {1, 2, 3, 4, 5};

    for(int i=0; i<arr.size(); i++) {
        ll.pushFront(arr[i]);
    }

    Node* Head = ll.getHead();

    // find middle using middleNode function and return it
    Node* result = middleNode().BruteForce(Head);

    cout << result->next->data;

    return 0;
}