//31. Next Permutation Add to List
//Implement next permutation, which rearranges numbers into the lexicographically next greater permutation of numbers.
//
//If such arrangement is not possible, it must rearrange it as the lowest possible order (ie, sorted in ascending order).
//
//The replacement must be in-place, do not allocate extra memory.
//
//Here are some examples. Inputs are in the left-hand column and its corresponding outputs are in the right-hand column.
//1,2,3 → 1,3,2
//3,2,1 → 1,2,3
//1,1,5 → 1,5,1


#include <iostream>
#include <vector>

using namespace std;

class Solution {
    public:
        void nextPermutation(vector<int> &num) {
            if(num.size()<2) return;
            int n = num.size(), j = n-2;
            while(j>=0 && num[j]>=num[j+1]) j--;

            if(j<0) {
                sort(num.begin(),num.end());
                return;
            }

            int i=j+1;
            while(i<n && num[i]>num[j]) i++;
            i--;

            swap(num[i],num[j]);
            sort(num.begin()+j+1, num.end());
        }
};

int main() {
    //4203022
    int a[] = {4,2,0,2,3,2,0};
    vector<int> nums(a, a + sizeof(a) / sizeof(int));
    Solution ss;
    ss.nextPermutation(nums);
    cout << "res:";
    for (int i = 0; i < nums.size(); ++i) {
        cout << nums[i];
    }
}