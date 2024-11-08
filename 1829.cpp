/*
https://leetcode.com/problems/maximum-xor-for-each-query/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
        int N = nums.size();
        int xorProduct = 0;
        for (int i = 0; i < N; ++i) {
            xorProduct ^= nums[i];
        }
        vector<int> ans(N);
        int mask = (1 << maximumBit) - 1;
        for (int i = 0; i < N; ++i) {
            ans[i] = xorProduct ^ mask;
            xorProduct ^= nums[N - 1 - i]; // Remove last ele
        }
        return ans;
    }
};
