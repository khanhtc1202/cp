/*
https://leetcode.com/problems/trapping-rain-water-ii/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trapRainWater(vector<vector<int>>& heightMap) {
        int n = heightMap.size(), m = heightMap[0].size();

        // Min-heap to store the boundary cells
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;

        // Visited grid
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        // Add all boundary cells to the priority queue
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 || i == n - 1 || j == 0 || j == m - 1) {
                    pq.push({heightMap[i][j], {i, j}});
                    visited[i][j] = true;
                }
            }
        }

        // Directions for moving in the grid
        vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        int trappedWater = 0;

        // Process the cells in the priority queue
        while (!pq.empty()) {
            auto cell = pq.top();
            pq.pop();

            int height = cell.first;
            int x = cell.second.first;
            int y = cell.second.second;

            for (auto dir : directions) {
                int nx = x + dir.first;
                int ny = y + dir.second;

                // Skip invalid or already visited cells
                if (nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny]) {
                    continue;
                }

                // Calculate trapped water for the neighboring cell
                trappedWater += max(0, height - heightMap[nx][ny]);

                // Update the height of the neighboring cell to the max of its height and the current cell's height
                pq.push({max(height, heightMap[nx][ny]), {nx, ny}});
                visited[nx][ny] = true;
            }
        }

        return trappedWater;
    }
};
