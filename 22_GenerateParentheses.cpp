//22.Generate Parentheses

//Given n pairs of parentheses, write a function to generate all combinations of well-formed parentheses.
//
//For example, given n = 3, a solution set is:
//
//[
//"((()))",
//"(()())",
//"(())()",
//"()(())",
//"()()()"
//]
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void generate(int leftNum, int rightNum, string s, vector<string>& result) {
        if (leftNum == 0 && rightNum == 0) {
            result.push_back(s);
            return;
        }
        if (leftNum > 0) {
            generate(leftNum - 1, rightNum, s + "(", result);
        }
        if (rightNum > 0 && leftNum < rightNum) {
            generate(leftNum, rightNum - 1, s + ")", result);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> res;
        generate(n, n, "", res);
        return res;
    }
};

int main() {
    int x = 3;
    Solution ss;
    vector<string> res = ss.generateParenthesis(x);
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << endl;
    }
}