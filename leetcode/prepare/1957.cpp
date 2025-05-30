/*
https://leetcode.com/problems/delete-characters-to-make-fancy-string/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string makeFancyString(string s) {
        if (s.size() < 3) return s;
        string ans = "";
        ans += s[0];
        ans += s[1];
        for (int i = 2; i < s.size(); ++i) {
            if (s[i] == s[i-1] && s[i] == s[i-2]) {
                continue;
            }
            ans += s[i];
        }
        return ans;
    }
};
