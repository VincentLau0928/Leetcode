//26. Remove Duplicates from Sorted Array
//Given a sorted array, remove the duplicates in place such that each element appear only once and return the new length.
//
//Do not allocate extra space for another array, you must do this in place with constant memory.
//
//For example,
//        Given input array nums = [1,1,2],
//
//Your function should return length = 2, with the first two elements of nums being 1 and 2 respectively.
// It doesn't matter what you leave beyond the new length.


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int originLength = nums.size();
        if (originLength < 2)
            return originLength;
        int end = 0;
        for (int i = 1; i < originLength; ++i) {
            if (nums[i] != nums[end]) {
                end++;
                nums[end] = nums[i];
            }
        }
        return end + 1;
    }
};


int main() {
    vector<int>nums;
    nums.push_back(1);
    nums.push_back(1);
    nums.push_back(2);
    Solution ss;
    int res = ss.removeDuplicates(nums);
    cout << "res: " << res << endl;
    for (int i = 0; i < res; ++i) {
        cout << nums[i] << " ";
    }
    return 0;
}