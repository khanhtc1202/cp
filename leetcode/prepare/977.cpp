/*
https://leetcode.com/problems/squares-of-a-sorted-array/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> out(n);
        int i = 0, j = n-1;

        for (int p = n-1; p >= 0; --p) {
            if (abs(nums[i]) > abs(nums[j])) {
                out[p] = nums[i] * nums[i];
                ++i;
            } else {
                out[p] = nums[j] * nums[j];
                --j;
            }
        }
        return out;
    }
};
