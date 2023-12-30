/*
https://leetcode.com/problems/redistribute-characters-to-make-all-strings-equal/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int count[26] = {0};
        for (auto w: words) {
            for (auto c: w) {
                count[c-'a']++;
            }
        }
        int n = words.size();
        for (int i = 0; i < 26; ++i) {
            if (count[i] % n != 0) return false;
        }
        return true;
    }
};
