//44. Wildcard Matching
//Implement wildcard pattern matching with support for '?' and '*'.
//
//'?' Matches any single character.
//'*' Matches any sequence of characters (including the empty sequence).
//
//The matching should cover the entire input string (not partial).
//
//The function prototype should be:
//bool isMatch(const char *s, const char *p)
//
//Some examples:
//isMatch("aa","a") → false
//isMatch("aa","aa") → true
//isMatch("aaa","aa") → false
//isMatch("aa", "*") → true
//isMatch("aa", "a*") → true
//isMatch("ab", "?*") → true
//isMatch("aab", "c*a*b") → false

#include <iostream>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        return isMatchc(s.c_str(), p.c_str());
    }

    bool isMatchc(const char *s, const char *p) {
        bool star = false;
        const char *str, *ptr;
        for (str = s, ptr = p; *str != '\0'; str++, ptr++) {
            switch (*ptr) {
                case '?':
                    break;
                case '*':
                    star = true;
                    s = str, p = ptr;
                    while (*p == '*')
                        p++;
                    if (*p == '\0') // 如果'*'之后，pat是空的，直接返回true
                        return true;
                    str = s - 1;
                    ptr = p - 1;
                    break;
                default: {
                    if (*str != *ptr) {
                        if (!star)
                            return false;
                        s++;
                        str = s - 1;
                        ptr = p - 1;
                    }
                }
            }
        }
        while (*ptr == '*')
            ptr++;
        return (*ptr == '\0');
    }
};
int main() {
    string s = "abcdefg";
    string p = "ab*degg";
    Solution ss;
    bool res = ss.isMatch(s, p);
    cout << res;
    return 0;
}