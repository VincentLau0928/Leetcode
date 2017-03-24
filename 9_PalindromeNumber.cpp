//Determine whether an integer is a palindrome. Do this without extra space.
//
//Some hints:
//Could negative integers be palindromes? (ie, -1)
//
//If you are thinking of converting the integer to string, note the restriction of using extra space.
//
//You could also try reversing an integer. However, if you have solved the problem "Reverse Integer", you know that the reversed integer might overflow. How would you handle such case?
//
//There is a more generic way of solving this problem.


#include <iostream>

using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        //负数不是回文数
        if (x < 0)
            return false;
        //得到x的长度
        int len = 1;
        while ( x / len >= 10) {
            len *= 10;
        }
        while (x != 0) {
            //判断x的最左和最右值是否相同
            int left = x / len;
            int right = x % 10;
            if (left != right)
                return false;
            else {
                //摘掉x的最左和最右值
                x = (x % len) / 10;
                len /= 100;
            }
        }
        return true;
    }
};
int main() {
    int a = 3;
    Solution ss;
    bool re = ss.isPalindrome(a);
    cout << re;
}