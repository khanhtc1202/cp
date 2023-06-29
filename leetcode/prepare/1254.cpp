/*
https://leetcode.com/problems/number-of-closed-islands/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int closedIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};

        auto bfs = [&](int r, int c) -> bool {
            queue<pair<int, int>> q;
            q.push({r, c});
            visited[r][c] = true;
            int isClosed = true;

            while (!q.empty()) {
                r = q.front().first, c = q.front().second;
                q.pop();

                for (int i = 0; i < 4; i++) {
                    int rv = r + dx[i];
                    int cv = c + dy[i];
                    if (rv < 0 || rv >= n || cv < 0 || cv >= m) {
                        isClosed = false;
                    } else if (grid[rv][cv] == 0 && !visited[rv][cv]) {
                        q.push({rv, cv});
                        visited[rv][cv] = true;
                    }
                }
            }
            return isClosed;
        };


        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0 && !visited[i][j])
                    if (bfs(i, j)) ans++;
            }
        }
        return ans;
    }
};
