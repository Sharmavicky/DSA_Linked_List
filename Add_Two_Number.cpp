#include <iostream>
#include <vector>
#include "List.h"
using namespace std;

/*
    * BruteForce:
        time complexity: O(m+n), where m and n are the length of linked list.
        space compleixty: O(max(m, n)+1)

    * BetterApproach:
        time complexity: O(max(m, n)+1), '+1' is for carry number.
        space complexity: O(max(m, n)+1)
*/

class Solution {
    public:
    Node* BruteForce(Node* h1, Node* h2) {
        // take two temperary nodes points both h1 and h2 respectively
        Node* t1 = h1;
        Node* t2 = h2;

        // extract the numbers
        int n1 = 0, n2 = 0;

        while (t1 != NULL && t2 != NULL) {
            n1 = (n1*10) + t1->data;
            n2 = (n2*10) + t2->data;
            t1 = t1->next;
            t2 = t2->next;
        }

        // if n1 > n2
        while (t1 != NULL) {
            n1 = (n1*10) + t1->data;
            t1 = t1->next;
        }

        // if n1 < n2
        while (t2 != NULL) {
            n2 = (n2*10) + t2->data;
            t2 = t2->next;
        }

        // Reverse the numbers to get original numbers
        int rev_n1 = 0, rev_n2 = 0;
        while (n1 > 0 && n2 > 0) {
            rev_n1 = (rev_n1 * 10) + n1 % 10;
            rev_n2 = (rev_n2 * 10) + n2 % 10;
            n1 /= 10;
            n2 /= 10;
        }

        // if n1 > n2
        while (n1 > 0) {
            int digit = n1 % 10;
            n1 /= 10;
            rev_n1 = (rev_n1 * 10) + digit;
        }

        // if n2 > n1
        while (n2 > 0) {
            int digit = n2 % 10;
            n2 /= 10;
            rev_n2 = (rev_n2 * 10) + digit;
        }

        // now add both numbers to get our result
        int newNum = rev_n1 + rev_n2;

        // make a new linkedlist from the newNum
        int digit = newNum % 10;
        newNum = newNum / 10;

        Node* resultHead = new Node(digit);
        Node* temp = resultHead;

        while (newNum > 0) {
            int digit = newNum % 10;
            newNum /= 10;

            Node* nextNode = new Node(digit);
            temp->next = nextNode;
            temp = temp->next;
        }

        return resultHead;
    }

    Node* BetterApproach(Node* h1, Node* h2) {
        Node* dummy = new Node(0); // create a dummy Node
        Node* current = dummy; // keeps track where to put new node or element
        int carry = 0; // keeps track of carry number while addition

        while (h1 != NULL || h2 != NULL || carry) {
            int total = carry;

            if (h1 != NULL) {
                total += h1->data;
                h1 = h1->next;
            }

            if (h2 != NULL) {
                total += h2->data;
                h2 = h2->next;
            }

            int num = total % 10;
            carry = total / 10;
            current->next = new Node(num);
            current = current->next;
        }

        return dummy->next;
    }
};

// main function
int main() {
    vector<int> a1 = {2, 4, 3};
    vector<int> a2 = {5, 6, 4};

    List ll1, ll2;

    for (int i=0; i<a1.size(); i++) {
        ll1.pushBack(a1[i]);
    }

    for (int i=0; i<a2.size(); i++) {
        ll2.pushBack(a2[i]);
    }

    Node* h1 = ll1.getHead();
    Node* h2 = ll2.getHead();

    Node* result = Solution().BetterApproach(h1, h2);

    Node* temp = result;

    while (temp != NULL) {
        cout << temp->data << "->";
        temp = temp->next;
    }
    cout << "NULL" << endl;

    return 0;
}