#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string s;
    vector<string> ans;
    vector<string> input = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    void backtrack(int i, string& d) {
        if (i == d.size()) {
            ans.push_back(s);
            return;
        }

        for (auto c : input[d[i] - '0']) {
            s += c;
            backtrack(i+1, d);
            s.pop_back();
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) {
            return ans;
        }
        backtrack(0, digits);
        return ans;
    }
};
