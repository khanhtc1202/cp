/*
https://leetcode.com/problems/minimum-absolute-sum-difference/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minAbsoluteSumDiff(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        int mod = 1e9+7;
        vector<int> tmp(nums1);
        sort(tmp.begin(), tmp.end());

        int maxn = 0;
        int sum = 0;
        for (int i = 0; i < n; i++) {
            int diff = abs(nums1[i] - nums2[i]);
            (sum += diff) %= mod;
            if (diff > maxn) {
                auto it = upper_bound(tmp.begin(), tmp.end(), nums2[i]);
                if (it != tmp.end()) {
                    maxn = max(maxn, diff - abs(*(it) - nums2[i]));
                }
                if (it != tmp.begin()) {
                    maxn = max(maxn, diff - abs(*(--it) - nums2[i]));
                }
            }
        }
        return (sum - maxn + mod) % mod;
    }
};
