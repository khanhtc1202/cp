/*
Problem desc: https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size(), m = grid[0].size();
        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};

        auto valid = [=](int x, int y) -> bool {
            return x >= 0 && x < n && y >= 0 && y < m;
        };

        queue<tuple<int, int, int>> q;
        q.push({0, 0, 0});
        vector<vector<vector<int>>> dist(n, vector<vector<int>>(m, vector<int>(k+1, -1)));
        dist[0][0][0] = 0;
        while (!q.empty()) {
            auto [u, v, c] = q.front(); q.pop();
            if (u == (n-1) && v == (m-1)) return dist[u][v][c];
            for (int i = 0; i < dx.size(); i++) {
                int x = u+dx[i], y = v+dy[i];
                if (valid(x, y)) {
                    int nc = c + grid[x][y];
                    if (nc > k) continue;
                    if (dist[x][y][nc] != -1) continue;
                    dist[x][y][nc] = dist[u][v][c]+1;
                    q.push({x,y,nc});
                }
            }
        }
        return -1;
    }
};
