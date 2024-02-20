/*
https://leetcode.com/problems/missing-number/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {
        // bit manipulation
        int res = nums.size();
        for (int i = 0; i < nums.size(); i++)
            res ^= (nums[i]^i);
        return res;
    }

    int missingNumberAgle(vector<int>& nums) {
        int sum = 0, n = nums.size();
        for (auto x: nums)
            sum += x;
        return n*(n+1)/2 - sum;
    }
};
