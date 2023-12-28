/*
https://leetcode.com/problems/string-compression-ii/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
    int getLen(int cnt) {
        return cnt == 1 ? 1 : (cnt < 10 ? 2 : (cnt < 100 ? 3 : 4));
    }

public:
    int getLengthOfOptimalCompression(string s, int k) {
        int n = s.size();
        // dp[i][j] is min len of encodind string for s[i:] string
        // with at max j char removals.
        int dp[n+1][k+1];

        for (int i = n; i >= 0; --i) {
            for (int j = 0; j <= k; ++j) {
                if (i == n) {
                    dp[n][j] = 0; // init
                    continue;
                }

                // If we delete the i-th char
                dp[i][j] = j > 0 ? dp[i+1][j-1] : INT_MAX;
                // or we keep it
                // then we try encode the group start with this i-th char
                int max_del = j, cnt = 0;
                for (int idx = i; idx < n && max_del >= 0; ++idx) {
                    if (s[idx] == s[i]) {
                        cnt++;
                        dp[i][j] = min(dp[i][j], getLen(cnt)+dp[idx+1][max_del]);
                    } else {
                        max_del--;
                    }
                }
            }
        }
        return dp[0][k];
    }
};
