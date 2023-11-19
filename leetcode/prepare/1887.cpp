/*
https://leetcode.com/problems/reduction-operations-to-make-the-array-elements-equal/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        // Sort the array in decreasing order
        sort(nums.rbegin(), nums.rend());
        int ans = 0, acc = 0, prev = INT_MAX;
        for (int x: nums) {
            // If we found a number that strictly smaller than previous
            // update all up to now count to operations (the ans).
            if (x != prev) {
                ans += acc;
            }
            acc++;
            prev = x;
        }
        return ans;
    }
};
