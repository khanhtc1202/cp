/*
https://leetcode.com/problems/length-of-longest-subarray-with-at-most-k-frequency/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        int n = nums.size();
        int res = 0;
        unordered_map<int, int> cnt;
        for (int l = 0, r = 0; r < n; ++r) {
            cnt[nums[r]]++;
            while (cnt[nums[r]] > k) {
                cnt[nums[l++]]--;
            }
            res = max(res, r-l+1);
        }
        return res;
    }
};
