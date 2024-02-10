/*
https://leetcode.com/problems/palindromic-substrings/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSubstring(string s) {
        int res = 0;
        int l, r;
        for (int i = 0; i < s.size(); i++) {
            // odd case
            l = r = i;
            while (l >= 0 && r < s.size() && s[l] == s[r]) {
                res++;
                l--; r++;
            }
            // even case
            l = i, r = i+1;
            while (l >= 0 && r < s.size() && s[l] == s[r]) {
                res++;
                l--; r++;
            }
        }
        return res;
    }
};
