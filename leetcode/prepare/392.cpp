/*
https://leetcode.com/problems/is-subsequence/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int si = 0, ti = 0;
        while (si < s.size()) {
            while (ti < t.size()) {
                if (s[si] == t[ti])
                    break;
                ti++;
            }

            if (s[si] != t[ti])
                return false;
            
            si++; ti++;
        }
        return si == s.size();
    }

    bool isSubsequenceRefactor(string s, string t) {
        int si = 0, ti = 0;
        while (si < s.size() && ti < t.size()) {
            if (s[si] == t[ti])
                si++;
            ti++;
        }
        return si == s.size();
    }
};
