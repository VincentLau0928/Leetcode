//94. Binary Tree Inorder Traversal
//Given a binary tree, return the inorder traversal of its nodes' values.
//For example:
//Given binary tree [1,null,2,3],
//   1
//    \
//     2
//    /
//   3
//return [1,3,2].

#include <iostream>
#include <vector>
#include <stack>
#include "toolkit.h"

using namespace std;

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        stack<TreeNode*> treeStack;
        TreeNode* p = root;
        vector<int> res;
        while (p != NULL || !treeStack.empty()) {
            while(p != NULL) {
                treeStack.push(p);
                p = p->left;
            }
            if (!treeStack.empty()) {
                p = treeStack.top();
                res.push_back(p->val);
                treeStack.pop();
                p = p->right;
            }
        }
        return std::move(res);
    }
};

int main () {
    TreeNode c(3);
    TreeNode b(2);
    TreeNode a(1);
    b.left = &c;
    a.right = &b;
    vector<int> res;
    Solution ss;
    res = ss.inorderTraversal(&a);
    printVector(res);
}
