/*
https://leetcode.com/problems/number-of-zero-filled-subarrays/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans = 0, numSubArr = 0;
        for (auto num: nums) {
            if (num == 0) numSubArr++;
            else numSubArr = 0;

            ans += numSubArr;
        }
        return ans;
    }
};
