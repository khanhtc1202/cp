/*
https://leetcode.com/problems/different-ways-to-add-parentheses/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> dp[20][20];
    vector<int> convert(string& expression){
        vector<int> ans;
        int sz=expression.size();
        ans.reserve(sz);
        int x=0;
        for(int i=0; i<sz; i++){
            const char c=expression[i];
            switch(c){
                case '+': ans.push_back(101); break;// 101 for +
                case '-': ans.push_back(102); break;// 102 for -
                case '*': ans.push_back(103); break;// 103 for *
                default:{
                    x=10*x+c-'0';
                    if (i==sz-1 || !isdigit(expression[i+1])){
                        ans.push_back(x);
                        x=0;
                    }
                }
            }
        }
        return ans;
    }

    vector<int> f(int l, int r, vector<int>& nums){
        if (l>r) return {};
        if (l==r){
            if (nums[l]>=101) return dp[l][r]={};
            return dp[l][r]={nums[l]};
        }
        if (dp[l][r].size()>0) return dp[l][r];

        vector<int> ans;
        for(int i=l; i<=r; i++){
            if (nums[i]<100) continue;
            vector<int> Left=f(l, i-1, nums);
            vector<int> Right=f(i+1, r, nums);
            for(int L: Left)
                for(int R: Right){
                //    int x=0;
                    switch(nums[i]){
                        case 101: ans.push_back(L+R); break;
                        case 102: ans.push_back(L-R); break;
                        case 103: ans.push_back(L*R); break;
                    }
                }
        }
        return dp[l][r]=ans;
    }
    void tabular(vector<int>& nums, int n){
        for(int i=0; i<n; i++){
            if (nums[i]>=101) dp[i][i]={};
            dp[i][i]={nums[i]};
        }
        for(int d=1; d<n; d++){
            int r;
            for (int l=0; l+d<n; l++) {
                r=l+d;
                vector<int> ans;
                for(int i=l; i<=r; i++){
                    if (nums[i]<100) continue;
                    vector<int> Left=dp[l][i-1];
                    vector<int> Right=dp[i+1][r];
                    for(int L: Left)
                        for(int R: Right){
                            switch(nums[i]){
                                case 101: ans.push_back(L+R); break;
                                case 102: ans.push_back(L-R); break;
                                case 103: ans.push_back(L*R); break;
                            }
                        }
                }
                dp[l][r]=ans;
            }
        }
    }

    vector<int> diffWaysToCompute(string& expression) {
        vector<int> nums=convert(expression);
        const int n=nums.size();
        tabular(nums, n);
        return dp[0][n-1];
    }
};
