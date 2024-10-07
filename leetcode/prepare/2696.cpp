/*
https://leetcode.com/problems/minimum-string-length-after-removing-substrings/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minLength(string s) {
        string out = "";
        for (char c: s) {
            if (out.size() != 0) {
                if ((out.back() == 'A' && c == 'B') || (out.back() == 'C' && c == 'D')) {
                    out.pop_back();
                    continue;
                }
            }
            out.push_back(c);
        }
        return out.size();
    }
};
