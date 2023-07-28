/*
https://leetcode.com/problems/sum-of-subarray-ranges/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {
        int n = nums.size();
        vector<int> stk;
        long long ans = 0;
        // Find mindVal using monotolick stack
        for (int r = 0; r <= n; ++r) {
            while (!stk.empty() && (r == n || nums[stk.back()] >= nums[r])) {
                int _min = stk.back();
                stk.pop_back();
                int l = stk.empty() ? -1 : stk.back();
                ans -= (long long)nums[_min] * (r - _min) * (_min - l);
            }
            stk.push_back(r);
        }

        stk.pop_back(); // remove n from stk.
        // Find maxVal same as above
        for (int r = 0; r <= n; ++r) {
            while (!stk.empty() && (r == n || nums[stk.back()] <= nums[r])) {
                int _max = stk.back();
                stk.pop_back();
                int l = stk.empty() ? -1 : stk.back();
                ans += (long long)nums[_max] * (r - _max) * (_max - l);
            }
            stk.push_back(r);
        }
        return ans;
    }
};
