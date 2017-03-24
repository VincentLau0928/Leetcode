//53. Maximum Subarray
//Find the contiguous subarray within an array (containing at least one number) which has the largest sum.
//
//For example, given the array [-2,1,-3,4,-1,2,1,-5,4],
//the contiguous subarray [4,-1,2,1] has the largest sum = 6.

//典型的DP题：
//1. 状态dp[i]：以A[i]为最后一个数的所有max subarray的和。
//2. 通项公式：dp[i] = dp[i-1]<=0 ? A[i] : dp[i-1]+A[i]
//3. 由于dp[i]仅取决于dp[i-1]，所以可以仅用一个变量来保存前一个状态，而节省内存。

#include <iostream>
#include <vector>
#include "toolkit.h"

using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if(n<=0) return 0;
        int maxSum = nums[0], curSum = nums[0];
        for(int i=1; i<n; i++) {
            curSum =  curSum <= 0 ? nums[i] : nums[i]+curSum;
            maxSum = max(maxSum,curSum);
        }
        return maxSum;
    }
};

int main() {
    int a[]  = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
    vector<int> aa(a, a+9);
    Solution ss;
    int res = ss.maxSubArray(aa);
    cout << res;
}