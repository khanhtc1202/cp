/*
https://leetcode.com/problems/reverse-substrings-between-each-pair-of-parentheses/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseParentheses(string s) {
        vector<int> openPIndex;
        string result;
        for (char c: s) {
            if (c == '(') {
                openPIndex.push_back(result.size());
            } else if (c == ')') {
                // revert
                int start = openPIndex.back();
                openPIndex.pop_back();
                reverse(result.begin()+start, result.end());
            } else {
                result += c;
            }
        }
        return result;
    }
};
