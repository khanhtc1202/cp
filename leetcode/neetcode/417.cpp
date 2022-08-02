#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size(), m = heights[0].size();
        
        vector<vector<bool>> pacific(n, vector<bool>(m, false));
        bfs(heights, 0, 0, pacific);
        vector<vector<bool>> atlantic(n, vector<bool>(m, false));
        bfs(heights, n-1, m-1, atlantic);
        
        vector<vector<int>> res;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++)
                if (pacific[i][j] && atlantic[i][j])
                    res.push_back({i, j});

        return res;
    }

    void bfs(vector<vector<int>>& heights, int row, int col, vector<vector<bool>>& ocean) {
        int n = heights.size(), m = heights[0].size();
        queue<pair<int, int>> q;
        for (int i = 0; i < m; i++) {
            q.push({row, i});
            ocean[row][i] = true;
        }
        for (int i = 0; i < n; i++) {
            q.push({i, col});
            ocean[i][col] = true;
        }
        
        vector<int> dx = {-1, 0, 0, 1};
        vector<int> dy = {0, -1, 1, 0};

        auto valid = [=](int x, int y) -> bool {
            return x >= 0 && x < n && y >= 0 && y < m;
        };

        pair<int, int> u;
        while (!q.empty()) {
            u = q.front(); q.pop();
            for (int i = 0; i < dx.size(); i++) {
                int vx = u.first + dx[i];
                int vy = u.second + dy[i];

                if (!valid(vx, vy)) continue;
                if (ocean[vx][vy]) continue;
                if (heights[vx][vy] < heights[u.first][u.second]) continue;

                q.push({vx, vy});
                ocean[vx][vy] = true;
            }
        }
    }
};
