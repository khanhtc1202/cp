/*
https://leetcode.com/problems/minimize-the-maximum-difference-of-pairs/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimizeMax(vector<int>& nums, int p) {
        int n = nums.size();
        auto countPairs = [&](int threshold) -> int {
            int idx = 0, count = 0;
            while (idx < n-1) {
                if (nums[idx+1] - nums[idx] <= threshold)
                    count++, idx++;

                idx++;
            }
            return count;
        };

        sort(nums.begin(), nums.end());
        int l = 0, r = nums[n-1] - nums[0];
        
        while (l < r) {
            int mid = l + (r-l)/2;

            if (countPairs(mid) >= p) {
                r = mid;
            } else {
                l = mid+1;
            }
        }
        return l;
    }
};
