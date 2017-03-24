/*There are two sorted arrays nums1 and nums2 of size m and n respectively.

Find the median of the two sorted arrays. The overall run time complexity should be O(log (m+n)).

Example 1:
nums1 = [1, 3]
nums2 = [2]

The median is 2.0
Example 2:
nums1 = [1, 2]
nums2 = [3, 4]

The median is (2 + 3)/2 = 2.5*/


#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    int findKth(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size();
        int n = nums2.size();
        //确保nums1的size()比较小
        if (m > n)
            return findKth(nums2, nums1, k);
        if (m == 0) return nums2[k - 1];
        if (n == 0) return nums1[k - 1];
        if (k == 1) return min(nums1[0], nums2[0]);
        vector<int> newNums1;
        vector<int> newNums2;
        int pa = min(k/2, m);
        int pb = k - pa;
        if (nums1[pa - 1] > nums2[pb - 1]) {
            newNums2.assign(nums2.begin() + pb, nums2.end());
            return findKth(nums1, newNums2, k - pb);
        } else if (nums1[pa - 1] < nums2[pb - 1]) {
            newNums1.assign(nums1.begin() + pa, nums1.end());
            return findKth(newNums1, nums2, k - pa);
        } else {
            return nums1[pa - 1];
        }
    }
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int sum = nums1.size() + nums2.size();
        if (sum & 1)
            return (double)findKth(nums1, nums2, sum/2 + 1);
        else
            return (double)(findKth(nums1, nums2, sum / 2) + findKth(nums1, nums2, sum/2 + 1)) / 2;
    }
};
int main() {
    int  v1[10] = {0,2,3,4};
    vector<int> a(&v1[0], &v1[4]);
    int v2[5] = {1,6,8,9};
    vector<int> b(&v2[0], &v2[4]);
    Solution ss;
//    double res = ss.findKth(a,b,10);
    double res = ss.findMedianSortedArrays(a, b);
    cout << res;
    return 0;
}