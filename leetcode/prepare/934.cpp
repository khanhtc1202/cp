/*
https://leetcode.com/problems/shortest-bridge/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestBridge(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();

        auto isValid = [&](int x, int y) -> bool {
            return x >= 0 && x < n && y >= 0 && y < m;
        };

        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};
        queue<pair<int, int>> q;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                // Find the first island cell then mark that island as 2.
                if (grid[i][j] == 1) {
                    // Mark first island cells to '2'.
                    vector<pair<int, int>> stk;
                    stk.push_back({i, j});
                    
                    while (!stk.empty()) {
                        auto [ux, uy] = stk.back(); stk.pop_back();
                        grid[ux][uy] = 2;
                        // Push to queue to splatter for finding bridge later.
                        q.push({ux, uy});
                        for (int k = 0; k < dx.size(); k++) {
                            int vx = ux + dx[k];
                            int vy = uy + dy[k];
                            if (!isValid(vx, vy)) continue;
                            if (grid[vx][vy] != 1) continue;
                            stk.push_back({vx, vy});
                        }
                    }

                    // Then stop.
                    goto L;
                }
            }
        }
        
L:
        int dist = 0;
        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                auto [ux, uy] = q.front(); q.pop();
                for (int j = 0; j < dx.size(); j++) {
                    int vx = ux + dx[j];
                    int vy = uy + dy[j];
                    if (!isValid(vx, vy)) continue;
                    if (grid[vx][vy] == 1) return dist;
                    if (grid[vx][vy] == 2) continue;
                    if (grid[vx][vy] == 0) {
                        // Mark water to current island cell to expand the current island.
                        grid[vx][vy] = 2;
                        q.push({vx, vy});
                    } 
                }
            }
            dist++;
        }
        return 0;
    }
};
