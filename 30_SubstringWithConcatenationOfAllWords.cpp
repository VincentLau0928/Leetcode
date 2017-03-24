//30. Substring with Concatenation of All Words
//You are given a string s, and a list of words that are all of the same length.
//Find all starting indices of substring(s) in s that is a concatenation of each word in words exactly once and without any intervening characters.
//
//For example, given:
//s: "barfoothefoobarman"
//words: ["foo", "bar"]
//
//You should return the indices: [0,9].
//(order does not matter).


#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution {
public:
    bool checkSubstring(string s, int start, unordered_map<string,int> &wordCount, int wordSize, int totalWords) {
        if (s.size() - start + 1 < wordSize * totalWords)
            return false;
        unordered_map<string, int> wordFound;
        for (int i = 0; i < totalWords; ++i) {
            string curWord = s.substr(start + i*wordSize, wordSize);
            if (!wordCount.count(curWord)) return false;
            wordFound[curWord]++;
            if (wordFound[curWord] > wordCount[curWord]) return false;
        }
        return true;
    }

    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> allPos;
        if (words.empty())
            return allPos;
        int totalWords = words.size();
        int wordSize = words[0].size();
        int totalLen = wordSize * totalWords;
        if (s.size() < totalLen)
            return allPos;
        unordered_map<string, int> wordCount;
        for (int i = 0; i < totalWords; ++i) {
            wordCount[words[i]]++;
        }
        for (int i = 0; i <= s.size() - totalLen; ++i) {
            if(checkSubstring(s, i, wordCount, wordSize, totalWords))
                allPos.push_back(i);
        }
        return allPos;
    }
};

int main() {
    string s = "barfoothefoobarman";
    vector<string> words;
    words.push_back("bar");
    words.push_back("foo");
    Solution ss;
    vector<int> res = ss.findSubstring(s, words);
    for (int i = 0; i < res.size(); ++i) {
        cout <<"res[" << i<< "]: "  << res[i] << endl;
    }
}