//23. Merge k Sorted Lists

//Merge k sorted linked lists and return it as one sorted list. Analyze and describe its complexity.

#include <iostream>
#include <vector>
#include <queue>
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
    struct compNode {
        bool operator () (ListNode* p, ListNode* q) {
            return p->val > q->val;
        }
    };
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        //STL优先队列,原理与堆相似
        priority_queue<ListNode*, vector<ListNode*>, compNode> pq;
        //创建一个辅助起始结点
        ListNode* dummy = new ListNode(-1);
        ListNode* tail = dummy;
        for (int i = 0; i < lists.size(); ++i) {
            if(lists[i])
                pq.push(lists[i]);
        }

        while(!pq.empty()) {
            tail->next = pq.top();
            tail = tail->next;
            pq.pop();
            if (tail->next) pq.push(tail->next);
        }
        //把创建的辅助起始结点删掉
        tail = dummy->next;
        delete dummy;
        return tail;
    }
};
