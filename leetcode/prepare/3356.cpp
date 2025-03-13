/*
https://leetcode.com/problems/zero-array-transformation-ii/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int k = 0, sum = 0, n = nums.size();
        vector<int> diff(n+1);
        for (int i = 0; i < n; ++i) {
            // Iterate queries until k first queries are enough to make nums[i] to zero
            while (sum + diff[i] < nums[i]) {
                k++;
                if (k > queries.size()) {
                    return -1; // Not enough queries to make array zero
                }
                int left = queries[k-1][0], right = queries[k-1][1], val = queries[k-1][2];
                if (right >= i) { // Current index is in range
                    diff[max(left, i)] += val;
                    diff[right+1] -= val;
                }
            }
            // calculate prefixsum of current index
            sum += diff[i];
        }
        return k;
    }
};
