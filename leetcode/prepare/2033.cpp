/*
https://leetcode.com/problems/minimum-operations-to-make-a-uni-value-grid/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<vector<int>>& grid, int x) {
        vector<int> numsArray;
        for (int row = 0; row < grid.size(); row++) {
            for (int col = 0; col < grid[0].size(); col++) {
                if (grid[row][col] % x != grid[0][0] % x) return -1;
                numsArray.push_back(grid[row][col]);
            }
        }

        int length = numsArray.size();
        nth_element(numsArray.begin(), numsArray.begin() + length / 2,
                    numsArray.end());

        // get median
        int median = numsArray[length / 2];

        int result = 0;
        for (int number : numsArray) {
            // Add the number of operations required to make the current number
            // equal to finalCommonNumber
            result += abs(median - number) / x;
        }

        return result;
    }
};
