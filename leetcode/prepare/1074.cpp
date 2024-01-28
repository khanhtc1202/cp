/*
https://leetcode.com/problems/number-of-submatrices-that-sum-to-target/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        for (int r = 0; r < m; ++r) {
            for (int c = 1; c < n; ++c) {
                matrix[r][c] += matrix[r][c-1];
            }
        }

        int cnt = 0;
        for (int c1 = 0; c1 < n; ++c1) {
            for (int c2 = c1; c2 < n; ++c2) {
                unordered_map<int,int> psum;
                psum[0] = 1;

                int sum = 0;
                for (int r = 0; r < m; ++r) {
                    sum += matrix[r][c2] - (c1 > 0 ? matrix[r][c1-1] : 0);
                    cnt += psum[sum - target];
                    psum[sum]++;
                }
            }
        }
        return cnt;
    }
};
