/*
https://leetcode.com/problems/continuous-subarrays/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long continuousSubarrays(vector<int>& nums) {
        int n = nums.size();
        int r = 0, l = 0;
        int curMin, curMax;
        long long windowLen = 0, total = 0;

        curMin = curMax = nums[r];
        for (r = 0; r < n; ++r) {
            curMin = min(curMin, nums[r]);
            curMax = max(curMax, nums[r]);

            // window break, update left
            if (curMax - curMin > 2) {
                windowLen = r - l;
                total += (windowLen * (windowLen + 1) / 2);

                // refinding new window which end at curr
                // since the window end at r, we expand left to ensure
                // [l, r] is valid window
                l = r;
                curMin = curMax = nums[r];
                while (l > 0 && abs(nums[r] - nums[l-1]) <= 2) {
                    l--;
                    curMin = min(curMin, nums[l]);
                    curMax = max(curMax, nums[l]);
                }

                // Remove the overcounted subarrays from total
                // Since it will be added later when we found the new r
                if (l < r) {
                    windowLen = r - l;
                    total -= (windowLen * (windowLen + 1) / 2);
                }
            }
        }

        // Add subarrays count for the last window
        windowLen = r - l;
        total += (windowLen * (windowLen + 1) / 2);

        return total;
    }
};
