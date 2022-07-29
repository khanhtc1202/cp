#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        vector<bool> dp(s.size()+1, false);
        dp[0] = true;
        string curr;
        for (int i = 1; i <= s.size(); i++) {
            curr = s.substr(0, i);
            for (auto word: wordDict) {
                int idx = i - word.size();
                if (idx >= 0 && curr.substr(idx, word.size()) == word)
                    dp[i] = dp[i] || dp[i-word.size()];
            }
        }
        return dp[s.size()];
    }
};
