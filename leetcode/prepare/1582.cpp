/*
https://leetcode.com/problems/special-positions-in-a-binary-matrix/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        vector<int> row(n, 0), col(m, 0);

        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (mat[i][j] == 1)
                    row[i]++, col[j]++;
            }
        }

        int ans = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j)
                if (mat[i][j] == 1 && row[i] == 1 && col[j] == 1)
                    ans++;
        }
        return ans;
    }
};
