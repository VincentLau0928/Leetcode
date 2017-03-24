//Implement atoi to convert a string to an integer.
//
//Hint: Carefully consider all possible input cases. If you want a challenge, please do not see below and ask yourself what are the possible input cases.
//
//Notes: It is intended for this problem to be specified vaguely (ie, no given input specs). You are responsible to gather all the input requirements up front.


#include <iostream>

using namespace std;

class Solution {
public:
    int myAtoi(string str){
        if (str.empty() || str[0] == '\0')
            return 0;
        int i = 0;
        int flag = 1;

        while (str[i] == ' ')
            i++;
        if(str[i] == '+' || str[i] == '-')
        {
            if (str[i+1] > '9' || str[i+1] < '0')
                return 0;
            if (str[i] == '-')
                flag = -1;
            if (str[i] == '-' || str[i] == '+')
                i++;
        }
        long long integernum = 0;
        while (str[i] != '\0')
        {
            if (str[i] <= '9' && str[i] >= '0')
            {
                integernum = integernum * 10 + str[i] - '0';
                if (integernum > INT_MAX)
                {
                    return flag < 0 ? INT_MIN : INT_MAX;
                }
                i++;
            }
            else break;
        }
        return flag * integernum;
    }
};
int main() {
    string a = "   -1231aa";
    Solution ss;
    int re = ss.myAtoi(a);
    cout << re;
}