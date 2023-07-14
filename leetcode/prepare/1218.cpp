/*
https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int diff) {
        unordered_map<int, int> dp;
        int ans = 0;
        for (int i = 0; i < arr.size(); ++i) {
            dp[arr[i]] = dp[arr[i] - diff] + 1;
            ans = max(ans, dp[arr[i]]);
        }
        return ans;
    }
};
