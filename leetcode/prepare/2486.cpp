/*
https://leetcode.com/problems/append-characters-to-string-to-make-subsequence/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int appendCharacters(string s, string t) {
        int pt = 0;
        for (int ps = 0; ps < s.size(); ++ps) {
            if (s[ps] == t[pt]) ++pt;
        }
        int ans = 0;
        while (pt++ < t.size()) ans++;
        return ans;
    }
};
