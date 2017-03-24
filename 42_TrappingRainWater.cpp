//42. Trapping Rain Water
//Given n non-negative integers representing an elevation map where the width of each bar is 1,
// compute how much water it is able to trap after raining.
//
//For example,
//        Given [0,1,0,2,1,0,1,3,2,1,2,1], return 6.

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int length = height.size();
        if (length < 3)
            return 0;
        vector<int> left(length, 0);
        vector<int> right(length, 0);
        int water = 0;
        for (int i = 1; i < length; ++i)
            left[i] = max(left[i-1], height[i - 1]);

        for (int j = length - 2; j >= 0; --j) {
            right[j] = std::max(right[j + 1], height[j + 1]);
            int min = std::min(left[j], right[j]);
            if (min > height[j])
                water += min - height[j];
        }
        return water;
    }
};


int main() {
    int a[] = {0,1,0,2,1,0,1,3,2,1,2,1};
    vector<int> aa(a, a + sizeof(a) / sizeof(int));
    Solution ss;
    int res = ss.trap(aa);
    cout << res;
    return 0;
}