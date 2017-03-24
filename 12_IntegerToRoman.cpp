//12. Integer to Roman
//Given an integer, convert it to a roman numeral.
//Input is guaranteed to be within the range from 1 to 3999.

//基本字符            I V X  L  C   D   M
//相应的阿拉伯数字表示为 1 5 10 50 100 500 1000
//相同的数字连写，所表示的数等于这些数字相加得到的数，如：Ⅲ = 3；
//小的数字在大的数字的右边，所表示的数等于这些数字相加得到的数， 如：Ⅷ = 8；Ⅻ = 12；
//小的数字，（限于Ⅰ、X 和C）在大的数字的左边，所表示的数等于大数减小数得到的数，如：Ⅳ= 4；Ⅸ= 9；
//正常使用时，连写的数字重复不得超过三次。
//在一个数的上面画一条横线，表示这个数扩大1000倍。
#include <iostream>

using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string res;
        int digit[13] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string dict[13] = {"M", "CM", "D", "CD", "C", "XC", "L", "XL", "X", "IX", "V", "IV", "I"};
        for (int i = 0; i < 13; ++i) {
            if (num >= digit[i]) {
                int times = num / digit[i];
                num %= digit[i];
                for (int j = 0; j < times; ++j) {
                    res.append(dict[i]);
                }
            }
        }
        return res;
    }
};

int main() {
    Solution ss;
    for (int i = 1; i <= 12; i++) {
        string res = ss.intToRoman(i);
        cout << res << " ";
    }
    return 0;
}