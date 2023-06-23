/*
https://leetcode.com/problems/longest-arithmetic-subsequence/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // 113ms
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size(), ans = 0, diff;
        int dp[n][1001];
        memset(dp, 0, sizeof(dp));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                diff = nums[i] - nums[j] + 500;
                dp[i][diff] = max(dp[j][diff]+1, 2);
                ans = max(ans, dp[i][diff]);
            }
        }
        return ans;
    }
    // > 2s
    int _longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
        vector<unordered_map<int,int>> dp(n);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            dp[i] = unordered_map<int,int>();
            for (int j = 0; j < i; j++) {
                int diff = nums[i] - nums[j];
                if (dp[j].find(diff) == dp[j].end()) {
                    dp[i][diff] = 2;
                } else {
                    dp[i][diff] = dp[j][diff] + 1;
                }
                ans = max(ans, dp[i][diff]);
            }
        }
        return ans;
    }
};
