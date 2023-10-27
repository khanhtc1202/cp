/*
https://leetcode.com/problems/longest-palindromic-substring/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        string res;
        int resLen = 0;

        int l, r;
        for (int i = 0; i < s.size(); i++) {
            // odd case
            l = i, r = i;
            while (l >= 0 && r < s.size() && s[l] == s[r]) {
                if (r-l+1 > resLen) {
                    res = s.substr(l, r-l+1);
                    resLen = r-l+1;
                }
                l--; r++;
            }
            // even case
            l = i, r = i+1;
            while (l >= 0 && r < s.size() && s[l] == s[r]) {
                if (r-l+1 > resLen) {
                    res = s.substr(l, r-l+1);
                    resLen = r-l+1;
                }
                l--; r++;
            }
        }
        return res;
    }
};
