/*
Problem desc: https://leetcode.com/problems/range-sum-query-immutable/
*/
#include <bits/stdc++.h>
using namespace std;

class NumArray {
    vector<int> prefixSum;
public:
    NumArray(vector<int>& nums) {
        prefixSum.resize(nums.size()+1, 0);
        prefixSum[1] = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            prefixSum[i+1] = prefixSum[i] + nums[i];
        }
    }
    
    int sumRange(int left, int right) {
        return prefixSum[right+1] - prefixSum[left];
    }
};
