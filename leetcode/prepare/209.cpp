/*
https://leetcode.com/problems/minimum-size-subarray-sum/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l = 0, ans = INT_MAX, sum = 0;
        for (int r = 0; r < nums.size(); r++) {
            sum += nums[r];
            while (l <= r && sum >= target) {
                ans = min(ans, r - l + 1);
                sum -= nums[l];
                l++;
            }
        }
        return ans == INT_MAX ? 0 : ans;
    }
};
