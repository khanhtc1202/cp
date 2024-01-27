/*
https://leetcode.com/problems/k-inverse-pairs-array/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
const int MOD = 1e9+7;
public:
    int kInversePairs(int n, int k) {
        auto dp = vector(n + 1, vector<int>(k + 1));
        dp[1][0] = 1;
        for (int i = 2; i <= n; ++i) {
            for (int j = 0; j <= k; ++j) {
                int psum = 0;
                for (int x = 0; x < i; ++x) {
                    if (j - x < 0) {
                        break;
                    }
                    (psum += dp[i-1][j-x]) %= MOD;
                }
                dp[i][j] = psum;
            }
        }
        return dp[n][k];
    }
};
