//55. Jump Game
//Given an array of non-negative integers, you are initially positioned at the first index of the array.
//
//Each element in the array represents your maximum jump length at that position.
//
//Determine if you are able to reach the last index.
//
//For example:
//A = [2,3,1,1,4], return true.
//
//A = [3,2,1,0,4], return false.

#include <iostream>
#include <vector>
#include "toolkit.h"

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size() - 1;
        int maxNum = 0;
        for (int i = 0; i < n; ++i) {
            if (maxNum < i || maxNum >= n)
                break;
            maxNum = max(maxNum, i + nums[i]);
        }
        return maxNum >= n ? true : false;
    }
};

int main() {
    int a[]  = {3,2,1,0,4};
    vector<int> aa(a, a+5);
    Solution ss;
    bool res = ss.canJump(aa);
    cout << res;
}