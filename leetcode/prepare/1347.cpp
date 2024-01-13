/*
https://leetcode.com/problems/minimum-number-of-steps-to-make-two-strings-anagram/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSteps(string s, string t) {
        int cnts[26] = {0}, cntt[26] = {0};
        for (auto c: s) ++cnts[c-'a'];
        int ans = 0;
        for (auto c: t) if (++cntt[c-'a'] > cnts[c-'a']) ++ans;
        return ans;
    }

    int minStepsOnePass(string s, string t) {
        int cnt[26] = {0};
        for (int i = 0; i < s.size(); ++i) {
            ++cnt[s[i]-'a'];
            --cnt[t[i]-'a'];
        }
        int ans = 0;
        for (int i = 0; i < 26; ++i)
            if (cnt[i] > 0) ans += cnt[i];
        return ans;
    }
};
