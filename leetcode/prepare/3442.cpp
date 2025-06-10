/*
https://leetcode.com/problems/maximum-difference-between-even-and-odd-frequency-i/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDifference(string s) {
        vector<int> freq(26, 0);
        for (char c: s) freq[c-'a']++;
        int max_odd = 0, min_even = INT_MAX;
        for (int i = 0; i < 26; ++i) {
            if (freq[i] == 0) continue;
            if (freq[i] % 2) max_odd = max(max_odd, freq[i]);
            else min_even = min(min_even, freq[i]);
        }
        return max_odd - min_even;
    }
};
