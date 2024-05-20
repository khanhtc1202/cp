/*
https://leetcode.com/problems/sum-of-all-subset-xor-totals/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n = nums.size();

        function<int(int, int)> backtrack = [&](int i, int sum) -> int {
            if (i == n) return sum;
            int x = nums[i];
            int take = backtrack(i+1, sum^x);
            int notake = backtrack(i+1, sum);
            return take+notake;
        };

        return backtrack(0, 0);
    }
};
