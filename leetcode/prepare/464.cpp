/*
Problem desc: https://leetcode.com/problems/can-i-win/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canIWin(int maxChoosableInteger, int desiredTotal) {
        int posTotal = (1 + maxChoosableInteger) * maxChoosableInteger / 2;
        if (posTotal < desiredTotal) return false;

        vector<int> dp(1 << maxChoosableInteger, -1);
        function<bool(int, int)> canWin = [&](int mask, int score) -> bool {
            if (dp[mask] != -1) return dp[mask];
            for (int i = 0; i < maxChoosableInteger; i++) {
                if (mask >> i & 1) continue;
                if (score+i+1 >= desiredTotal) return dp[mask] = true;
                if (!canWin(mask ^ (1 << i), score+i+1)) return dp[mask] = true;
            }
            return dp[mask] = false;
        };

        return canWin(0, 0);
    }
};
