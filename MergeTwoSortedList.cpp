#include <iostream>
#include <vector>
#include "List.h"
using namespace std;

/*
    BruteForce_iterative:
        time complexity: O(n+m), n and m are the length of our linked lists.
        space complexity: O(1)

    Optimal_recursive:
        time complexity: O(n+m)
        space complexity: O(1)
*/

class Solution {
    public:
    Node* BruteForce_iterative(Node* h1, Node* h2) {
        Node* t1 = h1;
        Node* t2 = h2;
        Node* newHead = NULL;

        if (h1 == NULL) return h2;
        if (h2 == NULL) return h1;

        // if both linkedlist are empty than return NULL
        if (h1 == NULL && h2 == NULL) return NULL;

        // if h1 < h2 than our newHead is h1 else h2;
        if (h1->data <= h2->data) {
            newHead = h1;
            t1 = t1->next;
        } else {
            newHead = h2;
            t2 = t2->next;
        }

        // k is temperary Node first points to our newHead than, track where to put next element
        Node* k = newHead;

        // loop until both t1 and t2 is not NULL and compare which should be our next element
        while (t1 != NULL && t2 != NULL) {
            if (t1->data <= t2->data) {
                k->next = t1;
                t1 = t1->next;
            } else {
                k->next = t2;
                t2 = t2->next;
            }
            k = k->next;
        }

        // if t1 has extra elements than directly add it to our newlinkedlist
        while (t1 != NULL) {
            k->next = t1;
            t1 = t1->next;
            k = k->next;
        }

        // if t2 has extra elements than directly add it to our newlinkelist
        while(t2 != NULL) {
            k->next = t2;
            t2 = t2->next;
            k = k->next;
        }

        // return our newlinkedlist head
        return newHead;
    }

    Node* Optimal_recursive(Node* h1, Node* h2) {
        if (h1 == NULL || h2 == NULL) return h1 == NULL ? h2 : h1;

        if (h1->data <= h2->data) {
            h1->next = Optimal_recursive(h1->next, h2);
            return h1;
        } else {
            h2->next = Optimal_recursive(h1, h2->next);
            return h2;
        }
    }
};

// main function 
int main() {
    vector<int> a1 = {1, 2, 4};
    vector<int> a2 = {1, 3, 4};

    List ll1, ll2;

    for(int i=0; i<a1.size(); i++) {
        ll1.pushBack(a1[i]);
    }

    for(int i=0; i<a2.size(); i++) {
        ll2.pushBack(a2[i]);
    }

    Node* h1 = ll1.getHead();
    Node* h2 = ll2.getHead();

    Node* result = Solution().BruteForce_iterative(h1, h2);

    Node* temp = result;

    while (temp != NULL) {
        cout << temp->data << "->";
        temp = temp->next;
    }

    cout << endl;

    return 0;
}