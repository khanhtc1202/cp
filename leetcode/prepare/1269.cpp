/*
https://leetcode.com/problems/number-of-ways-to-stay-in-the-same-place-after-some-steps/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numWays(int steps, int arrLen) {
        int mod = 1e9+7;
        arrLen = min(arrLen, steps);
        vector<vector<int>> dp(arrLen, vector(steps+1, 0));
        dp[0][0] = 1;

        for (int remain = 1; remain <= steps; ++remain) {
            for (int curr = arrLen - 1; curr >= 0; --curr) {
                int ans = dp[curr][remain-1];

                if (curr > 0)
                    (ans += dp[curr-1][remain-1]) %= mod;

                if (curr < arrLen - 1)
                    (ans += dp[curr+1][remain-1]) %= mod;

                dp[curr][remain] = ans;
            }
        }
        return dp[0][steps];
    }
};
