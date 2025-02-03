/*
https://leetcode.com/problems/longest-strictly-increasing-or-strictly-decreasing-subarray/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return n;
        int flag = 0, ans = 1, curr = 1; // increase
        for (int i = 1; i < n; ++i) {
            if (nums[i] > nums[i-1]) {
                if (flag == 0) {
                    curr++;
                } else {
                    flag = 0;
                    curr = 2;
                }
            } else if (nums[i] < nums[i-1]) {
                if (flag == 1) {
                    curr++;
                } else {
                    flag = 1;
                    curr = 2;
                }
            } else curr = 1;
            ans = max(ans, curr);
        }
        return ans;
    }
};
