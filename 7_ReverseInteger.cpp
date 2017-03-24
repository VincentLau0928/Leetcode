//Reverse digits of an integer.
//
//Example1: x = 123, return 321
//Example2: x = -123, return -321
//
//Have you thought about this?
//Here are some good questions to ask before coding. Bonus points for you if you have already thought through this!
//
//If the integer's last digit is 0, what should the output be? ie, cases such as 10, 100.
//
//Did you notice that the reversed integer might overflow? Assume the input is a 32-bit integer, then the reverse of 1000000003 overflows. How should you handle such cases?
//
//For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.
//
//Note:
//        The input is assumed to be a 32-bit signed integer. Your function should return 0 when the reversed integer overflows.
//


#include <iostream>

using namespace std;

class Solution {
public:
    int reverse(int x) {
        long long sum = 0;
        const int max = 0x7FFFFFFF;
        const int min = 0x80000000;
        while (x != 0) {
            int reg = x % 10;
            sum = sum * 10 + reg;
            x = x / 10;
        }
        if (sum < min || sum > max) {
            return 0;
        }
        return sum;
    }
};
int main() {
    int a = -123;
    Solution ss;
    int re = ss.reverse(a);
    cout << re;
}