//48. Rotate Image
//You are given an n x n 2D matrix representing an image.
//
//Rotate the image by 90 degrees (clockwise).

#include <iostream>
#include <vector>
#include "toolkit.h"

using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>> &matrix) {
        int start = 0, end = matrix.size() - 1;
        while(start < end) {
            for (int i = start; i < end; i++) {
                int offset = i - start;
                int temp = matrix[start][i];
                matrix[start][i] = matrix[end-offset][start];
                matrix[end-offset][start] = matrix[end][end-offset];
                matrix[end][end-offset] = matrix[start+offset][end];
                matrix[start+offset][end] = temp;
            }
            start++;
            end--;
        }
    }
};

int main() {
    int a[] = {1, 2, 3};
    int b[] = {4, 5, 6};
    int c[] = {7, 8, 9};
    vector<int> aa(a, a+ sizeof(a) / sizeof(int));
    vector<int> bb(b, b+ sizeof(b) / sizeof(int));
    vector<int> cc(c, c+ sizeof(c) / sizeof(int));
    vector<vector<int>> res;
    res.push_back(aa);
    res.push_back(bb);
    res.push_back(cc);
    Solution ss;
    ss.rotate(res);
    for (int i = 0; i < res.size(); ++i) {
        printVector(res[i]);
    }
}