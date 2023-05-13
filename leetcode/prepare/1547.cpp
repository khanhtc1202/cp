/*
https://leetcode.com/problems/minimum-cost-to-cut-a-stick/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        cuts.push_back(0); cuts.push_back(n);
        sort(cuts.begin(), cuts.end());

        int sz = cuts.size();
        int dp[103][103]{};

        for (int len = 2; len < sz; len++) {
            for (int i = 0, j = i+len; i + len < sz; i++, j++) {
                dp[i][j] = INT_MAX;
                for (int k = i+1; k < j; k++) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + cuts[j] - cuts[i]);
                }
            }
        }
        return dp[0][sz-1];
    }

    int minCostOp(int n, vector<int>& cuts) {
        cuts.push_back(0); cuts.push_back(n);
        sort(cuts.begin(), cuts.end());

        int sz = cuts.size();
        int dp[103][103]{};

        for (int i = sz-1; i >= 0; i--) {
            for (int j = i+2; j < sz; j++) {
                dp[i][j] = INT_MAX;
                for (int k = i+1; k < j; k++) {
                    dp[i][j] = min(dp[i][j], dp[i][k] + dp[k][j] + cuts[j] - cuts[i]);
                }
            }
        }

        return dp[0][sz-1];
    }
};
