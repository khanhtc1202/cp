/*
https://leetcode.com/problems/maximum-sum-circular-subarray/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSubarraySumCircular(vector<int>& nums) {
        // cur_max is max which stop at current index.
        // cur_min is min which stop at current index.
        int cur_max = 0, cur_min = 0, max_sum = nums[0], min_sum = nums[0];
        int sum = 0;
        for (auto num: nums) {
            // Reset cur_max if the current cur_max is negative number.
            cur_max = max(cur_max, 0) + num;
            // Keep max_sum is max by compare last max_sum with cur_max.
            max_sum = max(max_sum, cur_max);
            // Same with min
            cur_min = min(cur_min, 0) + num;
            min_sum = min(min_sum, cur_min);

            // Accumulative sum up all nums elements.
            sum += num;
        }
        // If accumulative sum is a min, then which ever max_sum will be max
        // else max would be max_sum or sum - min_sum (circular sum).
        return sum == min_sum ? max_sum : max(max_sum, sum - min_sum);
    }
};
