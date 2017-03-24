//14. Longest Common Prefix
//Write a function to find the longest common prefix string amongst an array of strings.
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int len = strs.size();
        if (len == 0) return "";
        if (len == 1) return strs[0];
        string comPre;
        for (int i = 0; i < strs[0].size(); ++i) {
            for (int j = 1; j < len; ++j) {
                if (i > strs[j].length() || strs[0][i] != strs[j][i])
                    return comPre;
            }
            comPre.push_back(strs[0][i]);
        }
        return comPre;
    }
};

int main() {
    Solution ss;
    string a = "abcd";
    string b = "abc";
    string c = "ab";
    vector<string> aa = {a, b, c};
    string res= ss.longestCommonPrefix(aa);
    cout << res << endl;
}