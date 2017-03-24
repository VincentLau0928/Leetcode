//49. Group Anagrams
//Given an array of strings, group anagrams together.
//
//For example, given: ["eat", "tea", "tan", "ate", "nat", "bat"],
//Return:
//
//[
//["ate", "eat","tea"],
//["nat","tan"],
//["bat"]
//]

#include <iostream>
#include <vector>
#include <unordered_map>
#include "toolkit.h"

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        unordered_map<string, vector<int>> strmap;
        for (int i = 0; i < strs.size(); ++i) {
            string str = strs[i];
            sort(str.begin(), str.end());
            strmap[str].push_back(i);
        }

        for(unordered_map<string,vector<int>>::iterator it=strmap.begin(); it!=strmap.end(); it++) {
                vector<string> t;
                for(int i=0; i<it->second.size(); i++) {
                    t.push_back(strs[it->second[i]]);
                }
                res.push_back(t);
        }
        return res;
    }
};

int main() {
    string a[] = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<string> strs(a, a + 6);
    vector<vector<string>> res;
    Solution ss;
    res = ss.groupAnagrams(strs);
    for (int i = 0; i < res.size(); ++i) {
        printVector(res[i]);
    }
}