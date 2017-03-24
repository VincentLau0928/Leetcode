//103. Binary Tree Zigzag Level Order Traversal
//Given a binary tree, return the zigzag level order traversal of its nodes' values.
//(ie, from left to right, then right to left for the next level and alternate between).
//
//For example:
//Given binary tree [3,9,20,null,null,15,7],
//    3
//   / \
//  9  20
//    /  \
//   15   7
//return its zigzag level order traversal as:
//[
//[3],
//[20,9],
//[15,7]
//]


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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> levelNodeValues;
        if(!root) return levelNodeValues;

        stack<TreeNode*> *curLevel = new stack<TreeNode*>();
        stack<TreeNode*> *nextLevel = new stack<TreeNode*>();
        curLevel->push(root);
        bool left2right = true;
        while(!curLevel->empty()) {
            vector<int> curLevelValues;
            while(!curLevel->empty()) {
                TreeNode *cur = curLevel->top();
                curLevel->pop();
                curLevelValues.push_back(cur->val);
                if (left2right) {
                    if (cur->left) nextLevel->push(cur->left);
                    if (cur->right) nextLevel->push(cur->right);
                } else {
                    if (cur->right) nextLevel->push(cur->right);
                    if (cur->left) nextLevel->push(cur->left);
                }
            }
            levelNodeValues.push_back(curLevelValues);
            // swap curLevel and nextLevel, no need to clear since curLevel is already empty
            stack<TreeNode*> *temp = curLevel;
            curLevel = nextLevel;
            nextLevel = temp;

            left2right  = !left2right;
        }

        return levelNodeValues;
    }
};

int main() {
    std::string tree = "3(9,20(15,7))";
    TreeNode* treenode = constructTree(tree);
    Solution ss;
    vector<vector<int>> res = ss.zigzagLevelOrder(treenode);
    destoryTree(treenode);
    for (int i = 0; i < res.size(); ++i) {
        printVector(res[i]);
    }
    return 0;
}