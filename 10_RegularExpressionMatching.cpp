//10. Regular Expression Matching
//Implement regular expression matching with support for '.' and '*'.
//
//'.' Matches any single character.
//'*' Matches zero or more of the preceding element.
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
//isMatch("aa", "a*") → true
//isMatch("aa", ".*") → true
//isMatch("ab", ".*") → true
//isMatch("aab", "c*a*b") → true

#include <iostream>

using namespace std;

class Solution {
public:
    bool isMatch(string s, string p) {
        int lenS = s.length();
        int lenP = p.length();
        if (lenP < 1)
            return lenS < 1 ? true : false;
        //采用动态规划的方式,创建一个二维数组记录之前的结果  dp[i][j]代表s[0..i-1] p[0..j-1]的匹配状态
        bool dp[lenS+1][lenP+1];
        //给二维数组赋予初始值
        for(int i = 0; i <= lenS; i++) {
            for (int j = 0; j <= lenP; ++j) {
                dp[i][j] = false;
            }
        }
        dp[0][0] = true;
        for (int i = 0; i <= lenS; ++i) {
            for (int j = 1; j <= lenP; ++j) {
                //1.p[j-1]既不是'*'也不是'.'
                if(p[j-1] != '*' && p[j-1] != '.') {
                    dp[i][j] = i > 0 && dp[i-1][j-1] && s[i-1] == p[j-1];
                }
                //2.p[j-1]是'.'
                else if (p[j-1] == '.') {
                    dp[i][j] = i > 0 && dp[i-1][j-1];
                }
                //3.p[j-1]等于'*',此时需要考虑三种情形:匹配0个元素;匹配1个元素;匹配多个元素
                else if (j > 1 && p[j-1] == '*') {
                    bool match0 = dp[i][j-2];
                    bool match1 = dp[i][j-1];
                    bool matchMulti = i > 0 && dp[i-1][j] && (s[i-1] == p[j-2] || p[j-2] == '.');
                    dp[i][j] = match0 || match1 || matchMulti;
                }
            }
        }
        return dp[lenS][lenP];
    }
};

int main() {
    string s = "aab";
    string p = "c*a*b";
    Solution ss;
    bool re = ss.isMatch(s, p);
    cout << re;
}