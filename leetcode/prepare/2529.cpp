/*
https://leetcode.com/problems/maximum-count-of-positive-integer-and-negative-integer/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int lb = lower_bound(nums.begin(), nums.end(), 0) - nums.begin();
        int ub = upper_bound(nums.begin(), nums.end(), 0) - nums.begin();
        int n = nums.size();
        return max(lb, n - ub);
    }
};
