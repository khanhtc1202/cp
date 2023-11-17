/*
https://leetcode.com/problems/minimize-maximum-pair-sum-in-array/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int l = 0, r = nums.size() - 1, ans = INT_MIN;
        while (l < r) {
            ans = max(ans, nums[l++] + nums[r--]);
        }
        return ans;
    }
};
