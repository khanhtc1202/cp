/*
Problem desc: https://leetcode.com/problems/count-all-possible-routes/
*/

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countRoutes(vector<int>& locations, int start, int finish, int fuel) {
        int n = locations.size();
        int MOD = 1e9+7;
        vector<vector<int>> dp(fuel+1, vector<int>(n, 0));
        dp[0][start] = 1;
        int ans = 0;
        for (int x = 0; x < fuel; x++) {
            for (int i = 0; i < n; i++) {
                if (dp[x][i] == 0) continue;
                if (i == finish)
                    (ans += dp[x][i]) %= MOD;
                for (int j = 0; j < n; j++) {
                    if (i == j) continue;

                    int cost = abs(locations[j] - locations[i]);

                    if (x + cost > fuel) continue;
                    (dp[x + cost][j] += dp[x][i]) %= MOD;
                }
            }
        }
        (ans += dp[fuel][finish]) %= MOD;
        return ans;
    }
};
