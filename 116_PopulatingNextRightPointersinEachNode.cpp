//116. Populating Next Right Pointers in Each Node
//Given a binary tree

//struct TreeLinkNode {
//    TreeLinkNode *left;
//    TreeLinkNode *right;
//    TreeLinkNode *next;
//}
//Populate each next pointer to point to its next right node. If there is no next right node, the next pointer should be set to NULL.
//
//Initially, all next pointers are set to NULL.
//Note:
//You may only use constant extra space.
//You may assume that it is a perfect binary tree (ie, all leaves are at the same level, and every parent has two children).
//For example,
//Given the following perfect binary tree,
//        1
//       /  \
//      2    3
//     / \  / \
//    4  5  6  7
//After calling your function, the tree should look like:
//        1 -> NULL
//       /  \
//      2 -> 3 -> NULL
//     / \  / \
//    4->5->6->7 -> NULL
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

#include <iostream>
#include "toolkit.h"

class Solution {
public:
    void connect(TreeLinkNode *root) {
        TreeLinkNode *leftMost = root;

        while (leftMost) {
            root = leftMost;
            while (root && !root->left && !root->right) root = root->next;
            if (!root) return;
            leftMost = root->left ? root->left : root->right;
            TreeLinkNode *cur = leftMost;

            while (root) {
                if (cur == root->left) {
                    if (root->right) {
                        cur->next = root->right;
                        cur = cur->next;
                    }
                    root = root->next;
                } else if (cur == root->right) {
                    root = root->next;
                } else { // cur is the child of the previous node of root
                    if (!root->left & !root->right) {
                        root = root->next;
                        continue;
                    }
                    cur->next = root->left ? root->left : root->right;
                    cur = cur->next;
                }
            }
        }
    }
};

//int main() {
//}