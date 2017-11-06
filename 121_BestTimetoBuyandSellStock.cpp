//121. Best Time to Buy and Sell Stock
//Say you have an array for which the ith element is the price of a given stock on day i.

//If you were only permitted to complete at most one transaction (ie, buy one and sell one share of the stock),
// design an algorithm to find the maximum profit.
//Example 1:
//Input: [7, 1, 5, 3, 6, 4]
//Output: 5
//
//max. difference = 6-1 = 5 (not 7-1 = 6, as selling price needs to be larger than buying price)
//Example 2:
//Input: [7, 6, 4, 3, 1]
//Output: 0
//
//In this case, no transaction is done, i.e. max profit = 0.
#include <iostream>
#include "toolkit.h"

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.empty()) return 0;
        int ret = 0, minPrice = prices[0];
        for (int i = 1; i < prices.size(); ++i) {
            if (prices[i] < minPrice) {
                minPrice = prices[i];
            } else {
                ret = max(prices[i] - minPrice, ret);
            }
        }
        return ret;
    }
};

int main() {
    int a[] = {7, 1, 5, 3, 6, 4};
    vector<int> prices(a, a + 6);
    Solution ss;
    int res = ss.maxProfit(prices);
    std::cout << res;
}