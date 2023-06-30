/*
https://leetcode.com/problems/last-day-where-you-can-still-cross/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        vector<int> dx = {1, -1, 0, 0};
        vector<int> dy = {0, 0, 1, -1};
        auto bfs = [&](int day) -> bool {
            vector<vector<int>> grid(row, vector<int>(col, 0));
            for (int i = 0; i < day; i++) {
                grid[cells[i][0]-1][cells[i][1]-1] = 1;
            }

            queue<pair<int,int>> q;
            for (int i = 0; i < col; i++) {
                if (grid[0][i] == 0) {
                    q.push({0, i});
                    grid[0][i] = -1; // visited
                }
            }

            while (!q.empty()) {
                auto [r, c] = q.front(); q.pop();
                if (r == row - 1) return true; // can touch last row

                for (int i = 0; i < 4; i++) {
                    int _r = r + dx[i], _c = c + dy[i];
                    if (_r < 0 || _r >= row || _c < 0 || _c >= col) continue;
                    if (grid[_r][_c] != 0) continue;

                    grid[_r][_c] = -1;
                    q.push({_r, _c});
                }
            }
            return false;
        };

        int left = 1, right = row*col;
        while (left < right) {
            int mid = right - (right - left) / 2;
            if (bfs(mid)) {
                left = mid;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
};
