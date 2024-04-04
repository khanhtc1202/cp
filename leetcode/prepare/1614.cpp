/*
https://leetcode.com/problems/maximum-nesting-depth-of-the-parentheses/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        int ans = 0, cnt = 0;
        for (char c: s) {
            if (c == '(') { ++cnt; ans = max(ans, cnt); }
            else if (c == ')') --cnt;
        }
        return ans;
    }
};
