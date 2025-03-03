/*
https://leetcode.com/problems/partition-array-according-to-given-pivot/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        int n = nums.size();
        int l = 0, g = n-1;
        vector<int> ans(n, pivot);
        for (int i = 0, j = n-1; i < n; ++i, --j) {
            if (nums[i] < pivot) {
                ans[l++] = nums[i];
            }
            if (nums[j] > pivot) {
                ans[g--] = nums[j];
            }
        }
        return ans;
    }
};
