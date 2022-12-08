#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        k = k % (m*n);

        vector<vector<int>> out(m, vector<int>(n, 0));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                out[(i+(j+k)/n)%m][(j+k)%n] = grid[i][j];
            }
        }
        return out;
    }
};
