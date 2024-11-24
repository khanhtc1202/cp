/*
https://leetcode.com/problems/shortest-subarray-with-or-at-least-k-ii/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumSubarrayLength(vector<int>& nums, int k) {
        int ans = INT_MAX;
        int start = 0, end = 0;
        vector<int> bitCounts(32, 0);

        while (end < nums.size()) {
            updateBitCounts(bitCounts, nums[end], 1); // Add curr number to window
            while (start <= end && bitCountsToNum(bitCounts) >= k) {
                ans = min(ans, end - start + 1);
                // remove left from window
                updateBitCounts(bitCounts, nums[start], -1);
                ++start;
            }
            ++end;
        }
        return ans == INT_MAX ? -1 : ans;
    }

private:
    void updateBitCounts(vector<int>& bitCounts, int number, int del) {
        for (int i = 0; i < 32; ++i) {
            if ((number >> i) & 1) { // Bit at position i is set
                bitCounts[i] += del;
            }
        }
    }

    int bitCountsToNum(const vector<int>& bitCounts) {
        int res = 0;
        for (int i = 0; i < 32; ++i) {
            if (bitCounts[i] != 0) {
                res |= 1 << i;
            }
        }
        return res;
    }
};
