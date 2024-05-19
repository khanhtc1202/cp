/*
https://leetcode.com/problems/find-the-maximum-sum-of-node-values/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maximumValueSum(vector<int>& nums, int k, vector<vector<int>>& edges) {
        long long sum=0, xor_cnt=0, correction=INT_MAX;
        for(long long x: nums){
            long long y=x^k;
            xor_cnt+=(y>x);
            sum+=(y>x)?y:x;
            correction=min(correction, abs(x-y));
        }
        return sum-=(xor_cnt&1?correction:0);
    }
};
