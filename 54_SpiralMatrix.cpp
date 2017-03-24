//54. Spiral Matrix
//Given a matrix of m x n elements (m rows, n columns), return all elements of the matrix in spiral order.
//
//For example,
//        Given the following matrix:
//
//[
//[ 1, 2, 3 ],
//[ 4, 5, 6 ],
//[ 7, 8, 9 ]
//]
//You should return [1,2,3,6,9,8,7,4,5].

#include <iostream>
#include <vector>
#include "toolkit.h"

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> > &matrix) {
        vector<int> ret;
        if(matrix.empty() || matrix[0].empty()) return ret;
        int m = matrix.size(), n = matrix[0].size();
        int nlvl = (min(m,n)+1)/2;
        for(int i=0; i<nlvl; i++) {
            int lastRow = m-1-i;
            int lastCol = n-1-i;
            if(lastRow==i) {    // one row remain
                for(int j=i; j<=lastCol; j++)
                    ret.push_back(matrix[i][j]);
            }
            else if(lastCol==i) {   // one col remain
                for(int j=i; j<=lastRow; j++)
                    ret.push_back(matrix[j][i]);
            }
            else {
                for(int j=i; j<lastCol; j++)
                    ret.push_back(matrix[i][j]);
                for(int j=i; j<lastRow; j++)
                    ret.push_back(matrix[j][lastCol]);
                for(int j=lastCol; j>i; j--)
                    ret.push_back(matrix[lastRow][j]);
                for(int j=lastRow; j>i; j--)
                    ret.push_back(matrix[j][i]);
            }
        }
        return ret;
    }

};

int main() {
    int a[]  = {1,2,3};
    int b[] = {4,5,6};
    int c[] = {7,8,9};
    vector<int> aa(a, a+3);
    vector<int> bb(b, b+3);
    vector<int> cc(c, c+3);
    vector<vector<int>> matrix;
    matrix.push_back(aa);
    matrix.push_back(bb);
    matrix.push_back(cc);
    Solution ss;
    vector<int> res = ss.spiralOrder(matrix);
    printVector(res);
}