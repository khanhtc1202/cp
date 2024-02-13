/*
https://leetcode.com/problems/find-first-palindromic-string-in-the-array/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string firstPalindrome(vector<string>& words) {
        for (auto& w: words) {
            if (isPalindrome(w)) return w;
        }
        return "";
    }

    bool isPalindrome(string& w) {
        for (int l = 0, r = w.size()-1; l <= r; ++l, --r) {
            if (w[l] != w[r]) return false;
        }
        return true;
    }
};
