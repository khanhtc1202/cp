/*
https://leetcode.com/problems/shortest-path-in-binary-matrix/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        if (grid[0][0] != 0 || grid[n-1][m-1] != 0) return -1;

        vector<pair<int, int>> move = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};
        queue<vector<int>> q; q.push({0, 0});
        grid[0][0] = 1;

        while (!q.empty()) {
            int row = q.front()[0], col = q.front()[1]; q.pop();
            int distance = grid[row][col];
            if (row == n-1 && col == m-1) return distance;

            for (auto [h, v]: move) {
                int nrow = row+h, ncol = col+v;
                if (nrow < 0 || nrow >= n || ncol < 0 || ncol >= m) continue;
                if (grid[nrow][ncol] != 0) continue;

                q.push({nrow, ncol});
                grid[nrow][ncol] = distance+1;
            }
        }

        return -1;
    }
};
