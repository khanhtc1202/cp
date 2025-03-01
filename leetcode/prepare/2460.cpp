/*
https://leetcode.com/problems/apply-operations-to-an-array/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int n = nums.size();
        int w = 0;
        for (int i = 0; i < n; ++i) {
            if (i < n-1 && nums[i] == nums[i+1] && nums[i] != 0) {
                nums[i] *= 2;
                nums[i+1] = 0;
            }

            // nums[i] is not 0 and not pass the condition n[i] == n[i+1]
            if (nums[i] != 0) {
                // so swap it to the front if i is not w (write index)
                if (i != w) {
                    swap(nums[i], nums[w]);
                }
                // add write index either way to increase swapable index
                w++;
            }
        }
        return nums;
    }
};
