/*
https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int l = 0, cnt = 0;
        int ans = 0;
        for (int r = 0; r < nums.size(); r++) {
            cnt += (nums[r] == 0);
            while (cnt > 1) {
                cnt -= (nums[l++] == 0);
            }
            ans = max(ans, r - l);
        }
        return ans;
    }
};
