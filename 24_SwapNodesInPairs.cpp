//24. Swap Nodes in Pairs
//Given a linked list, swap every two adjacent nodes and return its head.
//
//For example,
//        Given 1->2->3->4, you should return the list as 2->1->4->3.
//
//Your algorithm should use only constant space. You may not modify the values in the list, only nodes itself can be changed.

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
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode* bonus = new ListNode(0);
        bonus->next = head;
        ListNode* p = bonus;
        ListNode* q = NULL;
        ListNode* r = NULL;
        while(p->next && p->next->next) {
            q = p->next;
            r = q->next;
            p->next = r;
            q->next = r->next;
            r->next = q;
            p = q;
        }
        ListNode * del = bonus;
        bonus = bonus->next;
        delete del;
        return bonus;
    }
};


int main() {
    ListNode* a = new ListNode(1);
    ListNode* b = new ListNode(2);
    ListNode* c = new ListNode(3);
    ListNode* d = new ListNode(4);
    a->next = b;
    b->next = c;
    c->next = d;
    Solution ss;
    ListNode* res = ss.swapPairs(a);
    while (res) {
        cout << res->val << "->";
        res = res->next;
    }
}