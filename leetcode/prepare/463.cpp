/*
https://leetcode.com/problems/island-perimeter/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int islandPerimeter(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = 0; queue<pair<int,int>> q;
        vector<vector<int>> visited(n, vector<int>(m, 0));
        vector<int> dx = {1,-1,0,0};
        vector<int> dy = {0,0,-1,1};

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    ans += 4;
                    visited[i][j] = 1;
                    for (int k = 0; k < 4; ++k) {
                        int u = i + dx[k], v = j + dy[k];
                        if (u < 0 || u >= n || v < 0 || v >= m) continue;
                        if (grid[u][v] == 1 && visited[u][v] == 1) ans -= 2;
                    }
                }
            }
        }
        return ans;
    }

    int islandPerimeter_novisited(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int ans = 0; queue<pair<int,int>> q;
        vector<int> dx = {1,-1,0,0};
        vector<int> dy = {0,0,-1,1};

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == 1) {
                    ans += 4;
                    for (int k = 0; k < 4; ++k) {
                        int u = i + dx[k], v = j + dy[k];
                        if (u < 0 || u >= n || v < 0 || v >= m) continue;
                        if (grid[u][v] == 1) ans -= 1;
                    }
                }
            }
        }
        return ans;
    }
};
