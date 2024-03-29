/*
https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int M=*max_element(nums.begin(), nums.end());
        int n=nums.size();
        vector<int> idx;
        for(int i=0; i<n; i++)
            if(nums[i]==M) idx.push_back(i);
        int sz=idx.size();
        if (sz<k) return 0;
        long long ans=(long long)(idx[0]+1)*(n-idx[k-1]);
        for (int i=1; i+k-1<sz; i++)
            ans+=(long long)(idx[i]-idx[i-1])*(n-idx[i+k-1]);
        return ans;
    }
};
