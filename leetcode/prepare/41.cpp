/*
https://leetcode.com/problems/first-missing-positive/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n = nums.size();
        bool has1 = false;
        // Reset all negative, zero, and number which larger
        // than n with 1s since we don't care about those numbers
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 1) has1 = true;
            else if (nums[i] <= 0 || nums[i] > n) nums[i] = 1;
        }

        if (!has1) return 1; // as smallest

        // Same as https://leetcode.com/problems/find-all-duplicates-in-an-array/
        // using sign as mark for seen or not
        for (int i = 0; i < n; ++i) {
            int idx = abs(nums[i]);
            if (idx == n) {
                // (*)
                nums[0] = -abs(nums[0]);
            } else {
                // mark value at idx negative to mention
                // that the number which equal to idx is seen/visted
                nums[idx] = -abs(nums[idx]);
            }
        }

        for (int i = 1; i < n; ++i) {
            // First number which is not visited/seen
            // is the missing number => return it
            if (nums[i] > 0) return i;
        }

        // else the missing number is n or n+1
        // based on the sign of the first number at nums[0]
        // due to (*)
        return nums[0] > 0 ? n : n+1;
    }
};
