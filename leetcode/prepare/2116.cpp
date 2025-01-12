/*
https://leetcode.com/problems/check-if-a-parentheses-string-can-be-valid/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canBeValid(string s, string locked) {
        int n = s.size();
        if (n % 2) return false;

        vector<int> openBrackets; // store index of '('
        vector<int> unlocked;
        for (int i = 0; i < n; ++i) {
            if (locked[i] == '1') {
                char c = s[i];
                if (c == ')') {
                    if (!openBrackets.empty()) openBrackets.pop_back();
                    else if (!unlocked.empty()) unlocked.pop_back();
                    else return false;
                } else {
                    openBrackets.push_back(i);
                }
            } else {
                unlocked.push_back(i);
            }
        }
        // last condition to ensure there will be at least one unlocked char to convert to ')'
        while (!openBrackets.empty() && !unlocked.empty() && openBrackets.back() < unlocked.back()) {
            openBrackets.pop_back();
            unlocked.pop_back();
        }
        return openBrackets.empty();
    }
};
