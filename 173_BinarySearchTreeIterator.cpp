//173. Binary Search Tree Iterator
//Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.
//Calling next() will return the next smallest number in the BST.
//Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.
#include <iostream>
#include "toolkit.h"

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        TreeNode* p = root;
        while (p != NULL) {
            treeStack.push(p);
            p = p->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !treeStack.empty();
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* cur = treeStack.top();
        treeStack.pop();
        int res = cur->val;
        if (cur->right != NULL) {
            TreeNode* p = cur->right;
            while (p != NULL) {
                treeStack.push(p);
                p = p->left;
            }
        }
        return res;
    }

private:
    std::stack<TreeNode*> treeStack;
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */

using namespace std;

int main() {
    string treeStr = "8(3(1,6(4,7)),10(,14(13,))";
    TreeNode* root = constructTree(treeStr);
    BSTIterator i = BSTIterator(root);
    while (i.hasNext()) {
        std::cout << i.next() << ",";
    }
    return 0;
}