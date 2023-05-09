/*
https://leetcode.com/problems/spiral-matrix-ii/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> ans(n, vector<int>(n, 0));
        int up = 0, down = n - 1;
        int left = 0, right = n - 1;
        int cnt = 1;
        while (up <= down && left <= right) {
            for (int col = left; col <= right; col++)
                ans[up][col] = cnt++;

            for (int row = up+1; row <= down; row++)
                ans[row][right] = cnt++;

            if (up != down) {
                for (int col = right-1; col >= left; col--)
                    ans[down][col] = cnt++;
            }

            if (left != right) {
                for (int row = down-1; row > up; row--)
                    ans[row][left] = cnt++;
            }

            left++; right--;
            up++; down--;
        }
        return ans;
    }
};
