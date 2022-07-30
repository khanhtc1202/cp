#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for (auto n: nums)
            sum += n;

        int sub = sum / 2;
        if (sum != sub*2)
            return false;

        vector<int> dp(sub+1, false);
        dp[0] = true;
        for (auto num: nums)
            for (int i = sub; i >= num; i--)
                dp[i] = dp[i] || dp[i-num];
        return dp[sub];
    }

    bool canPartitionSet(vector<int>& nums) {
        int sum = 0;
        for (auto n: nums)
            sum += n;

        int sub = sum /2;
        if (sum != sub*2)
            return false;

        unordered_set<int> sums;
        sums.insert(0);
        for (auto num: nums) {
            unordered_set<int> tmp;
            for (auto sum: sums) {
                if (sum+num == sub)
                    return true;
                tmp.insert(sum+num);
                tmp.insert(sum);
            }                
            sums = tmp;
        }            
        return false;
    }

    // bool canPartitionBFS(vector<int>& nums) {
    //     int sum = 0;
    //     for (auto n: nums)
    //         sum += n;

    //     int sub = sum /2;
    //     if (sum != sub*2)
    //         return false;

    //     queue<int> q;
    //     q.push(0);
    //     vector<bool> visited(nums.size());
    //     while
    // }
};
