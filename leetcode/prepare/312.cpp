/*
https://leetcode.com/problems/burst-balloons/description/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> memo(n, vector<int>(n, -1));

        function<int(int, int)> dp = [&](int l, int r) -> int {
            if (l > r) return 0;
            if (memo[l][r] != -1) return memo[l][r];

            int lv = l == 0 ? 1 : nums[l-1];
            int rv = r == n-1 ? 1 : nums[r+1];
            int cos = lv * rv;

            for (int k = l; k <= r; k++) {
                memo[l][r] = max(memo[l][r], dp(l, k-1) + dp(k+1, r) + nums[k]*cos);
            }
            return memo[l][r];
        };

        return dp(0, n-1);
    }

    int maxCoinsOp(vector<int>& nums) {
        int n = nums.size();
        int dp[301][301] {};

        for (int l = n-1; l >= 0; l--) {
            for (int r = l; r < n; r++) {
                int lv = l == 0 ? 1 : nums[l-1];
                int rv = r == n-1 ? 1 : nums[r+1];
                int cos = lv * rv;

                for (int k = l; k <= r; k++) {
                    int lc = l > k-1 ? 0 : dp[l][k-1];
                    int rc = k+1 > r ? 0 : dp[k+1][r];
                    dp[l][r] = max(dp[l][r], lc + rc + nums[k]*cos);
                }
            }
        }

        return dp[0][n-1];
    }
};
