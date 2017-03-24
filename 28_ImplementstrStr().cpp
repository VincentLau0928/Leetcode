//28. Implement strStr()
//Implement strStr().
//Returns the index of the first occurrence of needle in haystack, or -1 if needle is not part of haystack.


#include <iostream>

using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        int hLength = haystack.length();
        int nLength = needle.length();
        if (nLength == 0)
            return 0;
        if (hLength == 0)
            return -1;
        for(int i=0; i<=hLength-nLength; i++) {
            for(int j=0; j<=nLength; j++) {
                if(j == nLength) return i;
                char p1 = haystack[i+j];
                char p2 = needle[j];
                if(p1 != p2) break;
            }
        }
        return -1;
    }
};


int main() {
    string h = "aaa";
    string n = "a";
    Solution ss;
    int res = ss.strStr(h, n);
    cout << "res: " << res << endl;
    return 0;
}