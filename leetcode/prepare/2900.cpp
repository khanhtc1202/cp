/*
https://leetcode.com/problems/longest-unequal-adjacent-groups-subsequence-i/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> ans = {words[0]};
        int n = words.size();
        for (int i = 1; i < n; ++i) {
            if (groups[i] != groups[i-1]) {
                ans.emplace_back(words[i]);
            }
        }
        return ans;
    }
};
