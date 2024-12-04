/*
https://leetcode.com/problems/make-string-a-subsequence-using-cyclic-increments/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        auto incr = [=](char c) -> char {
            return 'a' + (c - 'a' + 1) % 26;
        };

        int i = 0, j = 0;
        while (i < str1.size() && j < str2.size()) {
            if (str1[i] == str2[j]) {
                i++;
                j++;
            } else if (incr(str1[i]) == str2[j]) {
                i++;
                j++;
            } else i++;
        }
        return j == str2.size();
    }
};
