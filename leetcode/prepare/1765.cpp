/*
https://leetcode.com/problems/map-of-highest-peak/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> highestPeak(vector<vector<int>>& isWater) {
        int n = isWater.size(), m = isWater[0].size();
        vector<vector<int>> height(n, vector<int>(m, -1));

        queue<pair<int,int>> q;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (isWater[i][j] == 1)
                    q.push({i, j}), height[i][j] = 0;
            }
        }

        auto invalid = [&](int x, int y) -> bool {
            return (x < 0 || x >= n || y < 0 || y >= m);
        };

        vector<int> di = {1, -1, 0, 0};
        vector<int> dj = {0, 0, -1, 1};

        while (!q.empty()) {
            auto [i, j] = q.front(); q.pop();
            for (int k = 0; k < 4; ++k) {
                int ni = i + di[k], nj = j + dj[k];
                // Invalid cell or visited.
                if (invalid(ni, nj) || height[ni][nj] != -1) continue;

                height[ni][nj] = height[i][j] + 1;
                q.push({ni, nj});
            }
        }
        return height;
    }
};
