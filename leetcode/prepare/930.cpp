/*
https://leetcode.com/problems/binary-subarrays-with-sum/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int atMost(vector<int>& nums, int goal) {
        int n = nums.size();
        int sum=0, l=0, r=0, cnt=0;
        for(; r<n; r++){
            sum+=nums[r]; 
            for(; sum>goal; l++)
                sum-=nums[l];
            //add the length of each subarray 
            cnt+=(r-l+1);
        }       
        return cnt;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        return goal > 0 ? atMost(nums, goal) - atMost(nums, goal-1) : atMost(nums, 0);
    }
};
