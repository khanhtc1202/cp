/*
https://leetcode.com/problems/house-robber-iv/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCapability(vector<int>& nums, int k) {
        int minN = *min_element(nums.begin(), nums.end());
        int maxN = *max_element(nums.begin(), nums.end());
        if (k == 1) return minN;
        int l = minN, r = maxN, n = nums.size();
        while (l < r) {
            int mid = l + (r-l)/2;
            int cnt = 0;
            for (int i = 0; i < n; ++i) {
                if (nums[i] <= mid)
                    ++cnt, ++i; // skip the next house
            }
            if (cnt >= k) {
                r = mid;
            } else l = mid+1;
        }
        return l;
    }
};
