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

    int lengthAfterTransformations_26(string s, int t) {
        // a -> 26, ab
        // b -> 26, bc
        // ...
        // y -> 26, yz

        // z -> 1, ab
        // ab -> 24, yz
        // yz -> 1, zab
        // z -> 26, zab

        long cnts[26] = {};
        for (char c : s) ++cnts[c - 'a'];
        while (t >= 26) {
            long tmp[26] = {};
            for (int i = 0; i < 25; ++i) tmp[i + 1] += cnts[i];
            tmp[0] += cnts[25];
            tmp[1] += cnts[25];
            for (int i = 0; i < 26; ++i) {
                cnts[i] += tmp[i];
                cnts[i] %= mod;
            }
            t -= 26;
        }

        long ans = 0;
        for (int i = 0; i < 26; ++i) {
            ans += cnts[i];
            if (i + t >= 26) ans += cnts[i];
            ans %= mod;
        }
        return ans % mod;
    }
};
