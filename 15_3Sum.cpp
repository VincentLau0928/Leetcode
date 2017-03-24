//15.3Sum
//Given an array S of n integers, are there elements a, b, c in S such that a + b + c = 0? 
// Find all unique triplets in the array which gives the sum of zero.

// Note: The solution set must not contain duplicate triplets.

// For example, given array S = [-1, 0, 1, 2, -1, -4],

// A solution set is:
// [
//   [-1, 0, 1],
//   [-1, -1, 2]
// ]

class Solution {
public:
   vector<vector<int> > threeSum(vector<int> &num) 
{
	vector<vector<int> > ret;
	if (num.size() <3) return ret;
	sort(num.begin(), num.end());
	vector<int>::iterator itor;
	for (itor = num.begin(); itor != num.end();itor++)
	{
		if (itor!=num.begin()&&*itor==*(itor-1))
		{
			continue;
		}
		vector<int>::iterator first = itor + 1;
		vector<int>::iterator last=num.end()-1;
		while (first<last)
		{
			int sum = *itor + *first + *last;
			if (sum<0)
			{
				first++;
			}
			else if (sum>0)
			{
				last--;
			}
			else if (first != itor+1 && *first == *(first-1))
			{
				first++;
			}
			else if (last != num.end() - 1 && *last == *(last+1))
			{
				last--;
			}
			else
			{
				vector<int> result;
				result.push_back(*itor);
				result.push_back(*first);
				result.push_back(*last);
				ret.push_back(result);
				++first;
				--last;
			}
		}
	}
	return ret;
} 
   
};