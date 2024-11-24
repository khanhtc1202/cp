/*
https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> buildLIS(vector<int>& v) {
        vector<int> lisLen(v.size(), 1);
        vector<int> dp;
        dp.push_back(v[0]);
        for (int i = 1; i < v.size(); ++i) {
            if (v[i] > dp.back()) {
                dp.push_back(v[i]);
            } else {
                auto lower = lower_bound(dp.begin(), dp.end(), v[i]);
                dp[lower - dp.begin()] = v[i];
            }
            lisLen[i] = dp.size();
        }
        return lisLen;
    }

    int minimumMountainRemovals(vector<int>& nums) {
        int N = nums.size();
        vector<int> lis = buildLIS(nums);
        reverse(nums.begin(), nums.end());
        vector<int> lds = buildLIS(nums);
        reverse(lds.begin(), lds.end()); // to correct the indexies

        int ans = INT_MAX;
        for (int i = 0; i < N; ++i) {
            if (lis[i] > 1 && lds[i] > 1) {
                ans = min(ans, N - (lis[i] + lds[i] - 1));
            }
        }
        return ans;
    }
};
