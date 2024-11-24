/*
https://leetcode.com/problems/find-the-power-of-k-size-subarrays-i/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int N = nums.size();
        if (k == 1) return nums;
        
        vector<int> ans(N-k+1, -1);
        int consecutiveCount = 1;

        for (int i = 0; i < N-1; ++i) {
            if (nums[i]+1 == nums[i+1]) {
                consecutiveCount++;
            } else consecutiveCount = 1;

            if (consecutiveCount >= k) {
                ans[i-k+2] = nums[i+1];
            }
        }
        return ans;
    }
};
