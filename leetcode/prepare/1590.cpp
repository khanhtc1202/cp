/*
https://leetcode.com/problems/make-sum-divisible-by-p/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int N = nums.size();
        int totalSum = 0;

        for (int x: nums) {
            totalSum = (totalSum + x) % p;
        }

        int target = totalSum % p;
        if (target == 0) return 0;

        unordered_map<int, int> mod;
        mod[0] = -1;
        int currentSum = 0, minLen = N;

        for (int i = 0; i < N; ++i) {
            currentSum = (currentSum + nums[i]) % p;
            int needed = (currentSum - target + p) % p;
            if (mod.find(needed) != mod.end()) {
                minLen = min(minLen, i - mod[needed]);
            }
            mod[currentSum] = i;
        }
        return minLen == N ? -1 : minLen;
    }
};
