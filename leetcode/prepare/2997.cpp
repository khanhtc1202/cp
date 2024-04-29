/*
https://leetcode.com/problems/minimum-number-of-operations-to-make-array-xor-equal-to-k/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int xorSum=k;
        for(int i=0; i<nums.size(); ++i) 
            xorSum^=nums[i];
        return __builtin_popcount(xorSum);
    }
};
