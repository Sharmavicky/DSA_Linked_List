#include <iostream>
#include <vector>
#include "List.h"
using namespace std;

/*
    BruteForce:
        time complexity: O(n), n is the length of linkedlist
        space complexity: O(1).
*/

// Solution
class hasCycle {
    public:
    bool BruteForce(Node* Head) {
        Node* slow = Head;
        Node* fast = Head;

        while (fast != NULL && fast->next != NULL) {
            slow = slow->next;
            fast = fast->next->next;

            // cycle detected so, return true
            if (slow == fast) return true;
        }

        // cycle not detected
        return false;
    }
};

// main functin
int main() {
    List ll;
    vector<int> ar = {1, 2, 3, 4, 5};

    for(int i=0; i<ar.size(); i++) {
        ll.pushBack(ar[i]);
    }
    
    Node* head = ll.getHead();
    Node* tail = ll.getTail();
    Node* temp = head;

    for(int i=0; i<3; i++) {
        temp = temp->next;
    }

    tail->next = temp;

    // now our cyclic linkedlist is ready

    bool result = hasCycle().BruteForce(head);

    cout << result << endl;

    return 0;
}