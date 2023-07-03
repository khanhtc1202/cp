/*
https://leetcode.com/problems/buddy-strings/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool buddyStrings(string s, string goal) {
        if (s.size() != goal.size()) return false;
        int char_s[26] = {0};
        vector<int> diff;
        for (int i = 0; i < s.size(); i++) {
            if (diff.size() > 2) return false;
            if (s[i] != goal[i]) diff.push_back(i);
            char_s[s[i]-'a']++;
        }
        int cnt = diff.size();
        if (cnt == 1) return false;
        if (cnt == 2) return s[diff[0]] == goal[diff[1]] && s[diff[1]] == goal[diff[0]];
        if (cnt == 0) return *max_element(char_s, char_s + 26) >= 2;
        return false;
    }
};
