//84. Largest Rectangle in Histogram
//Given n non-negative integers representing the histogram's bar height where the width of each bar is 1, find the area of largest rectangle in the histogram
//
//Above is a histogram where width of each bar is 1, given height = [2,1,5,6,2,3].
//The largest rectangle is shown in the shaded area, which has area = 10 unit.
//
//For example,
//        Given heights = [2,1,5,6,2,3],
//return 10.
#include <iostream>
#include <vector>
#include <stack>
#include "toolkit.h"

using namespace std;

class Solution {
public:
    int largestRectangleArea1(vector<int>& heights) {
        int stack[heights.size() + 1], width[heights.size() + 1];
        if (heights.size() == 0) return 0;
        int top = 0, area = INT_MIN;
        stack[0] = 0;
        width[0] = 0;
        int newHeight;
        for (int i = 0; i <= heights.size(); ++i) {
            if (i < heights.size()) newHeight = heights[i];
            else newHeight = -1;
            if (newHeight >= stack[top]) {
                stack[++top] = newHeight;
                width[top] = 1;
            } else {
                int minV = INT_MAX;
                int wid = 0;
                while (stack[top] > newHeight) {
                    minV = min(minV, stack[top]);
                    wid += width[top];
                    area = max(area, minV * wid);
                    top--;
                }
                stack[++top] = newHeight;
                width[top] = wid + 1;
            }
        }
        return area;
    }
    int largestRectangleArea(vector<int> &h) {
        stack<int> S;
        h.push_back(0);
        int sum = 0;
        for (int i = 0; i < h.size(); i++) {
            if (S.empty() || h[i] > h[S.top()]) S.push(i);
            else {
                int tmp = S.top();
                S.pop();
                sum = max(sum, h[tmp]*(S.empty()? i : i-S.top()-1));
                i--;
            }
        }
        return sum;
    }
};

int main () {
    int a[] = {2,1,5,6,2,3};
    vector<int> aa(a, a+6);
    Solution ss;
    int res = ss.largestRectangleArea(aa);

    cout << res;
    return 0;
}
