/*
https://leetcode.com/problems/count-number-of-nice-subarrays/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        const int n = nums.size();

        int l=0, cnt=0, odds=0;
        for (int r = 0; r < n; r++) {
            odds+=(nums[r]&1);
            // Ensure the current window [l, r] has at least k odd numbers
            while (l <= r && odds > k){
                odds -= (nums[l]&1);
                l++;
            }
            // If the current window [l, r] has exactly k odd numbers
            if (odds == k) {
                int l0 = l;
                // Count nice subarrays ending at r
                while (l0 <= r && (nums[l0]&1) == 0) 
                    l0++;
                cnt += l0-l+1;
            }
        }
        return cnt;
    }
};
