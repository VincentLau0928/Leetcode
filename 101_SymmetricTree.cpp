//101. Symmetric Tree
//Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
//
//For example, this binary tree [1,2,2,3,4,4,3] is symmetric:
//
//    1
//   / \
//  2   2
// / \ / \
//3  4 4  3
//But the following [1,2,2,null,3,null,3] is not:
//    1
//   / \
//  2   2
//   \   \
//   3    3

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

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return isSym(root, root);
    }
    bool isSym(TreeNode *lr, TreeNode *rr) {
        if (!lr && !rr) return true;
        if ((lr && !rr) || (rr && !lr)) return false;
        if (lr == rr) return isSym(lr->left, lr->right);
        if (lr->val != rr->val) return false;
        return isSym(lr->left, rr->right) && isSym(lr->right, rr->left);
    }
};

int main() {
//    TreeNode a(1);
//    TreeNode b(2);
//    TreeNode c(3);
//    b.left = &a;
//    b.right = &c;
//    Solution ss;
//    bool res = ss.isValidBST(&b);
//    std::cout << res;
//    return 0;
}