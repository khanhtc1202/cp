/*
https://leetcode.com/problems/minimum-difficulty-of-a-job-schedule/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDifficulty(vector<int>& jobDifficulty, int d) {
        int n = jobDifficulty.size();
        // dp[i][j] stores min value for first i jobs for j days
        vector<vector<int>> dp(n+1, vector<int>(d+1, INT_MAX));

        dp[0][0] = 0;
        for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= min(i, d); ++j) {
                int _max = 0;
                for (int k = i; k > 0; --k) {
                    // _max stores max value of range [k-1, i]
                    _max = max(_max, jobDifficulty[k-1]);
                    // dp[i][j] builds up based on all previous
                    // [j-1] days + max of last day (stored in _max)
                    if (dp[k-1][j-1] == INT_MAX) continue;
                    else dp[i][j] = min(dp[i][j], dp[k-1][j-1]+_max);
                }
            }
        }
        return dp[n][d] == INT_MAX ? -1 : dp[n][d];
    }
};
