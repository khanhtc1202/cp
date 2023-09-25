/*
https://leetcode.com/problems/find-the-difference/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    char findTheDifference(string s, string t) {
        char out = 0;
        for (auto c: s) out ^= c;
        for (auto c: t) out ^= c;
        return out;
    }
};
