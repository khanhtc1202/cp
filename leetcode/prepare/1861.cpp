/*
https://leetcode.com/problems/rotating-the-box/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int n = box.size(), m = box[0].size();
        vector<vector<char>> ans(m, vector<char>(n, '.'));
        for (int i = 0; i < n; ++i) {
            int floor = m - 1;
            for (int j = m-1; j >= 0; --j) {
                // Found stone
                if (box[i][j] == '#') {
                    ans[floor][n-i-1] = '#'; // stone dropped
                    floor--; // Update floor as next possible to drop stone to
                }
                // Found obstacle -> reset floor to above it
                if (box[i][j] == '*') {
                    ans[j][n-i-1] = '*';
                    floor = j-1;
                }
            }
        }
        return ans;
    }
};
