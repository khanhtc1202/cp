#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();
        if (n == 2)
            return min(cost[0], cost[1]);

        vector<int> dp(n, 0);
        dp[0] = cost[0];
        dp[1] = cost[1];
        for (int i = 2; i < n; i++) {
            dp[i] = cost[i] + min(dp[i-1], dp[i-2]);
        }
        return min(dp[n-1], dp[n-2]);
    }
    
    int minCostClimbingStairsMen(vector<int>& cost) {
        int n = cost.size();
        if (n == 2)
            return min(cost[0], cost[1]);

        int out;
        int p2 = cost[0];
        int p1 = cost[1];
        for (int i = 2; i < n; i++) {
            out = cost[i] + min(p1, p2);
            p2 = p1;
            p1 = out;
        }
        return min(p2, p1);
    }
};
