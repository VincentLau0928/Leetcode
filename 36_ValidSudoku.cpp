//36. Valid Sudoku
//Determine if a Sudoku is valid, according to: Sudoku Puzzles - The Rules.
//
//The Sudoku board could be partially filled, where empty cells are filled with the character '.'.
//        530070000
//        600195000
//        098000060
//        800600003
//        400803001
//        700020006
//        060000280
//        000419005
//        000080079
//A partially filled sudoku which is valid.
#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    bool checkSudoku(vector<vector<char>>& board, int m, int n) {
        //检测字符是否有效
        if (board[m][n] - '0' < 0 || board[m][n] - '0' > 9)
            return false;
        //检测字符同行是否重复
        for (int i = 0; i < 9; ++i) {
            if (i!= n && board[m][i] == board[m][n])
                return false;
        }
        //检测字符同列是否重复
        for (int j = 0; j < 9; ++j) {
            if (j != m && board[j][n] == board[m][n])
                return false;
        }
        //检测字符同九宫内是否重复 zonem zonen是取得该字符九宫格左上的那个元素
        int zonem = m / 3 * 3; int zonen = n / 3 * 3;
        for (int i = zonem; i < zonem + 3; i++) {
            for (int j = zonen; j < zonen + 3; ++j) {
                if ((i!=m || j!=n) && board[i][j] == board[m][n])
                    return false;
            }
        }
        return true;
    }
    bool isValidSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] != '.' && !checkSudoku(board, i, j))
                    return false;
            }
        }
        return true;
    }
};

int main() {
    char a[] = ".87654321";
    char b[] = "2........";
    char c[] = "3........";
    char d[] = "4........";
    char e[] = "5........";
    char f[] = "6........";
    char g[] = "7........";
    char h[] = "8........";
    char i[] = "9........";
    vector<char> aa(a, a + sizeof(a) / sizeof(char));
    vector<char> bb(b, b + sizeof(b) / sizeof(char));
    vector<char> cc(c, c + sizeof(c) / sizeof(char));
    vector<char> dd(d, d + sizeof(d) / sizeof(char));
    vector<char> ee(e, e + sizeof(e) / sizeof(char));
    vector<char> ff(f, f + sizeof(f) / sizeof(char));
    vector<char> gg(g, g + sizeof(g) / sizeof(char));
    vector<char> hh(h, h + sizeof(h) / sizeof(char));
    vector<char> ii(i, i + sizeof(i) / sizeof(char));
    vector<vector<char>> board;
    board.push_back(aa);
    board.push_back(bb);
    board.push_back(cc);
    board.push_back(dd);
    board.push_back(ee);
    board.push_back(ff);
    board.push_back(gg);
    board.push_back(hh);
    board.push_back(ii);
    Solution ss;
    bool res = ss.isValidSudoku(board);
    cout << res;
}