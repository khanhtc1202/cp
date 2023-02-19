/*
Problem desc: https://leetcode.com/problems/longest-nice-substring/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestNiceSubstring(string s) {
        if (s.size() < 2) return "";
        unordered_set<char>dict(s.begin(), s.end());
        for (int i = 0; i < s.size(); i++) {
            if (dict.find((char)toupper(s[i])) == dict.end() || dict.find((char)tolower(s[i])) == dict.end()) {
                string s1 = longestNiceSubstring(s.substr(0,i));
                string s2 = longestNiceSubstring(s.substr(i+1));
                return s1.size() >= s2.size() ? s1 : s2;
            }
        }
        return s;
    }
};
