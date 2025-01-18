/*
https://leetcode.com/problems/minimum-cost-to-make-at-least-one-valid-path-in-a-grid/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCost(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();

        auto isValid = [&](int x, int y) -> bool {
            return !(x < 0 || x >= rows || y < 0 || y >= cols);
        };

        vector<vector<int>> minCost(rows, vector<int>(cols, INT_MAX));
        // 0-1 BFS using deque, 0 to front, 1 to back
        deque<pair<int,int>> dq;
        dq.push_front({0,0});
        minCost[0][0] = 0;

        // direction right, left, down, up <=> 1,2,3,4
        vector<int> dx = {0,0,1,-1};
        vector<int> dy = {1,-1,0,0};
        while (!dq.empty()) {
            auto [row, col] = dq.front();
            dq.pop_front();

            for (int i = 0; i < 4; ++i) {
                int nextRow = row + dx[i];
                int nextCol = col + dy[i];
                // cost = 0 if current grid point to next grid, else = 1
                int cost = (grid[row][col] != (i+1)) ? 1 : 0;

                if (isValid(nextRow, nextCol) && 
                    minCost[row][col] + cost < minCost[nextRow][nextCol]) {
                        minCost[nextRow][nextCol] = minCost[row][col] + cost; // update cost
                        if (cost == 1) {
                            dq.push_back({nextRow, nextCol});
                        } else {
                            dq.push_front({nextRow, nextCol});
                        }
                    }
            }
        }
        return minCost[rows-1][cols-1];
    }
};
