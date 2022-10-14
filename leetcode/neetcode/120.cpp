#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int sz = triangle.size();
        vector<int> dp;
        dp.push_back(triangle[0][0]);
        for (int i = 1; i < sz; i++) {
            vector<int> tmp(i+1, 2e6);
            for (int j = 0; j < i+1; j++) {
                int t1 = (j-1) >= 0 ? dp[j-1] + triangle[i][j] : 2e6;
                int t2 = j <= i-1 ? dp[j] + triangle[i][j] : 2e6;
                tmp[j] = min(t1, t2);
            }
            dp = tmp;
        }
        return *min_element(dp.begin(), dp.end());
    }
};
