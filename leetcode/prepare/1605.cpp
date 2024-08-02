/*
https://leetcode.com/problems/find-valid-matrix-given-row-and-column-sums/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int N = rowSum.size(), M = colSum.size();
        vector<vector<int>> ans(N, vector<int>(M, 0));

        int i = 0, j = 0;
        while (i < N && j < M) {
            ans[i][j] = min(rowSum[i], colSum[j]);
            rowSum[i] -= ans[i][j];
            colSum[j] -= ans[i][j];
            // Move curr to next row if curr row is 0 (no more possible fill)
            // otherwise, move to next column
            rowSum[i] == 0 ? i++ : j++;
        }
        return ans;
    }
};
