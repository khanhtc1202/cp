/*
Problem desc: https://leetcode.com/problems/allocate-mailboxes/
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minDistance(vector<int>& houses, int k) {
        auto median = [&](int s, int e) -> int {
            s--; e--;
            int mid = (s+e)/2;
            int ans = 0;
            for (int i = s; i <= e; i++) {
                ans += abs(houses[mid] - houses[i]);
            }
            return ans;
        };

        sort(houses.begin(), houses.end());
        int n = houses.size();
        vector<vector<int>> dp(n+1, vector<int>(k+1, 1e9));
        dp[0][0] = 0;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= k; j++) {
                for (int x = 1; x <= i-j+1; x++) {
                    dp[i][j] = min(dp[i][j], dp[i-x][j-1] + median(i-x+1, i));
                }
            }
        return dp[n][k];
    }
};
