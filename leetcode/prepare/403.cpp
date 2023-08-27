/*
https://leetcode.com/problems/frog-jump/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int n;
    vector<vector<int>> dp; //2D dp matrix (index for stone, jump units)
    unordered_map<int, int> stone2i; // Save Binary search

    bool f(vector<int>& stones, int i, int k){
        if (i==n-1) return 1;
        if (dp[i][k]!=-1) return dp[i][k];
        bool ans=0;
        for(int jump: {k-1, k, k+1}){//possible jump units: k-1, k, k+1
            if (jump==0) continue;
            //See whether stones[i]+jump in the hashTable stone2i
            if (stone2i.count(stones[i]+jump)==0) continue; // not found
            int next=stone2i[stones[i]+jump];
            ans=ans||f(stones, next, jump);
        }
        return dp[i][k]=ans;
    }

    bool canCross(vector<int>& stones) {
        n=stones.size();
        dp.assign(n+1, vector<int>(n+1, -1));
        for(int i=0; i<n; i++)
            stone2i[stones[i]]=i;
        return f(stones, 0, 0); 
    }
};
