/*
https://leetcode.com/problems/strange-printer/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int strangePrinter(string s) {
        if (s.empty()) return 0;
        int N = s.size();
        vector<vector<int>> dp(N, vector<int>(N));
        for (int i = 0; i < N; ++i) {
            dp[i][i] = 1;
            if (i > 0) dp[i - 1][i] = s[i - 1] == s[i] ? 1 : 2;
        }
        for (int len = 3; len <= N; ++len) {
            for (int i = 0; i + len <= N; ++i) {
                int val = len;
                for (int j = 0; j < len - 1; ++j) {
                    val = min(val, dp[i][i + j] + dp[i + j + 1][i + len - 1] - (s[i + j] == s[i + len - 1]));
                }
                dp[i][i + len - 1] = val;
            }
        } 
        return dp[0][N - 1];
    }
};

class Solution1 {
public:
    int strangePrinter(string s) {
        s = removeDuplicates(s);
        int N = s.size();
        vector<vector<int>> memo(N, vector<int>(N, -1));
        return minTurnsCal(0, N-1, s, memo);
    }
private:
    int minTurnsCal(int start, int end, string& s, vector<vector<int>>& memo) {
        // Base case
        if (start > end) return 0;
        // Met before
        if (memo[start][end] != -1) return memo[start][end];

        // Worst case init
        int minTurns = 1 + minTurnsCal(start+1, end, s, memo);
        // Opt by finding matching char (aka. "abcda" pattern)
        for (int k = start+1; k <= end; ++k) {
            if (s[k] == s[start]) {
                // Split at k to have [start, k-1] & [k+1, end]
                // since s[k] == s[start], we can print s[k] at the
                // time we print s[start] (no need to consider it in recursion call)
                int turnsWithMatch = minTurnsCal(start, k-1, s, memo) +
                                     minTurnsCal(k+1, end, s, memo);
                minTurns = min(minTurns, turnsWithMatch);
            }
        }

        // Memo and return
        return memo[start][end] = minTurns;
    }

    // Make "aaabbbaa" becomes "aba"
    string removeDuplicates(string& s) {
        string ans;
        int i = 0;
        while (i < s.size()) {
            char curr = s[i];
            ans += curr;
            while (i < s.size() && s[i] == curr) {
                ++i;
            }
        }
        return ans;
    }
};
