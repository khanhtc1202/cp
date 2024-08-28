/*
https://leetcode.com/problems/count-sub-islands/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int r, c;
    const int d[5] = {0, 1, 0, -1, 0};
    inline bool outside(int i, int j) {
        return i < 0 || i >= r || j < 0 || j >= c;
    }

    inline bool bfs(int i, int j, int mark, vector<vector<int>>& grid1,
             vector<vector<int>>& grid2) {
        if (grid1[i][j] != 1) return 0;

        queue<pair<short, short>> q;
        q.emplace(i, j);
        bool isSub = 1;
        grid2[i][j] = mark; // mark as visited
        while (!q.empty()) {
            auto [k, l] = q.front();
            q.pop();

            for (int a = 0; a < 4; a++) {
                int s = k + d[a], t = l + d[a + 1];
                if (outside(s, t) || grid2[s][t] != 1)
                    continue;

                // If this part of grid2 island doesn't match grid1
                if (grid1[s][t] != 1)
                    isSub = 0;

                // add to queue & mark as visited
                q.emplace(s, t);
                grid2[s][t] = mark;
            }
        }
        return isSub;
    }

    int countSubIslands(vector<vector<int>>& grid1,
                        vector<vector<int>>& grid2) {
        r = grid1.size(), c = grid1[0].size();
        int cnt = 0, mark = 2;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                if (grid2[i][j] == 1)
                    cnt += bfs(i, j, mark++, grid1, grid2);
            }
        }
        return cnt;
    }
};
