/*
https://leetcode.com/problems/longest-ideal-subsequence/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestIdealString(string s, int k) {
        vector<int> maxdp(26, 0);
        for (auto c: s) {
            int curr = 0;
            for (int i = 0; i < 26; i++) {
                if (abs(c - 'a' - i) > k) continue;
                
                curr = max(curr, maxdp[i] + 1);
            }
            maxdp[c-'a'] = max(curr, maxdp[c-'a']);
        }
        return *max_element(maxdp.begin(), maxdp.end());
    }
};
