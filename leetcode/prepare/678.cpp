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
};
