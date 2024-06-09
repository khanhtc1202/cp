/*
https://leetcode.com/problems/subarray-sums-divisible-by-k/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int modGroup[k];
        memset(modGroup, 0, sizeof(modGroup));
        // Avoid first element % k == 0 missed from counting
        modGroup[0] = 1;
        int sum = 0, ans = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            int rem = (sum % k + k) % k; // Avoid negative mod
            ans += modGroup[rem]++;
        }
        return ans;
    }
};
