//46. Permutations
//Given a collection of distinct numbers, return all possible permutations.
//
//For example,
//[1,2,3] have the following permutations:
//[
//[1,2,3],
//[1,3,2],
//[2,1,3],
//[2,3,1],
//[3,1,2],
//[3,2,1]
//]

#include <iostream>
#include <vector>
#include "toolkit.h"

using namespace std;

class Solution {
public:
    void findPermutations(vector<int> &num, vector<bool> &used, vector<int> &per, vector<vector<int>> &allPer) {
        if (per.size() == num.size()) {
            allPer.push_back(per);
            return;
        }

        for (int i = 0; i < num.size(); ++i) {
            if (used[i])
                continue;
            per.push_back(num[i]);
            used[i] = true;
            findPermutations(num, used, per, allPer);
            used[i] = false;
            per.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> allPer;
        if (nums.size() < 1)
            return allPer;
        vector<int> per;
        vector<bool> used(nums.size(), false);
        findPermutations(nums, used, per, allPer);
        return allPer;
    }
};

int main() {
    int a[] = {1, 2, 3};
    vector<int> aa(a, a+ sizeof(a) / sizeof(int));
    Solution ss;
    vector<vector<int>> res = ss.permute(aa);
    for (int i = 0; i < res.size(); ++i) {
        printVector(res[i]);
    }
}