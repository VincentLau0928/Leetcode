//105. Construct Binary Tree from Preorder and Inorder Traversal
//Given preorder and inorder traversal of a tree, construct the binary tree.

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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if (preorder.size() != inorder.size()) return NULL;
        int n = preorder.size();
        return buildBT(preorder, inorder, 0, n - 1, 0, n - 1);
    }

    TreeNode* buildBT(vector<int> &preorder, vector<int> &inorder, int s1, int e1, int s2, int e2) {
        if (s1 > e1 || s2 > e2) return NULL;
        TreeNode* p = new TreeNode(preorder[s1]);
        int pIndex = -1;
        for (int i = s2; i <= e2; ++i) {
            if (inorder[i] == p->val) {
                pIndex = i;
            }
        }
        if (pIndex == -1) return NULL;
        int leftTreeSize = pIndex - s2;
        int rightTreeSize = e2 - pIndex;
        p->left = buildBT(preorder, inorder, s1+1, s1+leftTreeSize, s2, pIndex-1);
        p->right = buildBT(preorder, inorder, e1-rightTreeSize +1, e1, pIndex+1, e2);
        return p;
    }
};

int main() {
}