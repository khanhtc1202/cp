/*
https://leetcode.com/problems/equal-sum-arrays-with-minimum-number-of-operations/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size() * 6 || nums2.size() > nums1.size() * 6)
            return -1;
        int sum1 = accumulate(nums1.begin(), nums1.end(), 0);
        int sum2 = accumulate(nums2.begin(), nums2.end(), 0);

        // Flip so that nums1 always smaller
        if (sum1 > sum2) swap(nums1, nums2);

        int cnt[6] = {};
        // cnt stores number of each ops of value (1->5) we can use
        // to reduce the gap

        // smaller -> larger (up to 5 if we have `1`)
        for (auto n: nums1) ++cnt[6 - n];
        // larger -> smaller (up to 5 if we have `6`)
        for (auto n: nums2) ++cnt[n - 1];

        int diff = abs(sum2 - sum1), ops = 0;
        for (int i = 5; i > 0 && diff > 0; --i) {
            // Greedy take all possible cnt[i] (5->1)
            int take = min(cnt[i], diff/i + (diff%i != 0));
            diff -= take*i;
            ops += take;
        }
        return ops;
    }
};
