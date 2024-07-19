/*
https://leetcode.com/problems/lucky-numbers-in-a-matrix/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int N = matrix.size(), M = matrix[0].size();

        int rMinMax = INT_MIN;
        for (int i = 0; i < N; ++i) {
            int rMin = INT_MAX;
            for (int j = 0; j < M; ++j) {
                rMin = min(rMin, matrix[i][j]);
            }
            rMinMax = max(rMinMax, rMin);
        } // rMinMax is max of all row min;

        int cMaxMin = INT_MAX;
        for (int j = 0; j < M; ++j) {
            int cMax = INT_MIN;
            for (int i = 0; i < N; ++i) {
                cMax = max(cMax, matrix[i][j]);
            }
            cMaxMin = min(cMaxMin, cMax);
        } // cMaxMin is min of all column max;

        if (cMaxMin == rMinMax) return { cMaxMin };
        return {};
    }
};
