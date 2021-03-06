//13. Roman to Integer
//Given a roman numeral, convert it to an integer.

//Input is guaranteed to be within the range from 1 to 3999.

class Solution {
public:
    int romanToInt(string s) {
        if(s.length()<1) return 0;
        int result = 0;
        int sub = getRomanValue(s[0]);
        int lastv = sub;
        for(int i = 1 ; i < s.length(); ++i) {
            char curc = s[i];
            int curv = getRomanValue(curc);
            if(curv == lastv) 
                sub += curv;
            else if( curv < lastv) {
                result += sub;
                sub = curv;
            } else {
                sub = curv - sub;
            }
            lastv = curv;
        }
        result += sub;
        return result;
    }
int getRomanValue(char c) {
        switch(c) {
            case 'I': return 1; 
            case 'V': return 5;
            case 'X': return 10;
            case 'L': return 50;
            case 'C': return 100;
            case 'D': return 500;
            case 'M': return 1000;
            default: return 0;
        }
}
};