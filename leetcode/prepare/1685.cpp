/*
https://leetcode.com/problems/sum-of-absolute-differences-in-a-sorted-array/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getSumAbsoluteDifferences(vector<int>& nums) {
        int left = 0, right = 0, n = nums.size();
        for (int i = 0; i < n; ++i)
            right += nums[i];

        vector<int> ans(n, 0);
        for (int i = 0; i < n; ++i) {
            // (nums[i] * i - (nums[0] + nums[1] + ... + nums[i-1])) + ((nums[i+1] + nums[i+2] + ... + nums[n-1]) - nums[i] * (n-i-1))
            ans[i] = (2*i - n) * nums[i] + right - left;
            left += nums[i];
            right -= nums[i];
        }
        return ans;
    }
};
