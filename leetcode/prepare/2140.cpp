/*
https://leetcode.com/problems/solving-questions-with-brainpower/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long mostPoints(vector<vector<int>>& questions) {
        int n = questions.size();
        vector<long long> dp(n, 0);
        dp[n-1] = questions[n-1][0];

        for (int i = n-2; i >= 0; --i) {
            int point = questions[i][0];
            int skip = questions[i][1];
            dp[i] = max(dp[i+1], i+skip+1 >= n ? point : point + dp[i+skip+1]);
        }
        return dp[0];
    }
};
