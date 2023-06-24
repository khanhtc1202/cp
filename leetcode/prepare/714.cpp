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

    int maxProfitSlow(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int> dp(n, 0);
        for (int i = 1; i < n; i++) {
            dp[i] = dp[i-1];
            for (int j = 0; j < i; j++) {
                int prev = j ? dp[j-1] : 0;
                dp[i] = max(dp[i], prev + prices[i] - prices[j] - fee);
            }
        }
        return dp[n-1];
    }

    int maxProfitOpt(vector<int>& prices, int fee) {
        int n = prices.size();
        vector<int> dp(n, 0);
        int curMax = -prices[0]; // buy at 0;

        // dp[i] = max(dp[i], dp[j-1] + prices[i] - prices[j] - fee)
        // => dp[i] = max(dp[i], dp[j-1] - prices[j] + prices[i] - fee)
        // since (prices[i] - fee) is const, find max(dp[j-1] - prices[j])
        for (int i = 0; i < n; i++) {
            if (i) dp[i] = dp[i - 1];

            dp[i] = max(dp[i], curMax + prices[i] - fee);
            curMax = max(curMax, (i ? dp[i - 1] : 0) - prices[i]);
        }

        return dp[n - 1];
    }
};
