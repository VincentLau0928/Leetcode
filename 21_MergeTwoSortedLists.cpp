//21. Merge Two Sorted Lists
//Merge two sorted linked lists and return it as a new list.
//The new list should be made by splicing together the nodes of the first two lists.
#include <iostream>

using namespace std;

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
class Solution {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        ListNode *l3 = new ListNode(-1);
        ListNode *t3 = l3;
        while(l1 && l2) {
            if(l1->val<=l2->val) {
                t3->next = l1;
                l1 = l1->next;
            }
            else {
                t3->next = l2;
                l2 = l2->next;
            }
            t3 = t3->next;
            t3->next = NULL;
        }

        t3->next = l1 ? l1 : l2;
        ListNode* temp = l3;
        l3 = l3->next;
        delete temp;
        return l3;
    }
};
int main() {
    ListNode* a1 = new ListNode(1);
    ListNode* b1 = new ListNode(2);
    ListNode* c1 = new ListNode(3);
    ListNode* a2 = new ListNode(2);
    ListNode* b2 = new ListNode(4);
    ListNode* c2 = new ListNode(6);
    ListNode* head1 = a1;
    ListNode* head2 = a2;
    a1->next = b1;
    b1->next = c1;
    a2->next = b2;
    b2->next = c2;

    Solution ss;
    ListNode* res = ss.mergeTwoLists(head1, head2);
    while (res != NULL) {
        cout << res->val << "->";
        res = res->next;
    }
}