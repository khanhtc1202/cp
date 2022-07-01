#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numIslands(vector<vector<char>>& grid) {
        vector<int> offset = {0, 1, 0, -1, 0};
        int n = grid.size(), m = grid[0].size();
        int island = 0;

        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    island++;
                    grid[i][j] = '0';

                    queue<pair<int, int>> todo;
                    todo.push({i, j});
                    while (!todo.empty()) {
                        pair<int, int> cur = todo.front();
                        todo.pop();
                        for (int k = 0; k < 4; k++) {
                            int r = cur.first + offset[k];
                            int c = cur.second + offset[k+1];
                            if (r < 0 || r >= n || c < 0 || c >= m)
                                continue;
                            if (grid[r][c] == '0')
                                continue;
                            grid[r][c] = '0';
                            todo.push({r,c});
                        }
                    }
                }
            }

        return island;
    }

    int numIslandsDFS(vector<vector<char>>& grid) {
        int n = grid.size(), m = grid[0].size();
        int island = 0;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == '1') {
                    island++;
                    eraseIslandDFS(grid, i, j);
                }
            }

        return island;
    }

private:
    void eraseIslandDFS(vector<vector<char>>& grid, int i, int j) {
        int n = grid.size(), m = grid[0].size();
        if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == '0')
            return;

        grid[i][j] = '0';
        eraseIslandDFS(grid, i - 1, j);
        eraseIslandDFS(grid, i + 1, j);
        eraseIslandDFS(grid, i, j - 1);
        eraseIslandDFS(grid, i, j + 1);
    }
};
