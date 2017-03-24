// 20. Valid Parentheses
// Given a string containing just the characters '(', ')', '{', '}', '[' and ']', 
// determine if the input string is valid.

// The brackets must close in the correct order, "()" and "()[]{}" are all valid but "(]" and "([)]" are not.

class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]==')'||s[i]==']'||s[i]=='}')
             {
                 if(st.empty())
                 return false;
                 else
                 {
                     char c = st.top();
                     if ((c == '(' && s[i] != ')') || (c == '[' && s[i] != ']') || (c == '{' && s[i] != '}'))
                     return false;
                     st.pop();
                 }
                 
             }
            else st.push(s[i]);
             
        }
        return st.empty();
        
    }
};