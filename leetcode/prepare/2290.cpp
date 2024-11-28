/*
https://leetcode.com/problems/minimum-obstacle-removal-to-reach-corner/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        vector<int> dx = {-1, 0, 0, 1};
        vector<int> dy = {0, 1, -1, 0};
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> cost(n, vector<int>(m, INT_MAX));
        cost[0][0] = 0;

        deque<array<int, 3>> q;
        q.push_back({0, 0, 0});  // {no obs, row 0, col 0}

        while (!q.empty()) {
            auto x = q.front(); q.pop_front();
            int obs = x[0], row = x[1], col = x[2];
            for (int k = 0; k < 4; ++k) {
                int nextR = row + dx[k], nextCol = col + dy[k];
                if (nextR < 0 || nextR >= n || nextCol < 0 || nextCol >= m)
                    continue;
                if (cost[nextR][nextCol] != INT_MAX) // second time visit
                    continue;
                if (grid[nextR][nextCol] == 1) { // Faced obs
                    cost[nextR][nextCol] = obs + 1;
                    q.push_back({obs+1, nextR, nextCol}); // 0-1 BFS trick, this mean next lvl node
                } else {
                    cost[nextR][nextCol] = obs;
                    q.push_front({obs, nextR, nextCol}); // 0-1 BFS trick, this mean same lvl node
                }
            }
        }
        return cost[n-1][m-1];
    }
};
