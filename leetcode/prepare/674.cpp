/*
Problem desc: https://leetcode.com/problems/longest-continuous-increasing-subsequence/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int res = 1, tmp = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i-1]) {
                tmp++;
                continue;
            }
            res = max(res, tmp);
            tmp = 1;
        }
        return max(res, tmp);
    }
};
