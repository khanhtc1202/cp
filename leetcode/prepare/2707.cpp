/*
https://leetcode.com/problems/extra-characters-in-a-string/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.size();
        unordered_set<string> dict(dictionary.begin(), dictionary.end());
        vector<int> dp(n+1, 0);

        for (int start = n-1; start >= 0; --start) {
            // init the char at index start as an extra char
            dp[start] = dp[start+1] + 1;

            for (int end = start; end < n; ++end) {
                string curr = s.substr(start, end - start + 1);
                if (dict.count(curr)) {
                    // string [start, end] found in dict so not contribute
                    // any extra chars to the dp[start]
                    dp[start] = min(dp[start], dp[end+1]);
                }
            }
        }
        return dp[0];
    }
};
