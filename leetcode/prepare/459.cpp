/*
https://leetcode.com/problems/repeated-substring-pattern/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        int n = s.size();
        if (n == 1) return false;

        for (int i = 1; i <= n/2; ++i) {
            if (n % i != 0) continue;

            string gen = "";
            string prefix = s.substr(0, i);
            for (int j = 0; j < n/i; ++j) {
                gen += prefix;
            }

            if (gen == s) return true;
        }
        return false;
    }
};
