/*
https://leetcode.com/problems/knight-probability-in-chessboard/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double knightProbability(int n, int k, int row, int column) {
        if (k == 0) return 1;

        vector<pair<int,int>> moves = {{1, 2}, {2, 1}, {-1, 2}, {-2, 1}, {1, -2}, {2, -1}, {-1, -2}, {-2, -1}};
        vector<vector<double>> dp(n, vector<double>(n, 1));
        vector<vector<double>> new_dp;

        for (int turn = 1; turn <= k; ++turn) {
            new_dp.assign(n, vector<double>(n, 0));
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    double prob = 0;
                    for (auto [x, y]: moves) {
                        int r = i + x, c = j + y;
                        if (r < 0 || r >= n || c < 0 || c >= n) continue;

                        // The probability which the current (i, j) jump
                        // to get (r, c) is 0.125, thus it contributes
                        // 0.125 * probability at (r, c) to (i, j) at which
                        // after jump we still on board.
                        prob += 0.125 * dp[r][c];
                    }
                    new_dp[i][j] = prob;
                }
            }
            swap(dp, new_dp);
        }
        return dp[row][column];
    }
};
