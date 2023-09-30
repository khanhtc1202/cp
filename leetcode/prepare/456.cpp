/*
https://leetcode.com/problems/132-pattern/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        if (nums.size() < 3) {
            return false;
        }
        stack<int> stk;
        vector<int> min_array(nums.size());
        min_array[0] = nums[0];

        for (size_t i = 1; i < nums.size(); i++) {
            min_array[i] = min(min_array[i - 1], nums[i]);
        }
        for (size_t j = nums.size() - 1; j > 0; j--) {
            if (nums[j] <= min_array[j]) {
                continue;
            }
            while (!stk.empty() and stk.top() <= min_array[j]) {
                stk.pop();
            }
            if (!stk.empty() and stk.top() < nums[j]) {
                return true;
            }
            stk.push(nums[j]);
        }
        return false;
    }

    bool find132pattern_slow(vector<int>& nums) {
        int min_i = INT_MAX;
        for (int j = 0; j < nums.size() - 1; ++j) {
            min_i = min(min_i, nums[j]);
            for (int k = j+1; k < nums.size(); ++k) {
                if (nums[k] < nums[j] && min_i < nums[k]) {
                    return true;
                }
            }
        }
        return false;
    }
};
