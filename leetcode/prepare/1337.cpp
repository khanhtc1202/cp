/*
https://leetcode.com/problems/the-k-weakest-rows-in-a-matrix/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    using ii = pair<int,int>;
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<ii> buff;
        int idx = 0;
        for (auto& r: mat) {
            int sol = lower_bound(r.begin(), r.end(), 0, greater<int>()) - r.begin();
            buff.emplace(buff.end(), sol, idx++);
        }

        sort(buff.begin(), buff.end());

        vector<int> ans;
        for (int i = 0; i < k; ++i) {
            ans.push_back(buff[i].second);
        }
        return ans;
    }
};
