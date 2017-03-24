//41. First Missing Positive
//Given an unsorted integer array, find the first missing positive integer.
//
//For example,
//        Given [1,2,0] return 3,
//and [3,4,-1,1] return 2.
//
//Your algorithm should run in O(n) time and uses constant space.

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int i = 0, n = nums.size();
        while (i < n) {
            if (nums[i] != i + 1 && nums[i] > 0 && nums[i] <= n && nums[i] != nums[nums[i] - 1]) {
                swap(nums[i], nums[nums[i] - 1]);
            } else
                i++;
        }

        for (int i = 0; i < n; ++i) {
            if (nums[i] != i+1) return i+1;
        }
        return n + 1;
    }
};


int main() {
    int a[] = {1,2,0};
    vector<int> aa(a, a + sizeof(a) / sizeof(int));
    Solution ss;
    int res = ss.firstMissingPositive(aa);
    cout << res;
    return 0;
}