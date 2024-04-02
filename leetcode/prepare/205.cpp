/*
https://leetcode.com/problems/isomorphic-strings/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        if (s.size() != t.size()) return false;

        unordered_map<char, char> hm;
        unordered_map<char, char> rhm;
        for (int i = 0; i < s.size(); i++) {
            if (hm.find(s[i]) == hm.end()) {
                if (rhm.find(t[i]) != rhm.end())
                    return false;

                hm[s[i]] = t[i];
                rhm[t[i]] = s[i];
                continue;
            }
            if (hm[s[i]] != t[i])
                return false;
        }
        return true;
    }
};
