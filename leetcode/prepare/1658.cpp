/*
https://leetcode.com/problems/minimum-operations-to-reduce-x-to-zero/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int total = 0;
        for (auto e: nums) total += e;

        int target = total - x;
        if (target < 0) return -1;

        int maxLenTarget = -1;
        int currSum = 0, left = 0;

        for (int right = 0; right < nums.size(); ++right) {
            currSum += nums[right];
            while (currSum > target && left <= right) {
                currSum -= nums[left++];
            }
            if (currSum == target) {
                maxLenTarget = max(maxLenTarget, right - left + 1);
            }
        }

        return (maxLenTarget == -1) ? -1 : (nums.size() - maxLenTarget);
    }
};
