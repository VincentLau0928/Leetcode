//25. Reverse Nodes in k-Group
//Given a linked list, reverse the nodes of a linked list k at a time and return its modified list.
//
//k is a positive integer and is less than or equal to the length of the linked list.
//If the number of nodes is not a multiple of k then left-out nodes in the end should remain as it is.
//
//You may not alter the values in the nodes, only nodes itself may be changed.
//
//Only constant memory is allowed.
//
//For example,
//Given this linked list: 1->2->3->4->5
//
//For k = 2, you should return: 2->1->4->3->5
//
//For k = 3, you should return: 3->2->1->4->5


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
    ListNode *reverseKGroup(ListNode *head, int k) {
        if (!head || !head->next) return head;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* p = dummy;
        while (p->next && p->next->next) {
            ListNode* prev = p->next;
            ListNode* cur = p->next->next;
            int i = 0;
            while (cur && i < k - 1) {
                ListNode* temp = cur->next;
                cur->next = prev;
                prev = cur;
                cur = temp;
                i++;
            }
            if (i == k - 1) {
                ListNode* temp = p->next;
                p->next->next = cur;
                p->next = prev;
                p = temp;
            } else {
                cur = prev->next;
                prev->next = NULL;
                while(cur != p->next) {
                    ListNode *temp = cur->next;
                    cur->next = prev;
                    prev = cur;
                    cur = temp;
                }
                break;
            }
        }
        ListNode* temp = dummy;
        dummy = dummy->next;
        delete temp;
        return dummy;
    }
};

int main() {
    ListNode* a = new ListNode(1);
    ListNode* b = new ListNode(2);
    ListNode* c = new ListNode(3);
    ListNode* d = new ListNode(4);
    ListNode* e = new ListNode(5);
    a->next = b;
    b->next = c;
    c->next = d;
    d->next = e;
    Solution ss;
    ListNode* res = ss.reverseKGroup(a, 3);

    while (res) {
        cout << res->val << "->";
        res = res->next;
    }
}