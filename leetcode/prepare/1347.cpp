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
};
