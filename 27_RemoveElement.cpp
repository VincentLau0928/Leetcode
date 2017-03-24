//27. Remove Element
//Given an array and a value, remove all instances of that value in place and return the new length.
//
//Do not allocate extra space for another array, you must do this in place with constant memory.
//
//The order of elements can be changed. It doesn't matter what you leave beyond the new length.
//
//Example:
//        Given input array nums = [3,2,2,3], val = 3
//
//Your function should return length = 2, with the first two elements of nums being 2.

#include <iostream>
#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int end = 0;
        int length = nums.size();
        for (int i = 0; i < length; ++i) {
            if (nums[i] != val) {
                nums[end] = nums[i];
                end++;
            }
        }
        return end;
    }
};

int main() {
    int a[] = {3,2,2,3};
    vector<int> aa(a, a+4);
    Solution ss;
    int res = ss.removeElement(aa, 3);
    cout << "res: " << res << endl;
    for (int i = 0; i < res; ++i) {
        cout << aa[i] << " ";
    }
}