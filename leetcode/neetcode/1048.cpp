/*
https://leetcode.com/problems/longest-string-chain/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestStrChain(vector<string>& words) {
        sort(words.begin(), words.end(), [](string& s1, string& s2) {
            return s1.size() < s2.size();
        });
        
        unordered_map<string, int> dp;
        int ans = 1;
        dp[words[0]] = 1;
        for (int i = 1; i < words.size(); i++) {
            int currLen = 1; string word = words[i];
            for (int j = 0; j < word.size(); j++) {
                string tmp = word.substr(0, j) + word.substr(j+1, word.size()+1);
                if (dp.find(tmp) != dp.end()) {
                    currLen = max(currLen, dp[tmp]+1);
                }
            }
            dp[word] = currLen;
            ans = max(ans, currLen);
        }
        return ans;
    }
};
