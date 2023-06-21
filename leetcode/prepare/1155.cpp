/*
https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numRollsToTarget(int n, int k, int target) {
        int mod = 1e9+7;
        vector<vector<int>> dp(n+1, vector<int>(target+1, 0));
        dp[0][0] = 1;
        
        for (int diceNo = 1; diceNo <= n; diceNo++) {
            for (int currSum = 1; currSum <= target; currSum++) {
                int ways = 0;
                for (int i = 1; i <= min(k, currSum); i++) {
                    (ways += dp[diceNo-1][currSum-i]) %= mod;
                }
                dp[diceNo][currSum] = ways;
            }
        }
        return dp[n][target];
    }

    int numRoolsToTargetMemOpt(int n, int k, int target) {
        int mod = 1e9+7;
        vector<int> dp(target+1, 0);
        dp[0] = 1;

        for (int roll = 1; roll <= n; roll++) {
            vector<int> newDp(target+1, 0);
            for (int currSum = 1; currSum <= target; currSum++) {
                for (int i = 1; i <= min(k, currSum); i++) {
                    (newDp[currSum] += dp[currSum-i]) %= mod;
                }
            }
            dp = newDp;
        }
        return dp[target];
    }
};
