//11. Container With Most Water
//Given n non-negative integers a1, a2, ..., an, where each represents a point at coordinate (i, ai).
// n vertical lines are drawn such that the two endpoints of line i is at (i, ai) and (i, 0). Find two lines,
//which together with x-axis forms a container, such that the container contains the most water.
//
//Note: You may not slant the container and n is at least 2.

#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    int maxArea(vector<int>& height) {
        int length = height.size();
        int left = 0;
        int right = length - 1;
        int maxArea = min(height[left], height[right]) * (right - left);
        while (left < right) {
            if (height[left] < height[right])
                left++;
            else if (height[left] > height[right])
                right--;
            else if (height[left] == height[right]) {
                left++;
                right--;
            }
            int curArea =  min(height[left], height[right]) * (right - left);
            maxArea = max(curArea, maxArea);
        }
        return maxArea;
    }
};

int main() {
    vector<int> a = {2,4,3};
    Solution ss;
    int res = ss.maxArea(a);
    cout << res << endl;
    return 0;
}