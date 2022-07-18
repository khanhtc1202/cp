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
};
