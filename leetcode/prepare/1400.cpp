/*
https://leetcode.com/problems/construct-k-palindrome-strings/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canConstruct(string s, int k) {
        int n = s.size();
        if (n < k) return false;
        vector<int> cnt(26, 0);
        for (char c: s) ++cnt[c-'a'];
        int odd = 0;
        for (int i = 0; i < 26; ++i) {
            if (cnt[i] % 2) ++odd;
        }
        // There will be at least odd single char as "x" string that palindrome
        //  must be created if using all of s characters
        if (odd > k) return false;
        return true;
    }
};
