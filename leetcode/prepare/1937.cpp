/*
https://leetcode.com/problems/maximum-number-of-points-with-cost/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int rows = points.size(), cols = points[0].size();
        // This will store cal row max
        vector<long long> previousRow(cols);

        // first row pass
        for (int col = 0; col < cols; ++col) {
            previousRow[col] = points[0][col];
        }

        // process rows
        for (int row = 0; row < rows-1; ++row) {
            vector<long long> leftMax(cols);
            vector<long long> rightMax(cols);
            vector<long long> currentRow(cols);

            // cal leftMax, which contains max possible value
            // we can have at each [i] by compare
            // - previousRow[i] (direct choice, no penalty)
            // - leftMax[i-1] - 1 (best of the (i-1) and minus 1 for penalty)
            leftMax[0] = previousRow[0];
            for (int col = 1; col < cols; ++col) {
                leftMax[col] = max(leftMax[col-1]-1, previousRow[col]);
            }

            // cal rightMax, same idea with leftMax
            rightMax[cols-1] = previousRow[cols-1];
            for (int col = cols-2; col >= 0; --col) {
                rightMax[col] = max(rightMax[col+1]-1, previousRow[col]);
            }

            // cal the current row max points
            for (int col = 0; col < cols; ++col) {
                currentRow[col] =
                    points[row + 1][col] + max(leftMax[col], rightMax[col]);
            }

            // Update previousRow
            previousRow = currentRow;
        }

        return *max_element(previousRow.begin(), previousRow.end());
    }
};
