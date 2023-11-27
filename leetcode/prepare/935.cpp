/*
https://leetcode.com/problems/knight-dialer/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int MOD = 1e9+7;
    vector<vector<int>> memo;
    vector<vector<int>> jumps = {
        {4, 6},
        {6, 8},
        {7, 9},
        {4, 8},
        {3, 9, 0},
        {},
        {1, 7, 0},
        {2, 6},
        {1, 3},
        {2, 4}
    };

    int dp(int remain, int square) {
        // No more next jump
        if (remain == 0) return 1;

        // Memorization
        if (memo[remain][square] != 0)
            return memo[remain][square];

        int ans = 0;
        for (int nextSquare: jumps[square]) {
            (ans += dp(remain - 1, nextSquare)) %= MOD;
        }
        
        // Memo for next time visit
        memo[remain][square] = ans;
        return ans;
    }

    int knightDialer(int n) {
        memo = vector(n+1, vector(10, 0));
        int ans = 0;
        for (int square = 0; square < 10; ++square) {
            (ans += dp(n-1, square)) %= MOD;
        }
        return ans;
    }
};
