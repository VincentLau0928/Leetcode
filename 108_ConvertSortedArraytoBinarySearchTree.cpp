//108.Convert Sorted Array to Binary Search Tree
//Given an array where elements are sorted in ascending order, convert it to a height balanced BST.

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
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return singleBST(nums, 0, nums.size() - 1);
    }

    TreeNode* singleBST(vector<int>& nums, int start, int end) {
        if (start > end) return NULL;
        int mid = start + (end - start) / 2;
        TreeNode* p = new TreeNode(nums[mid]);
        p->left = singleBST(nums, start, mid - 1);
        p->right = singleBST(nums, mid + 1, end);
        return p;
    }
};

int main() {
    int a[] = {1,2,3,4,5,6};
    vector<int> aa(a, a+6);
    Solution ss;
    TreeNode* res = ss.sortedArrayToBST(aa);
    showTree(res);
    destoryTree(res);
    return 1;
}