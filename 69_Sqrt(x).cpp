//69. Sqrt(x)
//Implement int sqrt(int x).
//
//Compute and return the square root of x.


#include <iostream>
#include <vector>
#include "toolkit.h"

using namespace std;

class Solution {
public:
    int mySqrt(int x) {
        if (x <= 1)
            return x;
        int low = 0, high = x;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (mid < x / mid) {
                low = mid + 1;
            } else if (mid > x / mid) {
                high = mid - 1;
            } else return mid;
        }
        return high;
    }
};

int main () {
    int a = 2;
    Solution ss;
    int res = ss.mySqrt(a);
    cout << res;
    return 0;
}