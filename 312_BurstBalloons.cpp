//312. Burst Balloons
//Given n balloons, indexed from 0 to n-1. Each balloon is painted with a number on it represented by array nums.
//You are asked to burst all the balloons. If the you burst balloon i you will get nums[left] * nums[i] * nums[right] coins.
//Here left and right are adjacent indices of i. After the burst, the left and right then becomes adjacent.
//
//Find the maximum coins you can collect by bursting the balloons wisely.
//
//Note:
//(1) You may imagine nums[-1] = nums[n] = 1. They are not real therefore you can not burst them.
//(2) 0 ≤ n ≤ 500, 0 ≤ nums[i] ≤ 100
//
//Example:
//Given [3, 1, 5, 8]
//Return 167
//
//nums = [3,1,5,8] --> [3,5,8] -->   [3,8]   -->  [8]  --> []
//coins =  3*1*5      +  3*5*8    +  1*3*8      + 1*8*1   = 167

#include <iostream>
#include "toolkit.h"

class Solution {
public:
    int divid(vector<int>& nums, vector<vector<int>>& dp, int low, int high)
    {
        if(low+1 == high) return 0;
        if(dp[low][high] > 0) return dp[low][high];
        int ans = 0;
        for(int i = low+1; i < high; i++)
            ans=max(ans, nums[low]*nums[i]*nums[high]
                         + divid(nums, dp, low, i) + divid(nums, dp, i, high));
        dp[low][high] = ans;
        return ans;
    }

    int maxCoins(vector<int>& nums) {
        nums.insert(nums.begin(), 1);
        nums.insert(nums.end(), 1);
        vector<vector<int>> dp(nums.size()+1, vector<int>(nums.size()+1, 0));
        return divid(nums, dp, 0, nums.size()-1);
    }
};

using namespace std;

int main() {
    int a[] = {7,9,8,0,7,1,3,5,5,2,3};
    vector<int> aa(a, a + sizeof(a) / sizeof(int));
    Solution ss;
    int res = ss.maxCoins(aa);
    cout << res << endl;
    return 0;
}