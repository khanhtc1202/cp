/*
https://leetcode.com/problems/grid-game/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
using ll = long long;
public:
    long long gridGame(vector<vector<int>>& grid) {
        ll firstRowSum = accumulate(grid[0].begin(), grid[0].end(), 0LL);
        ll secondRowSum = 0;
        ll minSum = LONG_LONG_MAX;
        for (int turnIndex = 0; turnIndex < grid[0].size(); ++turnIndex) {
            firstRowSum -= grid[0][turnIndex]; // sum of [turnIndex, end of first row] (possible for robot2)
            // max(firstRowSum, secondRowSum) means the max possible robot2 get since robot1 path
            // split the matrix to 2 paths with 0-cells line as spliter
            minSum = min(minSum, max(firstRowSum, secondRowSum));
            secondRowSum += grid[1][turnIndex]; // update secondRowSum with value at cell that possible to get
        }
        return minSum;
    }
};
