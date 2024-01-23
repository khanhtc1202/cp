/*
https://leetcode.com/problems/maximum-length-of-a-concatenated-string-with-unique-characters/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxLength(vector<string>& arr) {
        vector<int> dp = {0};
        int res = 0;
        for (const string& s: arr) {
            int mask = 0, dup = 0;
            for (char c: s) {
                dup |= mask & (1 << (c-'a'));
                mask |= 1 << (c-'a');
            }
            if (dup > 0) continue; // s contains dup

            for (int i = dp.size()-1; i >= 0; --i) {
                // there are dup between mask and dp[i]
                if ((dp[i] & mask) > 0) continue;

                dp.push_back(dp[i] | mask);
                res = max(res, __builtin_popcount(dp[i] | mask));
            }
        }
        return res;
    }
};
