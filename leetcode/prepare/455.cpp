/*
https://leetcode.com/problems/assign-cookies/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        if (s.size() == 0) return 0;

        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        int gi = 0, si = 0;
        int ans = 0;
        while (gi < g.size() && si < s.size()) {
            if (g[gi] <= s[si]) {
                ans++;
                gi++; si++;
            } else {
                si++;
            }
        }
        return ans;
    }
};
