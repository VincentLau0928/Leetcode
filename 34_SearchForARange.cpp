//34. Search for a Range
//Given an array of integers sorted in ascending order, find the starting and ending position of a given target value.
//
//Your algorithm's runtime complexity must be in the order of O(log n).
//
//If the target is not found in the array, return [-1, -1].
//
//For example,
//        Given [5, 7, 7, 8, 8, 10] and target value 8,
//return [3, 4].


#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> range;
        int n = nums.size();
        range.push_back(findLeftMost(nums, n, target));
        range.push_back(findRightMost(nums, n, target));
        return range;
    }

    int findLeftMost(vector<int>& nums, int n, int target) {
        int start = 0, end = n-1;
        while(start<=end) {
            int mid = start + (end-start)/2;
            if(target<nums[mid])
                end = mid-1;
            else if(target>nums[mid])
                start = mid+1;
            else
                end = mid-1;
        }
        if(start>=0 && start<n && nums[start]==target) return start;
        return -1;
    }

    int findRightMost(vector<int>& nums, int n, int target) {
        int start = 0, end = n-1;
        while(start<=end) {
            int mid = start + (end-start)/2;
            if(target<nums[mid])
                end = mid-1;
            else if(target>nums[mid])
                start = mid+1;
            else
                start = mid+1;
        }
        if(end>=0 && end<n && nums[end]==target) return end;
        return -1;
    }
};

int main() {
    int a[] = {5, 7, 7, 8, 8, 10};
    vector<int> aa(a, a + sizeof(a) / sizeof(int));
    Solution ss;
    vector<int> res = ss.searchRange(aa, 8);
    cout << res[0] << res[1];
}