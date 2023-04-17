/*
https://leetcode.com/problems/max-sum-of-rectangle-no-larger-than-k/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int n = matrix.size(), m = matrix[0].size();
        vector<vector<int>> prefix(n, vector<int>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                prefix[i][j] = i == 0 ? matrix[i][j] : prefix[i-1][j] + matrix[i][j];
            }
        }

        int ans = -1e6;
        for (int i = 0; i < n; i++) {
            for (int j = i; j < n; j++) {
                set<int> _set; _set.insert(0);
                int pref = 0;
                for (int x = 0; x < m; x++) {
                    int current = prefix[j][x] - prefix[i][x] + matrix[i][x];
                    pref += current;
                    set<int>::iterator it = _set.lower_bound(pref - k);
                    if (it != _set.end()) {
                        ans = max(ans, pref - *it);
                    }
                    _set.insert(pref);
                }
                if (ans == k)
                    return ans;
            }
        }
        return ans;
    }
};
