/*
https://leetcode.com/problems/total-characters-in-string-after-transformations-i/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
    static constexpr int mod = 1e9+7;
public:
    int lengthAfterTransformations(string s, int t) {
        vector<int> cnt(26, 0);
        for (char c: s)
            ++cnt[c-'a'];

        // simulate t times
        for (int r = 0; r < t; ++r) {
            vector<int> next(26);
            next[0] = cnt[25];
            next[1] = (cnt[25]+cnt[0]) % mod;
            for (int i = 2; i < 26; ++i) {
                next[i] = cnt[i-1];
            }
            cnt = move(next);
        }

        int ans = 0;
        for (int i = 0; i < 26; ++i) {
            (ans += cnt[i]) %= mod;
        }
        return ans;
    }
};
