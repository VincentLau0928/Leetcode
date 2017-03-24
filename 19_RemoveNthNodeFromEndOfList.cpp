//19. Remove Nth Node From End of List
//Given a linked list, remove the nth node from the end of list and return its head.
//
//For example,
//
//        Given linked list: 1->2->3->4->5, and n = 2.
//
//After removing the second node from the end, the linked list becomes 1->2->3->5.
//Note:
//        Given n will always be valid.
//Try to do this in one pass.
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
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        if (head == NULL)
            return NULL;

        ListNode *pPre = NULL;
        ListNode *p = head;
        ListNode *q = head;
        for(int i = 0; i < n - 1; i++)
            q = q->next;

        while(q->next)
        {
            pPre = p;
            p = p->next;
            q = q->next;
        }

        if (pPre == NULL)
        {
            head = p->next;
            delete p;
        }
        else
        {
            pPre->next = p->next;
            delete p;
        }

        return head;
    }
};

int main() {
    ListNode* a = new ListNode(1);
    ListNode* b = new ListNode(2);
    ListNode* c = new ListNode(3);
    ListNode* d = new ListNode(4);
    ListNode* e = new ListNode(5);
    ListNode* head = a;
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;

    Solution ss;
    ListNode* res = ss.removeNthFromEnd(head, 1);
    while (res != NULL) {
        cout << res->val << "->";
        res = res->next;
    }
}