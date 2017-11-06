//127. Word Ladder
//Given two words (beginWord and endWord), and a dictionary's word list,
//find the length of shortest transformation sequence from beginWord to endWord, such that:
//    1.Only one letter can be changed at a time.
//    2.Each transformed word must exist in the word list. Note that beginWord is not a transformed word.
//For example,
//Given:
//beginWord = "hit"
//endWord = "cog"
//wordList = ["hot","dot","dog","lot","log","cog"]
//As one shortest transformation is "hit" -> "hot" -> "dot" -> "dog" -> "cog",
//return its length 5.
//Note:
//Return 0 if there is no such transformation sequence.
//All words have the same length.
//All words contain only lowercase alphabetic characters.
//You may assume no duplicates in the word list.
//You may assume beginWord and endWord are non-empty and are not the same.

#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>

using namespace std;

class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> dict = transferToSet(wordList);
        queue<pair<string,int>> q;
        q.push(make_pair(beginWord, 1));
        while (!q.empty()) {
            string s = q.front().first;
            int len = q.front().second;
            if (s == endWord) return len;
            q.pop();
            vector<string> neighbors = findNeighbors(s, dict);
            for(int i = 0; i < neighbors.size(); i++) {
                q.push(make_pair(neighbors[i], len + 1));
            }
        }
        return 0;
    }

    vector<string> findNeighbors(string s, unordered_set<string> &dict) {
        vector<string> ret;
        for (int i = 0; i < s.size(); ++i) {
            char c = s[i];
            for (int j = 0; j < 26; ++j) {
                if (c == 'a' + j) continue;
                s[i] = 'a' + j;
                if (dict.count(s)) {
                    ret.push_back(s);
                    dict.erase(s);
                }
            }
            s[i] = c;
        }
        return std::move(ret);
    }

    unordered_set<string> transferToSet(vector<string>& wordList) {
        unordered_set<string> ret;
        if (wordList.size() < 1)
            return std::move(ret);
        for (int i = 0; i < wordList.size(); ++i)
            ret.insert(wordList[i]);
        return std::move(ret);
    }
};

int main() {
    string beginWord = "hit";
    string endWord = "cog";
    string ww[6] = {"hot","dot","dog","lot","log","cog"};
    vector<string> s(ww, ww+6);
    Solution ss;
    int ret = ss.ladderLength(beginWord, endWord, s);
    cout << ret;
    return 0;
}