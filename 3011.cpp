/*
https://leetcode.com/problems/find-if-array-can-be-sorted/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        // Number of set bits of the elements in the current segment
        int numOfSetBits = __builtin_popcount(nums[0]);
        int maxOfSeg = nums[0];
        int minOfSeg = nums[0];
        int maxOfPrevSeg = INT_MIN;

        for (int i = 1; i < nums.size(); ++i) {
            // Same segment
            if (__builtin_popcount(nums[i]) == numOfSetBits) {
                maxOfSeg = max(maxOfSeg, nums[i]);
                minOfSeg = min(minOfSeg, nums[i]);
            } else { // Other segment
                if (minOfSeg < maxOfPrevSeg) {
                    return false; // Check last segment is valid
                }
                // Update last segment max
                maxOfPrevSeg = maxOfSeg;
                // Update new segment init values
                maxOfSeg = nums[i];
                minOfSeg = nums[i];
                numOfSetBits = __builtin_popcount(nums[i]);
            }
        }
        // Check final segment
        if (minOfSeg < maxOfPrevSeg) {
            return false;
        }
        return true;
    }
};
