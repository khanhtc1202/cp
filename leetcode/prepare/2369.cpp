/*
https://leetcode.com/problems/check-if-there-is-a-valid-partition-for-the-array/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool validPartition(vector<int>& nums) {
        int n = nums.size();
        bool dp[3] = {};
        dp[0] = true;

        for (int i = 0; i < n; ++i) {
            int dpIdx = i+1;
            bool ans = false;

            if (i > 0 && nums[i] == nums[i-1]) {
                ans |= dp[(dpIdx - 2) % 3];
            }
            if (i > 1 && nums[i] == nums[i-1] && nums[i] == nums[i-2]) {
                ans |= dp[(dpIdx - 3) % 3];
            }
            if (i > 1 && nums[i] == nums[i-1]+1 && nums[i-1] == nums[i-2]+1) {
                ans |= dp[(dpIdx - 3) % 3];
            }

            dp[dpIdx % 3] = ans;
        }
        return dp[n % 3];
    }
};
