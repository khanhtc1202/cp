/*
https://leetcode.com/problems/number-of-ways-to-reach-a-position-after-exactly-k-steps/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfWays(int startPos, int endPos, int k) {
        int dist = abs(startPos - endPos);
        if ((k < dist) || (k - dist) % 2) return 0;

        auto combination = [=](int n, int k) -> int {
            int mod = 1e9+7;
            k = min(k, n-k);
            vector<vector<int>> dp(n+1, vector<int>(k+1));
            for (int i = 0; i <= n; ++i) dp[i][0] = 1;
            for (int i = 1; i <= n; ++i) {
                for (int j = 1; j <= k; ++j) {
                    dp[i][j] = (dp[i-1][j-1] + dp[i-1][j]) % mod;
                }
            }
            return dp[n][k];
        };

        return combination(k, (k - dist)/2);
    }
};
