/*
https://leetcode.com/problems/longest-substring-without-repeating-characters/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0) return 0;

        unordered_map<char, int> window;
        int max_l = 0;
        int lo = 0, hi = 0;

        while (hi < s.size()) {
            if (window.find(s[hi]) != window.end()) {
                lo = max(lo, window[s[hi]]+1);
            }
            window[s[hi]] = hi;
            max_l = max(max_l, hi - lo + 1);
            hi++;
        }
        return max_l;
    }
};
