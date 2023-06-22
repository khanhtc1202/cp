/*
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-transaction-fee/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices, int fee) {
        int n = prices.size();
        // free is ready to buy, hold is ready to sell (so must bought previously).
        int free = 0, hold = -prices[0];

        for (int i = 1; i < n; i++) {
            int tmp = hold;
            hold = max(hold, free - prices[i]);
            free = max(free, tmp + prices[i] - fee);
        }
        return free;
    }
};
