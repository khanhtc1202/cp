#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        queue<pair<int,int>> rottens;
        vector<int> dx = {-1, 0, 0, 1};
        vector<int> dy = {0, -1, 1, 0};
        vector<vector<int>> visited(n, vector<int>(m, -1));

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (grid[i][j] == 2) {
                    rottens.push({i, j});
                    visited[i][j] = 0;
                }
        
        pair<int, int> r;
        while (!rottens.empty()) {
            r = rottens.front();
            rottens.pop();

            for (int i = 0; i < dx.size(); i++) {
                pair<int, int> nr = {r.first+dx[i], r.second+dy[i]};

                if (!isValid(nr.first, nr.second, n, m))
                    continue;

                if (visited[nr.first][nr.second] != -1)
                    continue;

                if (grid[nr.first][nr.second] == 0)
                    continue;

                rottens.push(nr);
                visited[nr.first][nr.second] = visited[r.first][r.second] + 1;
            }

        }

        int ans = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                ans = max(ans, visited[i][j]);
                if (visited[i][j] == -1 && grid[i][j] == 1)
                    return -1;
            }

        return ans;
    }

    bool isValid(int x, int y, int m, int n) {
        return x >= 0 && x < m && y >= 0 && y < n;
    }
};
