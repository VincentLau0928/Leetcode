//Given a string s, find the longest palindromic substring in s. You may assume that the maximum length of s is 1000.
//
//Example:
//
//        Input: "babad"
//
//Output: "bab"
//
//Note: "aba" is also a valid answer.
//Example:
//
//        Input: "cbbd"
//
//Output: "bb"

#include <iostream>
using namespace std;

class Solution {
public:
    string addSpecialChar(char c, string s) {
        int len = s.length();
        int reslen = 2 * len;
        char tempc[reslen + 1];
        for (int i = 0; i < reslen + 1; ++i) {
            if (!(i & 1)) {
                tempc[i] = c;
            } else {
                tempc[i] = s[i/2];
            }
        }
        string res = tempc;
        return res;
    }

    string deleteSpecialChar(char c, string s) {
        for (int i = 0; i < s.length(); ++i) {
            if (s[i] == c) {
                s.erase(s.begin() + i);
            }
        }
        return s;
    }
    string longestPalindrome(string s) {
        string s1 = addSpecialChar('#', s);
        int jj = 0;
        int ii = 0;
        int max = 0;
        for (int i = 0; i < s1.length(); ++i) {
            int len = 0;
            int j = 1;
            while (i - j >= 0  && i + j < s1.length() && s1[i - j] == s1[i + j]) {
                len++;
                j++;
            }
            if (len > max) {
                max = len;
                jj = j-1;
                ii = i;
            }
        }
        string s2(s1, ii-jj, 2*jj + 1);
        string res = deleteSpecialChar('#', s2);
        return res;
    }
};
int main() {
    string s("babad");
    Solution ss;
    string res = ss.longestPalindrome(s);
    cout << res << endl;
    return 0;
}