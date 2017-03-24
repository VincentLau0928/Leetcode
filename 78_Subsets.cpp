//78. Subsets
//Given a set of distinct integers, nums, return all possible subsets.
//
//Note: The solution set must not contain duplicate subsets.
//
//For example,
//        If nums = [1,2,3], a solution is
//[
//[3],
//[1],
//[2],
//[1,2,3],
//[1,3],
//[2,3],
//[1,2],
//[]
//]

#include <iostream>
#include <vector>
#include "toolkit.h"

using namespace std;

class Solution {
public:
    void setANum(vector<vector<int>>& res, vector<int>& nums, int n) {
        if (n == 0) {
            int num = nums[0];
            vector<int> a(1, num);
            vector<int> b;
            res.push_back(a);
            res.push_back(b);
            return;
        } else {
            setANum(res, nums, n-1);
            int originSize = res.size();
            for (int i = 0; i < originSize; ++i) {
                vector<int> temp(res[i]);
                temp.push_back(nums[n]);
                res.push_back(temp);
            }
        }
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size() - 1;
        vector<vector<int>> res;
        setANum(res, nums, n);
        return res;
    }
};

int main () {
    int a[] = {1,2,3};
    vector<int> aa(a, a+3);
    Solution ss;
    vector<vector<int>> res = ss.subsets(aa);

    for (int i = 0; i < res.size(); ++i) {
        printVector(res[i]);
        cout << endl;
    }
    return 0;
}
