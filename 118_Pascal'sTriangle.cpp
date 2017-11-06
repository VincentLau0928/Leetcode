//118. Pascal's Triangle
//Given numRows, generate the first numRows of Pascal's triangle.
//
//For example, given numRows = 5,
//Return
//
//[
//[1],
//[1,1],
//[1,2,1],
//[1,3,3,1],
//[1,4,6,4,1]
//]
#include <iostream>
#include "toolkit.h"

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> pascal;
        if (numRows == 0)
            return pascal;
        vector<int> row(1,1);
        pascal.push_back(row);
        for (int i = 1; i < numRows; ++i) {
            vector<int>& lastRow = pascal.back();
            vector<int> newRow(lastRow.size() + 1, 1);
            for (int j = 1; j < newRow.size() - 1; ++j) {
                newRow[j] = lastRow[j-1] + lastRow[j];
            }
            pascal.push_back(newRow);
        }
        return pascal;
    }
};

int main() {
    Solution ss;
    vector<vector<int>> res = ss.generate(5);
    for (int i = 0; i < res.size(); ++i) {
        printVector(res[i]);
    }
}