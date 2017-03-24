//17. Letter Combinations of a Phone Number
//Given a digit string, return all possible letter combinations that the number could represent.

//A mapping of digit to letters (just like on the telephone buttons)
//Input:Digit string "23"
//Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    void findLettComb(string &digits, int index, string dict[], string &comb, vector<string> &lettComb) {
        if (index == digits.length()) {
            lettComb.push_back(comb);
            return;
        }
        string dic = dict[digits[index] - '0'];
        for (int i = 0; i < dic.length(); ++i) {
            comb[index] = dic[i];
            findLettComb(digits, index + 1, dict, comb, lettComb);
        }
    }
    vector<string> letterCombinations(string digits) {
        vector<string> lettComb;
        string dict[] = {" ", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        if (digits.size() == 0)
            return lettComb;
        string comb(digits.size(), '\0');
        findLettComb(digits, 0, dict, comb, lettComb);
        return lettComb;
    }
};

int main() {
    string digits = "";
    Solution ss;
    vector<string> res = ss.letterCombinations(digits);
    for (int i = 0; i < res.size(); ++i) {
        cout << res[i] << " ";
    }
}