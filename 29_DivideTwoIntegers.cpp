//29. Divide Two Integers
//Divide two integers without using multiplication, division and mod operator.
//
//If it is overflow, return MAX_INT.


#include <iostream>

using namespace std;

class Solution {
public:
    int divide(int dividend, int divisor) {
        if(!divisor) return dividend>=0 ? INT_MAX : INT_MIN;
        if(dividend==INT_MIN && divisor==-1) return INT_MAX; //overflow problem

        bool isNeg = false;
        if((dividend<0 && divisor>0) || (dividend>0 && divisor<0)) isNeg = true;
        unsigned long long dvd = abs((long long)dividend);
        unsigned long long dvs = abs((long long)divisor);

        int i = 0;
        while(dvs<<(i+1) <= dvd) i++;

        int res = 0;
        while(dvd>=dvs) {
            if(dvd >= dvs<<i) {
                dvd -= dvs<<i;
                res += 1<<i;
            }
            i--;
        }

        return isNeg ? 0-res : res;
    }
};

int main() {
    Solution ss;
    int res = ss.divide(319,20);
    cout << "res: " << res << endl;
}