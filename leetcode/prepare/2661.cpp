/*
https://leetcode.com/problems/first-completely-painted-row-or-column/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstCompleteIndex(vector<int>& arr, vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<pair<int,int>> hm(m*n+1);
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                hm[mat[i][j]] = make_pair(i, j);
            }
        }
        vector<int> row(n, 0), col(m, 0);
        for (int i = 0; i < arr.size(); ++i) {
            auto [r,c] = hm[arr[i]];
            if (++row[r] == m || ++col[c] == n) return i;
        }
        return 0; // never
    }
};
