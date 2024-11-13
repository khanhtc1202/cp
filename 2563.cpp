/*
https://leetcode.com/problems/count-the-number-of-fair-pairs/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long lower_bound(vector<int>& nums, int low, int high, int ele) {
        while (low <= high) {
            int mid = low + ((high-low)/2);
            if (nums[mid] >= ele) {
                high = mid - 1;
            } else
                low = mid + 1;
        }
        return low;
    }
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        sort(nums.begin(), nums.end());
        long long ans = 0;
        for (int i = 0; i < nums.size(); ++i) {
            // Find the index of which sum (i + low) < lower
            int low = lower_bound(nums, i+1, nums.size()-1, lower-nums[i]);
            // Find the index of which sum (i + high) <= upper
            int high = lower_bound(nums, i+1, nums.size()-1, upper-nums[i]+1);

            // Update ans
            ans += 1LL * (high - low);
        }
        return ans;
    }
};
