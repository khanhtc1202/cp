#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        vector<int> dx = {0, 0, 1, -1};
        vector<int> dy = {1, -1, 0, 0};
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> dp(n, vector<int>(m, 0));
        
        function<int(int, int)> dfs = [&](int x, int y) -> int {
            if (dp[x][y] != 0) return dp[x][y];
            for (int i = 0; i < dx.size(); i++) {
                int vx = x+dx[i], vy = y+dy[i];
                if (0 > vx || n <= vx || 0 > vy || m <= vy || matrix[vx][vy] <= matrix[x][y])
                    continue;
                dp[x][y] = max(dp[x][y], dfs(vx, vy));
            }
            return ++dp[x][y];
        };
        
        int ans = 1;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                ans = max(ans, dfs(i, j));
        return ans;
    }

    int longestIncreasingPathTopo(vector<vector<int>>& matrix) {
        vector<int> dx = {0, 0, 1, -1};
        vector<int> dy = {1, -1, 0, 0};
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> indegree(n, vector<int>(m, 0));
        
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                for (int z = 0; z < 4; z++) {
                    int neix = i + dx[z], neiy = j + dy[z];
                    if (0 > neix || n <= neix || m <= neiy || 0 > neiy || matrix[neix][neiy] <= matrix[i][j])
                        continue;
                    indegree[neix][neiy]++;
                }
        
        queue<tuple<int, int, int>> zero_indegree;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (!indegree[i][j]) zero_indegree.push({i, j, 1});
        
        int ans = 0;
        while (!zero_indegree.empty()) {
            auto [ux, uy, d] = zero_indegree.front(); zero_indegree.pop();
            ans = max(ans, d);
            for (int i = 0; i < 4; i++) {
                int neix = ux + dx[i], neiy = uy + dy[i];
                if (0 > neix || n <= neix || m <= neiy || 0 > neiy || matrix[neix][neiy] <= matrix[ux][uy])
                        continue;
                indegree[neix][neiy]--;
                if (!indegree[neix][neiy]) zero_indegree.push({neix, neiy, d+1});
            }
        }
        
        return ans;
    }
};
