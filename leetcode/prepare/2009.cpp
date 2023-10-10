/*
https://leetcode.com/problems/minimum-number-of-operations-to-make-array-continuous/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int ans = n;
        // std::set will sort the nums by default
        set<int> unique(nums.begin(), nums.end());
        vector<int> _nums;
        _nums.assign(unique.begin(), unique.end());

        for (int i = 0; i < _nums.size(); ++i) {
            int left = _nums[i];
            int right = left + n - 1;
            // Find the first index that after last element which <= right
            int j = upper_bound(_nums.begin(), _nums.end(), right) - _nums.begin();
            // (j - i) produces the numbers of in [left, right] range element
            // thus, we need n - (j-i) more operations to make it continuous arr
            ans = min(ans, n - (j - i));
        }

        return ans;
    }
};
