/*
https://leetcode.com/problems/move-pieces-to-obtain-a-string/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canChange(string start, string target) {
        vector<pair<char,int>> spos, tpos;
        for (int i = 0; i < start.size(); ++i) {
            if (start[i] != '_') spos.push_back({start[i], i});
        }
        for (int j = 0; j < target.size(); ++j) {
            if (target[j] != '_') tpos.push_back({target[j], j});
        }
        if (spos.size() != tpos.size())
            return false;
        for (int i = 0, j = 0; i < spos.size(); ++i, ++j) {
            auto [a, pa] = spos[i];
            auto [b, pb] = tpos[j];
            if (a != b || (a == 'L' && pa < pb) || (a == 'R' && pa > pb))
                return false;
        }
        return true;
    }
};
