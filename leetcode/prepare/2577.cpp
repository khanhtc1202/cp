/*
https://leetcode.com/problems/minimum-time-to-visit-a-cell-in-a-grid/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        if (grid[0][1] > 1 && grid[1][0] > 1) return -1;

        int rows = grid.size(), cols = grid[0].size();
        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, -1, 1};
        vector<vector<bool>> visited(rows, vector<bool>(cols, false));

        // min heap {time, row, col}
        priority_queue<vector<int>, vector<vector<int>>, greater<>> pq;
        pq.push({0, 0, 0});

        while (!pq.empty()) {
            auto curr = pq.top();
            pq.pop();
            int time = curr[0], row = curr[1], col = curr[2];

            if (row == rows-1 && col == cols-1) return time;
            if (visited[row][col]) continue;
            visited[row][col] = true;

            for (int k = 0; k < 4; ++k) {
                int nextRow = row + dx[k], nextCol = col + dy[k];
                if (nextRow < 0 || nextRow >= rows || nextCol < 0 || nextCol >= cols)
                    continue;

                if (grid[nextRow][nextCol] <= time+1) {
                    pq.push({time+1, nextRow, nextCol});
                } else {
                    // buffer time is check wether when possible to jump to {nextRow, nextCol}
                    // it's at the curr ceil or the previous ceil
                    int buffer = (grid[nextRow][nextCol] - time) % 2 == 0 ? 1 : 0;
                    pq.push({grid[nextRow][nextCol] + buffer, nextRow, nextCol});
                }
            }
        }
        return -1;
    }
};
