/*
https://leetcode.com/problems/out-of-boundary-paths/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
int MOD = 1e9+7;
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<pair<int,int>> moves = {{1,0}, {-1,0}, {0,1}, {0,-1}};
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(maxMove+1, -1)));

        function<int(int,int,int)> dfs = [&](int i, int j, int moveLeft) -> int {
            if (i < 0 || i >= m || j < 0 || j >= n) return 1;
            if (moveLeft == 0) return 0;

            if (dp[i][j][moveLeft] >= 0) return dp[i][j][moveLeft];

            int ans = 0;
            for (auto [x, y]: moves) {
                (ans += dfs(i+x, j+y, moveLeft-1)) %= MOD;
            }
            return dp[i][j][moveLeft] = ans;
        };

        return dfs(startRow, startColumn, maxMove);
    }
};
