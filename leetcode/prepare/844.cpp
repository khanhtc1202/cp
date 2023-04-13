/*
https://leetcode.com/problems/backspace-string-compare/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool backspaceCompare(string s, string t) {
        return build(s) == build(t);
    }

    string build(string s) {
        stack<char> stk;
        for (auto c: s) {
            if (c != '#') {
                stk.push(c);
            } else if (!stk.empty()) {
                stk.pop();
            }
        }
        string out;
        while (!stk.empty()) {
            out += stk.top();
            stk.pop();
        }
        return out;
    }

    bool backspaceCompare_O1Space(string s, string t) {
        int i = s.size() - 1, j = t.size() - 1;
        int skipS = 0, skipT = 0;
        while (i >= 0 || j >= 0) {
            // Skip # and its "follow" alphabet char from s until get comparable char.
            while (i >= 0) {
                if (s[i] == '#') {
                    skipS++;
                    i--;
                } else if (skipS) {
                    skipS--;
                    i--;
                } else break;
            }
            // Same in t
            while (j >= 0) {
                if (t[j] == '#') {
                    skipT++;
                    j--;
                } else if (skipT) {
                    skipT--;
                    j--;
                } else break;
            }

            // The two comparable chars are not equal.
            if (i >= 0 && j >= 0 && s[i] != t[j])
                return false;

            // One of string reaches the end but the other is not.
            if ((i >= 0) != (j >= 0))
                return false;

            i--; j--;
        }
        return true;
    }
};
