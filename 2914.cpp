/*
https://leetcode.com/problems/minimum-number-of-changes-to-make-binary-string-beautiful/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minChanges(string s) {
        int ans = 0;
        for (int i = 0; i < s.size(); i=i+2) {
            if (s[i] != s[i+1]) ans++;
        }
        return ans;
    }
};
