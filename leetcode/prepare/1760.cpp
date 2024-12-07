/*
https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumSize(vector<int>& nums, int maxOperations) {
        int l = 1, r = *max_element(nums.begin(), nums.end());
        while (l < r) {
            int mid = l + (r-l)/2;
            if (isPossible(mid, nums, maxOperations)) {
                r = mid;
            } else {
                l = mid+1;
            };
        }
        return l;
    }

    bool isPossible(int maxBallsInBag, vector<int>& nums, int maxOpe) {
        int totalOpe = 0;
        for (int num: nums) {
            int ope = ceil(num / (double)maxBallsInBag) - 1;
            totalOpe += ope;
            if (totalOpe > maxOpe) return false;
        }
        return true;
    }
};
