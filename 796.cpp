/*
https://leetcode.com/problems/rotate-string/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size()) return false;
        string ss = s+s;
        return ss.find(goal) < ss.size();
    }
};
