/*
https://leetcode.com/problems/minimum-number-of-days-to-disconnect-island/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int r, c;
    int d[5] = {0, 1, 0, -1, 0};

    inline bool inside(int i, int j) { return 0 <= i && i < r && 0 <= j && j < c; }

    inline void dfs(int i, int j, vector<vector<int>>& grid, bitset<30> viz[30]) {
        viz[i][j] = 1;
        for (int a = 0; a < 4; a++) {
            int s = i + d[a], t = j + d[a + 1];
            if (inside(s, t) && !viz[s][t] && grid[s][t] == 1) {
                dfs(s, t, grid, viz);
            }
        }
    }

    inline int component(vector<vector<int>>& grid) {
        int cnt = 0;
        bitset<30> viz[30] = {0};
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid[i][j] == 1 && !viz[i][j]) {
                    cnt++;
                    dfs(i, j, grid, viz);
                }
            }
        }
        return cnt;
    }

    int minDays(vector<vector<int>>& grid) {
        r = grid.size(), c = grid[0].size();
        if (r==1 && c==1 && grid[0][0]==1) return 1;// edge case
        int cnt = component(grid);
        if (cnt == 0 || cnt > 1)
            return 0;

        vector<pair<int, int>> deg2;

        bitset<30> isin[30]={0};
        for (int i = 0; i < r; i++)
            for (int j = 0; j < c; j++)
                if (grid[i][j] == 1) {
                    int cnt= 0;
                    for (int a = 0; a < 4; a++) {
                        int s = i + d[a], t = j + d[a + 1];
                        if (!inside(s, t)||grid[s][t]) cnt++;
                    }
                    if (cnt<=2) 
                        if (!isin[i][j])
                        deg2.push_back({i, j});
                    for (int a = 0; a < 4; a++) {
                        int s = i + d[a], t = j + d[a + 1];
                        if (inside(s, t) && grid[s][t] && !isin[s][t]) {
                            
                            deg2.push_back({s, t});
                            isin[s][t]=1;
                        }
                    }
                }

        for (auto [a, b]: deg2) {
            grid[a][b] = 0;
            int cnt = component(grid);
            if (cnt == 0 || cnt > 1)
                return 1;
            grid[a][b] = 1;
        }

        return 2;
    }
};
