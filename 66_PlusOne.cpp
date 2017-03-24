//66. Plus One
//Given a non-negative integer represented as a non-empty array of digits, plus one to the integer.
//
//You may assume the integer do not contain any leading zero, except the number 0 itself.
//
//The digits are stored such that the most significant digit is at the head of the list.

#include <iostream>
#include <vector>
#include "toolkit.h"

using namespace std;

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int carry = 1;
        vector<int> res(digits.size(),0);
        for(int i=digits.size()-1; i>=0; i--) {
            carry += digits[i];
            res[i] = carry%10;
            carry /= 10;
        }
        if(carry) res.insert(res.begin(),1);
        return res;
    }
};

int main () {
    int a[] = {9,9,7};
    vector<int> aa(a, a + 3);
    Solution ss;
    vector<int> res = ss.plusOne(aa);
    printVector(res);
    return 0;
}