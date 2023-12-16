/*
https://leetcode.com/problems/valid-anagram/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.size() != t.size()) return false;

        unordered_map<char, int> hm;
        for (auto c: s) {
            hm[c]++;
        }
        for (auto c: t) {
            if (hm[c] == 0)
                return false;
            hm[c]--;
        }
        return true;
    }
};
