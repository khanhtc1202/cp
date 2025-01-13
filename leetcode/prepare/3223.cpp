/*
https://leetcode.com/problems/minimum-length-of-string-after-operations/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumLength(string s) {
        vector<int> count(26, 0);
        for (char c: s) ++count[c-'a'];
        int ans = 0;
        for (int i = 0; i < 26; ++i) {
            if (count[i] < 3) ans += count[i];
            else if (count[i] % 2) ans += 1;
            else ans += 2;
        }
        return ans;
    }
};
