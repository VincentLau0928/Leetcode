//124. Binary Tree Maximum Path Sum
//Given a binary tree, find the maximum path sum.
//
//For this problem, a path is defined as any sequence of nodes from some starting node to
//any node in the tree along the parent-child connections. The path must contain at least
//one node and does not need to go through the root.
//
//For example:
//Given the below binary tree,
//
//       1
//      / \
//     2   3
//Return 6.
#include <iostream>
#include "toolkit.h"
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int maxPath = INT_MIN;
        int ps1_root = findMaxPathSum(root, maxPath);
        return maxPath;
    }

    int findMaxPathSum(TreeNode* root, int& maxSum) {
        if (!root) return 0;
        int ps1_left = 0, ps1_right = 0;
        if (root->left) {
            ps1_left = max(findMaxPathSum(root->left, maxSum), 0);
        }
        if (root->right) {
            ps1_right = max(findMaxPathSum(root->right, maxSum), 0);
        }

        int ps1_root = max(ps1_left, ps1_right) + root->val;
        int ps2_root = ps1_left + ps1_right + root->val;
        maxSum = max(maxSum, max(ps1_root, ps2_root));

        return ps1_root;
    }
};

int main() {
    string s = "1(2,3)";
    TreeNode* root = constructTree(s);
    Solution ss;
    int res = ss.maxPathSum(root);
    destoryTree(root);
    std::cout << res;
}