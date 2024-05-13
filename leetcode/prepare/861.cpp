/*
https://leetcode.com/problems/score-after-flipping-matrix/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int matrixScore(vector<vector<int>>& grid) {
        const int r= grid.size(), c= grid[0].size();
        int sum = 0;
        for (int j=0; j<c; j++) {
            int cnt1= 0;
            int b=1<<(c-1-j);
            for (int i = 0; i < r; i++) {
                bool one = (grid[i][0] == 0) ^ (grid[i][j] == 1);
                cnt1+=one;
            }
            // Flip col or not based on the number of 1
            sum += max(r-cnt1, cnt1)*b;
        }
        return sum;
    }
};
