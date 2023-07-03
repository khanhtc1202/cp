/*
https://leetcode.com/problems/zigzag-conversion/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        if (numRows == 1) return s;

        int n = s.size();
        int sections = ceil(n / (2* numRows - 2.0));
        int numCols = sections * (numRows - 1);

        vector<vector<char>> matrix(numRows, vector<char>(numCols, ' '));
        int currRow = 0, currCol = 0;
        int idx = 0;

        while (idx < n) {
            while (currRow < numRows && idx < n) {
                matrix[currRow][currCol] = s[idx];
                currRow++;
                idx++;
            }

            // Move diagonally from the first next col
            currRow -= 2; // one passed from numRows cond
            currCol++;

            while (currRow > 0 && currCol < numCols && idx < n) {
                matrix[currRow][currCol] = s[idx];
                currRow--;
                currCol++;
                idx++;
            }
        }

        string ans;
        for (auto& row: matrix) {
            for (auto& c: row) {
                if (c == ' ') continue;
                ans += c;
            }
        }
        return ans;
    }
};
