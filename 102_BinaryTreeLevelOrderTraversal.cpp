//102. Binary Tree Level Order Traversal
//Given a binary tree, return the level order traversal of its nodes' values.
//(ie, from left to right, level by level).
//
//For example:
//Given binary tree [3,9,20,null,null,15,7],
//    3
//   / \
//  9  20
//    /  \
//   15   7
//return its level order traversal as:
//[
//[3],
//[9,20],
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> levelNodeValues;
        if (!root) return levelNodeValues;
        vector<TreeNode*>* curLevel = new vector<TreeNode*>();
        vector<TreeNode*>* nextLevel =  new vector<TreeNode*>();
        curLevel->push_back(root);
        while (!curLevel->empty()) {
            vector<int> curLevelValues;
            for (int i = 0; i < curLevel->size(); ++i) {
                TreeNode* curNode = (*curLevel)[i];
                curLevelValues.push_back(curNode->val);
                if (curNode->left) nextLevel->push_back(curNode->left);
                if (curNode->right) nextLevel->push_back(curNode->right);
            }
            levelNodeValues.push_back(curLevelValues);

            vector<TreeNode*>* temp = curLevel;
            curLevel = nextLevel;
            nextLevel = temp;
            nextLevel->clear();
        }
        return levelNodeValues;
    }
};

int main() {
    std::string tree = "13(19,21(11,722))";
    TreeNode* treenode = constructTree(tree);
    Solution ss;
    vector<vector<int>> res = ss.levelOrder(treenode);
    destoryTree(treenode);
    for (int i = 0; i < res.size(); ++i) {
        printVector(res[i]);
    }
    return 0;
}