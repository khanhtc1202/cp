/*
https://leetcode.com/problems/path-with-minimum-effort/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int r = heights.size(), c = heights[0].size();
        vector<vector<int>> dist(r, vector<int>(c, INT_MAX));
        priority_queue<tuple<int,int,int>, vector<tuple<int,int,int>>, greater<>> minHeap;
        minHeap.push({0,0,0});
        dist[0][0] = 0;

        vector<int> dx = {0, 0, 1, -1};
        vector<int> dy = {1, -1, 0, 0};

        while (!minHeap.empty()) {
            auto [effort, x, y] = minHeap.top();
            minHeap.pop();

            // Skip if revisit but not better
            if (effort > dist[x][y]) continue;

            // First time reach exit -> best ?
            if (x == r - 1 && y == c - 1) return effort;

            for (int i = 0; i < 4; ++i) {
                int nx = x + dx[i], ny = y + dy[i];
                if (nx < 0 || nx >= r || ny < 0 || ny >= c) continue;

                int new_effort = max(effort, abs(heights[x][y] - heights[nx][ny]));
                if (new_effort < dist[nx][ny]) {
                    dist[nx][ny] = new_effort;
                    minHeap.push({new_effort, nx, ny});
                }
            }
        }
        return -1;
    }
};
