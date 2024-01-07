/*
https://leetcode.com/problems/arithmetic-slices-ii-subsequence/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numberOfArithmeticSlices(vector<int>& nums) {
        const int n=nums.size();
        unordered_map<int, int> dp[n];
        unordered_set<int> arith(nums.begin(), nums.end());
        int ans=0;
        for(int i=0; i<n; i++){
            for (int j=0; j<i; j++){
                long long diff=move((long long)nums[i]-nums[j]);
                if (diff<INT_MIN || diff>INT_MAX) continue;
                int count=dp[j].count(diff)?dp[j][diff]:0;
                if (arith.count(nums[i]+diff))
                    dp[i][diff]+=count+1;
                ans+=count;
            }
        }
        return ans;
    }
};
