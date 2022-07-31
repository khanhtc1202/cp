#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int size = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    size = max(size, calIslandSize(grid, i, j)); 
                }
            }
        return size;
    }

    int calIslandSize(vector<vector<int>>& grid, int i, int j) {
        int size = 0;
        int n = grid.size(), m = grid[0].size();
        function<void(int, int)> eraseIsland = [&](int i, int j) -> void {
            if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == 0)
                return;
            grid[i][j] = 0; size++;
            eraseIsland(i - 1, j);
            eraseIsland(i + 1, j);
            eraseIsland(i, j - 1);
            eraseIsland(i, j + 1);
        };

        eraseIsland(i, j);
        return size;
    }
};
