/**128. Longest Consecutive Sequence
 * Given an unsorted array of integers, find the length of the longest consecutive elements sequence.
 * For example,
 * Given [100, 4, 200, 1, 3, 2],
 * The longest consecutive elements sequence is [1, 2, 3, 4]. Return its length: 4.
 * Your algorithm should run in O(n) complexity.
 */

#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        if (nums.empty()) {
            return 0;
        }

        std::unordered_set<int> unorderedSet;
        for(size_t i = 0; i < nums.size(); i++) {
            unorderedSet.insert(nums[i]);
        }

        int maxLength = 0;
        for(size_t i = 0; i < nums.size(); i++) {
            if (unorderedSet.size() == 0)
                break;
            int curNum = nums[i];
            int curLength = 0;
            while (unorderedSet.count(curNum)) {
                unorderedSet.erase(curNum);
                curLength++;
                curNum++;
            }
            curNum = nums[i] - 1;
            while (unorderedSet.count(curNum)) {
                unorderedSet.erase(curNum);
                curLength++;
                curNum--;
            }

            maxLength = std::max(maxLength, curLength);
        }
        return maxLength;
    }
};

int main() {
    int a[6] = {100, 4, 200, 1, 3, 2};
    std::vector<int> input(a, a+6);
    Solution ss;
    std::cout << ss.longestConsecutive(input) << std::endl;
    return 0;
}