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

    string reverseParentheses_Opt(string s) {
        int N = s.size();
        vector<int> opened;
        vector<int> pair(N);

        for (int i = 0; i < N; ++i) {
            if (s[i] == '(') {
                opened.push_back(i);
            }
            if (s[i] == ')') {
                int j = opened.back();
                opened.pop_back();
                // create the wormhole
                pair[i] = j;
                pair[j] = i;
            }
        }

        string ans;
        // direction == 1 mean travel forward, == -1 mean travel backward
        for (int curr = 0, direction = 1; curr < N; curr += direction) {
            if (s[curr] == '(' || s[curr] == ')') {
                curr = pair[curr]; // jump to the connected parenthes
                direction = -direction;
            } else {
                ans += s[curr];
            }
        }
        return ans;
    }
};
