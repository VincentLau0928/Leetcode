//50. Pow(x, n)
//Implement pow(x, n).

#include <iostream>
#include <vector>
#include "toolkit.h"

using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        if (n >= 0) {
            return powPositive(x, n);
        } else if (n < 0 ) {
            return 1 / powPositive(x, -n);
        }
    }
    double powPositive(double x, int n) {
        if (n == 0) return 1;
        double res = powPositive(x, n / 2);
        res *= res;
        if(n%2) res *= x;
        return res;
    }
};

int main() {
    Solution ss;
    double res = ss.myPow(8.88023, 3);
    cout << res;
}