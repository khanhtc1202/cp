/*
https://leetcode.com/problems/count-the-number-of-consistent-strings/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char> sa;
        for (auto c: allowed) sa.insert(c);
        int cnt = 0;
        for (auto w: words) {
            
            for (auto c: w) {
                if (sa.count(c) == 0) goto L;
            }
            cnt++;
L:
        }
        return cnt;
    }
};
