// 16. 3Sum Closest
// Given an array S of n integers, find three integers in S such that the sum is closest to a given number, target. 
//Return the sum of the three integers. You may assume that each input would have exactly one solution.
//For example, given array S = {-1 2 1 -4}, and target = 1.
//The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

class Solution {
public:
    int threeSumClosest(vector<int> &num, int target) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        sort(num.begin(), num.end());
        
        int ret;
        bool first = true;
        
        for(int i = 0; i < num.size(); i++)
        {
            int j = i + 1;
            int k = num.size() - 1;
            
            while(j < k)
            {
                int sum = num[i] + num[j] + num[k];
                if (first)
                {
                    ret = sum;
                    first = false;
                }
                else
                {
                    if (abs(sum - target) < abs(ret - target))
                        ret = sum;                                         
                }
                
                if (ret == target)
                    return ret;
                
                if (sum > target)
                    k--;
                else
                    j++;
            }
        }
        
        return ret;
    }
};