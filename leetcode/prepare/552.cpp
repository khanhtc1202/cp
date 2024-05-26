/*
https://leetcode.com/problems/student-attendance-record-ii/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int _checkRecord(int n) {
        int mod = 1e9+7;

        int dp[n+1][2][3];
        memset(dp, 0, sizeof(int) * 6 * (n+1));
        dp[0][0][0] = 1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 3; k++) {
                    if (!dp[i][j][k]) continue;

                    if (j < 1) (dp[i+1][j+1][0] += dp[i][j][k]) %= mod;
                    if (k < 2) (dp[i+1][j][k+1] += dp[i][j][k]) %= mod;
                    (dp[i+1][j][0] += dp[i][j][k]) %= mod;
                }
            }
        }

        int ans = 0;
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 3; j++)
                (ans += dp[n][i][j]) %= mod;

        return ans;
    }

    int checkRecord(int n) {
        int mod = 1e9+7;
        
        vector<vector<int>> dp(2, vector<int>(3, 0));
        dp[0][0] = 1;
        
        for (int i = 0; i < n; i++) {
            vector<vector<int>> nxt(2, vector<int>(3, 0));
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k < 3; k++) {
                    if (!dp[j][k]) continue;

                    if (j < 1) (nxt[j+1][0] += dp[j][k]) %= mod;
                    if (k < 2) (nxt[j][k+1] += dp[j][k]) %= mod;
                    (nxt[j][0] += dp[j][k]) %= mod;
                }
            }
            swap(dp, nxt);
        }

        int ans = 0;
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 3; j++)
                (ans += dp[i][j]) %= mod;

        return ans;
    }
};
