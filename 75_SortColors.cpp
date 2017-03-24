//75. Sort Colors
//Given an array with n objects colored red, white or blue,
//sort them so that objects of the same color are adjacent, with the colors in the order red, white and blue.
//
//Here, we will use the integers 0, 1, and 2 to represent the color red, white, and blue respectively.
//
//Note:
//        You are not suppose to use the library's sort function for this problem.
//Follow up:
//A rather straight forward solution is a two-pass algorithm using counting sort.
//First, iterate the array counting number of 0's, 1's, and 2's, then overwrite array with total number of 0's, then 1's and followed by 2's.
//
//Could you come up with an one-pass algorithm using only constant space?


#include <iostream>
#include <vector>
#include "toolkit.h"

using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        int i = low;
        while (i <= high) {
            if(nums[i] == 0)
                swap(nums[i++], nums[low++]);
            else if (nums[i] == 1)
                i++;
            else if (nums[i] == 2)
                swap(nums[i], nums[high--]);
        }
    }
};
int main () {
    int a[] = {1,0,2,1,2,0,0};
    vector<int> aa(a, a+7);
    Solution ss;
    ss.sortColors(aa);
    printVector(aa);
    return 0;
}
