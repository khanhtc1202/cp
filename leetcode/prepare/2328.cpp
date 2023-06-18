/*
https://leetcode.com/problems/number-of-increasing-paths-in-a-grid/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPaths(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        vector<int> dx = {0, 0, 1, -1};
        vector<int> dy = {1, -1, 0, 0};
        int mod = 1e9+7;

        function<int(int, int)> dfs = [&](int i, int j) -> int {
            if (dp[i][j] != 0) return dp[i][j];

            // Always have one path which is itself.
            int res = 1;
            for (int k = 0; k < 4; k++) {
                int nei_i = i + dx[k], nei_j = j + dy[k];
                // Ignore invalid cell
                if (nei_i < 0 || nei_i >= n || nei_j < 0 || nei_j >= m)
                    continue;
                // Ignore cell that greater than current
                if (grid[nei_i][nei_j] >= grid[i][j])
                    continue;

                (res += dfs(nei_i, nei_j)) %= mod;
            }
            // memo
            dp[i][j] = res;
            return res;
        };

        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                (ans += dfs(i, j)) %= mod;
            }
        }
        return ans;
    }
};
