/*
https://leetcode.com/problems/maximum-width-ramp/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxWidthRamp(vector<int>& nums) {
        int N = nums.size();
        vector<int> rightMax(N); // store max [i, end of nums]

        rightMax[N-1] = nums[N-1];
        for (int i = N-2; i >= 0; --i) {
            rightMax[i] = max(rightMax[i+1], nums[i]);
        }

        int left = 0, right = 0;
        int ans = 0;

        while (right < N) {
            while (left < right && nums[left] > rightMax[right]) {
                left++; // Scroll left until we found the smallest left which nums[left] <= rightMax[right]
            }
            ans = max(ans, right - left);
            right++; // Scroll right
        }
        return ans;
    }
};
