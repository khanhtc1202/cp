/*
https://leetcode.com/problems/range-sum-of-sorted-subarray-sums/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        const int mod=1e9+7;
        vector<int> sum(n*(n+1)/2, 0);
        int idx=0;
        for(int i=0; i<n; i++){
            int x=0;
            for(int j=i; j<n; j++){
                x+=nums[j];
                sum[idx++]=x;
            }
        }
        sort(sum.begin(), sum.end());
        return accumulate(sum.begin()+left-1, sum.begin()+right, 0LL)%mod;
    }
};
