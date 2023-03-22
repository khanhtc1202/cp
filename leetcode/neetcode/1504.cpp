/*
https://leetcode.com/problems/count-submatrices-with-all-ones/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubmat(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            vector<int> sum(m, 1);
            for (int j = i; j < n; j++) {
                int cnt = 0;
                for (int k = 0; k < m; k++) {
                    sum[k] *= mat[j][k];
                    // ans += sum[k] ? ++cnt : (cnt = 0);
                    if (sum[k]) ans += ++cnt;
                    else cnt = 0;
                }
            }
        }
        return ans;
    }
};
