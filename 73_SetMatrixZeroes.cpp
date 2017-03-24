//73. Set Matrix Zeroes
//Given a m x n matrix, if an element is 0, set its entire row and column to 0. Do it in place.
//
//Follow up:
//Did you use extra space?
//A straight forward solution using O(mn) space is probably a bad idea.
//A simple improvement uses O(m + n) space, but still not the best solution.
//Could you devise a constant space solution?


#include <iostream>
#include <vector>
#include "toolkit.h"

using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int> > &matrix) {
        if(matrix.empty() || matrix[0].empty()) return;
        int m = matrix.size(), n = matrix[0].size();

        // find if the 1st row/col needs to be set as zero
        bool isFirstRowZero = false;
        bool isFirstColZero = false;
        for(int j=0; j<n; j++) {
            if(matrix[0][j]==0) {
                isFirstRowZero = true;
                break;
            }
        }
        for(int i=0; i<m; i++) {
            if(matrix[i][0]==0) {
                isFirstColZero = true;
                break;
            }
        }

        // use 1st row/col to record whether to set each col/row as zero
        for(int i=1; i<m; i++) {
            for(int j=1; j<n; j++) {
                if(matrix[i][j]==0) {
                    matrix[i][0] = matrix[0][j] = 0;
                }
            }
        }

        // set rows & cols
        for(int i=1; i<m; i++) {
            if(matrix[i][0]==0) setRowCol(matrix, i, true);
        }
        for(int j=1; j<n; j++) {
            if(matrix[0][j]==0) setRowCol(matrix, j, false);
        }

        // set first row & col
        if(isFirstRowZero) setRowCol(matrix, 0, true);
        if(isFirstColZero) setRowCol(matrix, 0, false);
    }

    void setRowCol(vector<vector<int>> &matrix, int index, bool isSetRow) {
        if(matrix.empty() || matrix[0].empty() || index<0) return;
        int m = matrix.size(), n = matrix[0].size();
        if((isSetRow && index>=m) || (!isSetRow && index>=n)) return;

        if(isSetRow) {
            for(int j=0; j<n; j++)
                matrix[index][j] = 0;
        }
        else {
            for(int i=0; i<m; i++)
                matrix[i][index] = 0;
        }
    }
};
//int main () {
//    int n = 5;
//    Solution ss;
//    int res = ss.climbStairs(n);
//    cout << res;
//    return 0;
//}