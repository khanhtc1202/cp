/*
https://leetcode.com/problems/find-players-with-zero-or-one-losses/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> findWinners(vector<vector<int>>& matches) {
        vector<int> p(100001, -1);
        int pmin = INT_MAX, pmax = INT_MIN;
        for (auto& m: matches) {
            int &w=m[0], &l=m[1];
            p[w] = (p[w] == -1) ? 0 : p[w];
            p[l] = (p[l] == -1) ? 1 : p[l]+1;
            pmin = min({pmin, w, l});
            pmax = max({pmax, w, l});
        }
        vector<vector<int>> ans(2);
        for (int i = pmin; i <= pmax; ++i) {
            if (p[i] == 0) ans[0].push_back(i);
            else if (p[i] == 1) ans[1].push_back(i);
        }
        return ans;
    }
};
