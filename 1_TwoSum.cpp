//Given an array of integers, return indices of the two numbers such that they add up to a specific target.

//You may assume that each input would have exactly one solution, and you may not use the same element twice.

//Example:
//Given nums = [2, 7, 11, 15], target = 9,

//Because nums[0] + nums[1] = 2 + 7 = 9,
//return [0, 1].

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        int i, sum;  
        vector<int> results;  
        map<int, int> hmap;  
        for(i=0; i<numbers.size(); i++)
        { 
            if(!hmap.count(numbers[i]))
            {  
                hmap.insert(pair<int, int>(numbers[i], i));  
            }  
            if(hmap.count(target-numbers[i]))
            {  
                int n=hmap[target-numbers[i]];  
                if(n<i)
                {  
                    results.push_back(n+1);  
                    results.push_back(i+1);  
                    //cout<<n+1<<", "<<i+1<<endl;  
                    return results;  
                }  
  
            }  
        }  
        return results;  
    }
};