#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string s;
    vector<string> ans;

    void backtrack(int i, int n, int open = 0, int close = 0) {
        if (i == 2*n) {
            ans.push_back(s);
            return;
        }

        if (open < n) {
            s += '(';
            backtrack(i+1, n, open+1, close);
            s.pop_back();
        }

        if (open > close) {
            s += ')';
            backtrack(i+1, n, open, close+1);
            s.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        backtrack(0, n);
        return ans;
    }
};
