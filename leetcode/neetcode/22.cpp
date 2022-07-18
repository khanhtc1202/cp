#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string s;
    vector<string> ans;

    void generate(int i, int n, int open = 0, int close = 0) {
        if (i == 2*n) {
            ans.push_back(s);
            return;
        }

        if (open < n) {
            s += '(';
            generate(i+1, n, open+1, close);
            s.pop_back();
        }

        if (close < open) {
            s += ')';
            generate(i+1, n, open, close+1);
            s.pop_back();
        }
    }

    vector<string> generateParenthesis(int n) {
        generate(0, n);
        return ans;
    }
};
