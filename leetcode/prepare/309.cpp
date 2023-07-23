/*
https://leetcode.com/problems/best-time-to-buy-and-sell-stock-with-cooldown
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> dp(n+1, 0);
        int mx = -prices[0];
        for (int i = 1; i < n; ++i) {
            // Max at i-1, or buy at i-1 and sell at i
            // mx store max dp[i-2] - prices[i-1] (prev loop)
            dp[i+1] = max(dp[i], mx + prices[i]);
            mx = max(mx, dp[i-1] - prices[i]);
        }
        return dp[n];
    }
};
