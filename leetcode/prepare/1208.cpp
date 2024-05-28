/*
https://leetcode.com/problems/get-equal-substrings-within-budget/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int n = s.size();
        int maxLen = 0, curr = 0, start = 0;
        for (int i = 0; i < n; ++i) {
            curr += abs(s[i]-t[i]);
            while (curr > maxCost) {
                curr -= abs(s[start]-t[start]);
                ++start;
            }
            maxLen = max(maxLen, i-start+1);
        }
        return maxLen;
    }
};
