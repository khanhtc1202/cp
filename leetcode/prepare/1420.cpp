/*
https://leetcode.com/problems/build-array-where-you-can-find-the-maximum-exactly-k-comparisons/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numOfArrays(int n, int m, int k) {
        vector<vector<vector<int>>> dp(n+1, vector(m+1, vector(k+1, 0)));
        int MOD = 1e9+7;

        for (int num = 0; num < dp[0].size(); ++num) {
            dp[n][num][0] = 1;
        }

        for (int i = n-1; i >= 0; --i) {
            for (int currMax = m; currMax >= 0; --currMax) {
                for (int cost = 0; cost <= k; ++cost) {
                    int ans = 0;
                    for (int num = 1; num <= currMax; ++num) {
                        (ans += dp[i+1][currMax][cost]) %= MOD;
                    }

                    if (cost > 0) {
                        for (int num = currMax + 1; num <= m; ++num) {
                            (ans += dp[i+1][num][cost-1]) %= MOD;
                        }
                    }

                    dp[i][currMax][cost] = ans;
                }
            }
        }
        return dp[0][0][k];
    }
};
