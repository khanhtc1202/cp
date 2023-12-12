/*
https://leetcode.com/problems/set-matrix-zeroes/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(), m = matrix[0].size();
        bool flag_x = false, flag_y = false;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (matrix[i][j] != 0) continue;
                if (j == 0) flag_x = true;
                if (i == 0) flag_y = true;
                matrix[i][0] = matrix[0][j] = 0;
            }
        }

        for (int i = 1; i < n; ++i) {
            for (int j = 1; j < m; ++j)
                if (matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] = 0;
        }
        
        // Set the border
        if (flag_x) {
            for (int i = 0; i < n; ++i)
                matrix[i][0] = 0;
        }
        if (flag_y) {
            for (int j = 0; j < m; ++j)
                matrix[0][j] = 0;
        }

        return;
    }
};
