/*
https://leetcode.com/problems/spiral-matrix-iii/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int rStart, int cStart) {
        vector<vector<int>> ans;

        int up = rStart, down = rStart+1;
        int left = cStart-1, right = cStart+1;

        while (ans.size() < rows*cols) {
            if (up >= 0) {
                for (int col = max(0, left+1); col <= right; col++) {
                    if (col >= cols) break;
                    ans.push_back({up, col});
                }
            }

            if (right < cols) {
                for (int row = max(0, up+1); row <= down; row++) {
                    if (row >= rows) break;
                    ans.push_back({row, right});
                }
            }

            if (down < rows) {
                for (int col = min(cols-1, right-1); col >= left; col--) {
                    if (col < 0) break;
                    ans.push_back({down, col});
                }
            }

            if (left >= 0) {
                for (int row = min(rows-1, down-1); row >= up; row--) {
                    if (row < 0) break;
                    ans.push_back({row, left});
                }
            }

            up--; down++;
            left--; right++;
        }
        return ans;
    }
};
