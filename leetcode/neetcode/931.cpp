/*
https://leetcode.com/problems/minimum-falling-path-sum/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int sz = matrix.size();
        vector<int> dp(sz, 0);
        for (int i = 0; i < sz; i++) dp[i] = matrix[0][i];

        for (int i = 1; i < sz; i++) {
            vector<int> tmp(sz, 0);
            for (int j = 0; j < sz; j++) {
                int t1 = 1e4, t3 = 1e4;
                if (j-1 >= 0) t1 = dp[j-1] + matrix[i][j];
                if (j+1 < sz) t3 = dp[j+1] + matrix[i][j];
                int t2 = dp[j] + matrix[i][j];
                tmp[j] = min(min(t1, t2), t3);
            }
            dp = tmp;
        }
        return *min_element(dp.begin(), dp.end());
    }
};
