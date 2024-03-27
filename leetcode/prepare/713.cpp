/*
https://leetcode.com/problems/subarray-product-less-than-k/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if (k<=1) return 0; // edge case
        unsigned  prod=1;
        int n = nums.size(), r = 0, cnt = 0;
        for(int l = 0; l < n; ++l){
            while (r<n && prod<k) prod*=nums[r++];
            cnt += (r-l);
            if (prod >= k) cnt--; // subtract 1 if the product>= k
            prod /= nums[l];
        }
        return cnt;
    }
};
