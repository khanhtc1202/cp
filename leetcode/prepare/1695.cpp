/*
http://leetcode.com/problems/maximum-erasure-value/description/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        const int n = nums.size();
        bitset<10001> hasX = 0;
        int ans = 0, wsum = 0;

        for (int l = 0, r = 0; r < n; ++r) {
            const int x = nums[r];
            while (hasX[x]) { // only one x available at a time
                hasX[nums[l]] = 0;
                wsum -= nums[l];
                ++l;
            }
            hasX[x] = 1;
            wsum += x; // re-add x to current window
            ans = max(ans, wsum);
        }
        return ans;
    }
};
