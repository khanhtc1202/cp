/*
https://leetcode.com/problems/minimum-remove-to-make-valid-parentheses/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minRemoveToMakeValid(string s) {
        int left = 0, right = 0;
        vector<char> stk;

        for (char c: s) {
            if (c == '(') ++left;
            else if (c == ')') ++right;

            if (right > left) --right;
            else stk.push_back(c);
        }

        string out = "";
        while (!stk.empty()) {
            char c = stk.back();
            stk.pop_back();
            if (left > right && c == '(') --left;
            else out += c;
        }

        reverse(out.begin(), out.end());
        return out;
    }
};
