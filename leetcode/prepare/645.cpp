/*
https://leetcode.com/problems/set-mismatch
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector<bool> seen(n+1, 0);
        int dup, sum = 0;
        for (auto x: nums) {
            if (seen[x]) dup = x;
            else seen[x] = 1;
            sum += x;
        }
        int miss = (n*(n+1)/2)-sum+dup;
        return {dup, miss};
    }
};
