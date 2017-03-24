//70. Climbing Stairs
//You are climbing a stair case. It takes n steps to reach to the top.
//
//Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?


#include <iostream>
#include <vector>
#include "toolkit.h"

using namespace std;

class Solution {
public:
    int climbStairs(int n) {
        if (n == 0 || n == 1)
            return 1;
        int a = 1, b = 1, res = 0;
        for (int i = 2; i <= n; i++) {
            res = a + b;
            a = b;
            b = res;
        }
        return res;
    }
};
int main () {
    int n = 5;
    Solution ss;
    int res = ss.climbStairs(n);
    cout << res;
    return 0;
}