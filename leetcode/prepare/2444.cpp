/*
https://leetcode.com/problems/count-subarrays-with-fixed-bounds/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans = 0;
        int mini = -1, maxi = -1;
        int n = nums.size();
        for (int l = 0, r = 0; r < n; ++r) {
            int x = nums[r];
            if (x < minK || x > maxK) { // range over
                l = r+1;
                continue;
            }
            if (x == maxK) maxi = r; // update position
            if (x == minK) mini = r; // update position
            ans += max(min(maxi, mini) - l+1, 0);
        }
        return ans;
    }
};
