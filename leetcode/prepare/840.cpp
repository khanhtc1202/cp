/*
https://leetcode.com/problems/magic-squares-in-grid/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
    static bool isMagic(int i, int j, vector<vector<int>>& grid) {
        bitset<10> once; // bitset of size 10 to track digits 1-9
        int rowSum[3] = {0}, colSum[3] = {0};

        for (int a = i-1; a <= i+1; ++a) {
            for (int b = j-1; b <= j+1; ++b) {
                int x = grid[a][b];
                if (x == 0 || x > 9) return 0;

                rowSum[a-i+1] += x;
                colSum[b-j+1] += x;
                once.flip(x);
            }
        }
        // numbers 1-9 are present exactly once
        if (once.count() != 9) return 0;

        // all sum col and row must be 15
        if (!all_of(rowSum, rowSum+3, [](int sum) { return sum == 15; })) return 0;
        if (!all_of(colSum, colSum+3, [](int sum) { return sum == 15; })) return 0;

        // 2 diagonals must be 15
        return (grid[i-1][j-1]+grid[i+1][j+1] == 10) && (grid[i+1][j-1]+grid[i-1][j+1] == 10);
    }
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        const int r = grid.size(), c = grid[0].size();
        if (r < 3 || c < 3) return 0;

        int cnt = 0;
        for (int i = 1; i < r-1; ++i) {
            for (int j = 1; j < c-1; ++j) {
                // the center of magic square must be 5
                if (grid[i][j] == 5) {
                    cnt += isMagic(i, j, grid);
                }
            }
        }
        return cnt;
    }
};
