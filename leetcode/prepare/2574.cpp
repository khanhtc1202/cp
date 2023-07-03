/*
https://leetcode.com/problems/left-and-right-sum-differences/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        int n = nums.size();
        if (n == 1) return {0};

        vector<int> leftSum(n, 0);
        int sum = nums[0];
        for (int i = 1; i < n; i++) {
            leftSum[i] = leftSum[i-1] + nums[i-1];
            sum += nums[i];
        }
        vector<int> ans(n, 0);
        for (int i = 0; i < n; i++) {
            ans[i] = abs(leftSum[i] - (sum - nums[i] - leftSum[i]));
        }
        return ans;
    }
};
