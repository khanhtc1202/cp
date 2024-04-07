/*
https://leetcode.com/problems/valid-parenthesis-string/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool checkValidString(string s) {
        int lo = 0, hi = 0;
        for (auto c: s) {
            lo += c == '(' ? 1 : -1;
            hi += c != ')' ? 1 : -1;
            if (hi < 0) break;
            lo = max(lo, 0);
        }
        return lo == 0;
    }

    bool checkValidString_Alter(string s) {
        int open = 0, close = 0;
        int sz = s.size();
        for (int i = 0; i < sz; ++i) {
            // travel both ends, end encount any *
            // from left as '(' while any from right as ')'
            if (s[i] == '(' || s[i] == '*') ++open;
            else --open;

            if (s[sz-i-1] == ')' || s[sz-i-1] == '*') ++close;
            else --close;

            if (open < 0 || close < 0) return false;
        }
        return true;
    }
};
