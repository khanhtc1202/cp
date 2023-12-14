/*
https://leetcode.com/problems/difference-between-ones-and-zeros-in-row-and-column/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> onesMinusZeros(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<int> val_x(n, 0), val_y(m, 0);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                val_x[i] += grid[i][j];
                val_y[j] += grid[i][j];
            }
        }
        vector<vector<int>> diff(n, vector<int>(m, 0));
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                diff[i][j] = 2*(val_x[i] + val_y[j]) - n - m;
            }
        }
        return diff;
    }
};
