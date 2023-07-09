/*
https://leetcode.com/problems/longest-substring-with-at-most-k-distinct-characters/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstringKDistinct(string s, int k) {
        int cnt[128] = {}, dist = 0, l = 0, r = 0;
        while (r < s.size()) {
            dist += cnt[s[r++]]++ == 0;
            if (dist > k) dist -= --cnt[s[l++]] == 0;
        }
        return r - l;
    }
};
