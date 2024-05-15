/*
https://leetcode.com/problems/find-the-safest-path-in-a-grid/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        const int dx[4] = {0, 0, -1, 1};
        const int dy[4] = {-1, 1, 0, 0};

        queue<pair<int,int>> q;
        // Thieves marks as 0 and empty as -1 as unvisited
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if (grid[i][j] == 1) {
                    q.push({i,j});
                    grid[i][j] = 0;
                } else {
                    grid[i][j] = -1;
                }
            }
        }

        // Travel from thieves cell and cal all distance from that cell
        // to the surrounding, store the minimum dist to a thieve using BFS
        while (!q.empty()) {
            auto [u, v] = q.front();
            q.pop();
            for (int i = 0; i < 4; ++i) {
                int x = u + dx[i];
                int y = v + dy[i];
                if (x < 0 || x == n || y < 0 || y == n || grid[x][y] != -1)
                    continue;
                grid[x][y] = grid[u][v]+1;
                q.push({x,y});
            }
        }

        // Dijkstra
        // heap contains [max_safeness, x, y]
        priority_queue<tuple<int,int,int>> heap;
        vector<vector<int>> dist(n, vector<int>(n, -1e9));
        dist[0][0] = grid[0][0];
        heap.push({dist[0][0], 0, 0});

        while (!heap.empty()) {
            auto [d, u, v] = heap.top();
            heap.pop();

            if (u == n-1 && v == n-1) // destination
                return d;

            if (d != dist[u][v]) continue;

            for (int i = 0; i < 4; ++i) {
                int x = u+dx[i];
                int y = v+dy[i];
                if (x < 0 || x == n || y < 0 || y == n)
                    continue;
                
                if (dist[x][y] < min(d, grid[x][y])) {
                    dist[x][y] = min(d, grid[x][y]);
                    heap.push({dist[x][y],x,y});
                }
            }
        }
        return -1;
    }
};
