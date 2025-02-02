/*
https://leetcode.com/problems/check-if-array-is-sorted-and-rotated/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool check(vector<int>& nums) {
        int drop = 0;
        int n = nums.size();
        if (n < 2) return true;
        for (int i = 1; i < n; ++i) {
            if (nums[i] < nums[i-1]) drop++;
        }
        return drop == 0 || ((drop == 1) && (nums[0] >= nums[n-1]));
    }
};
