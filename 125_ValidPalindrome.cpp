//125. Valid Palindrome
//Given a string, determine if it is a palindrome,
//considering only alphanumeric characters and ignoring cases.
//
//For example,
//"A man, a plan, a canal: Panama" is a palindrome.
//"race a car" is not a palindrome.
//
//Note:
//Have you consider that the string might be empty? This is a good question to ask during an interview.
//
//For the purpose of this problem, we define empty string as valid palindrome.
#include <iostream>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        if (s.empty())
            return true;
        int left = 0, right = s.size() - 1;
        while (left <= right) {
            while (!isalnum(s[left])) left++;
            while (!isalnum(s[right])) right--;
            if (left > right)
                return true;
            if (tolower(s[left++]) != tolower(s[right--])) return false;
        }
        return true;
    }
};

int main() {
    string a = "race a car";
    Solution ss;
    bool res = ss.isPalindrome(a);
    cout << res;
    return 0;
}