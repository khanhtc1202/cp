/*
https://leetcode.com/problems/monotonic-array/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
        if (nums.size() == 1) return true;
        bool init, flag = false;
        for (int i = 1; i < nums.size(); ++i) {
            if (nums[i] == nums[i-1]) continue;
            if (!flag) { init = nums[i] > nums[i-1]; flag = true; continue; }
            if (init ^ (nums[i] > nums[i-1])) return false;
        }
        return true;
    }
};
