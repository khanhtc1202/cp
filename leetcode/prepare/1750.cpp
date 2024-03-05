/*
https://leetcode.com/problems/minimum-length-of-string-after-deleting-similar-ends/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumLength(string s) {
        int l = 0, r = s.size() - 1;
        while (l < r) {
            if (s[l] != s[r]) break;
            char c = s[l];
            while (l < s.size() && s[l] == c) ++l;
            while (l < r && s[r] == c) --r;
        }
        return r-l+1;
    }
};
