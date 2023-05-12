/*
https://leetcode.com/problems/shortest-common-supersequence/description/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size(), m = str2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));

        for (int i = 0; i <= n; i++)
            for (int j = 0; j <= m; j++) {
                if (i == 0 || j == 0) dp[i][j] = max(i, j);
                else {
                    dp[i][j] = min({dp[i-1][j-1]+2, dp[i-1][j]+1, dp[i][j-1]+1});
                    if (str1[i-1] == str2[j-1])
                        dp[i][j] = min(dp[i][j], dp[i-1][j-1] + 1);
                }
            }

        string ans = "";
        while(n > 0 && m > 0) {
            if (str1[n-1] == str2[m-1] && dp[n][m] == dp[n-1][m-1] + 1) {
                ans += str1[n-1];
                n--; m--;
            }
            else if (dp[n][m] == dp[n-1][m] + 1) {
                ans += str1[--n];
            }
            else if (dp[n][m] == dp[n][m-1] + 1) {
                ans += str2[--m];
            }
            else {
                ans += str1[--n];
                ans += str2[--m];
            }
        }
        while (n > 0) ans += str1[--n];
        while (m > 0) ans += str2[--m];
        
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
