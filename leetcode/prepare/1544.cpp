/*
https://leetcode.com/problems/make-the-string-great/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string makeGood(string s) {
        string str;
        for (char c: s) {
            if (!str.empty() && abs(c - str.back()) == 32) str.pop_back();
            else str.push_back(c);
        }
        return str;
    }
};
