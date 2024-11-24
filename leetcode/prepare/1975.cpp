/*
https://leetcode.com/problems/maximum-matrix-sum/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
        long long ans = 0;
        int smallest = INT_MAX, cnt_neg = 0;
        for (int i = 0; i < matrix.size(); ++i) {
            for (int j = 0; j < matrix[0].size(); ++j) {
                int x = matrix[i][j];
                if (x < 0) cnt_neg++;
                ans += abs(x);
                smallest = min(smallest, abs(x));
            }
        }
        if (cnt_neg % 2) ans -= (2*smallest);
        return ans;
    }
};
