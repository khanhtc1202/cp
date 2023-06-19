/*
https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxAbsoluteSum(vector<int>& nums) {
        int cur_max = 0, cur_min = 0, max_sum = nums[0], min_sum = nums[0];
        for (auto num: nums) {
            cur_max = max(cur_max, 0) + num;
            max_sum = max(max_sum, cur_max);
            cur_min = min(cur_min, 0) + num;
            min_sum = min(min_sum, cur_min);
        }
        return abs(min_sum) > max_sum ? abs(min_sum) : max_sum;
    }
};
