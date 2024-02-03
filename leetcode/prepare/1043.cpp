/*
https://leetcode.com/problems/partition-array-for-maximum-sum/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        int n=arr.size();
        vector<int> dp(k, 0);// dp[i]= max sum for arr[0:i]
        for(int i=1; i<=n; i++){
            int maxA=0, ans=0;
            int k0=min(k, i);
            for (int j=1; j<=k0; j++) {
                maxA=max(maxA, arr[i-j]); // Find max value in the current partition
                ans=max(ans, dp[(i-j)%k]+j*maxA);
            }
            dp[i%k]=ans;
        }
        return dp[n%k];
    }
};
