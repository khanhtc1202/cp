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
                for (int col = left+1; col <= right; col++) {
                    if (col < 0) continue;
                    if (col >= cols) break;
                    ans.push_back({up, col});
                }
            }

            if (right < cols) {
                for (int row = up+1; row <= down; row++) {
                    if (row < 0) continue;
                    if (row >= rows) break;
                    ans.push_back({row, right});
                }
            }

            if (down < rows) {
                for (int col = right-1; col >= left; col--) {
                    if (col >= cols) continue;
                    if (col < 0) break;
                    ans.push_back({down, col});
                }
            }

            if (left >= 0) {
                for (int row = down-1; row >= up; row--) {
                    if (row >= rows) continue;
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
