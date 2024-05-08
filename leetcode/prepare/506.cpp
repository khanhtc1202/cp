/*
https://leetcode.com/problems/relative-ranks/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
    using int2 = pair<int, int>;
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        const int n = score.size();
        vector<int2> sIdx(n);
        for (int i = 0; i < n; i++)
            sIdx[i] = make_pair(score[i], i);
        sort(sIdx.begin(), sIdx.end());
        vector<string> ans(n);
        ans[sIdx[n - 1].second] = "Gold Medal";
        if (n > 1)
            ans[sIdx[n - 2].second] = "Silver Medal";
        if (n > 2)
            ans[sIdx[n - 3].second] = "Bronze Medal";
        for (int i = n - 4; i >= 0; i--)
            ans[sIdx[i].second] = to_string(n - i);
        return ans;
    }
};
