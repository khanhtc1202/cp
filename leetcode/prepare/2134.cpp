/*
https://leetcode.com/problems/minimum-swaps-to-group-all-1s-together-ii/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int ans = INT_MAX, N = nums.size();
        // We slide a window of side totalOnes
        int totalOnes = accumulate(nums.begin(), nums.end(), 0);

        int onesCount = nums[0];
        int end = 0;

        for (int start = 0; start < N; ++start) {
            // Update onesCount by remove the ele that is sliding
            // out of the window (left most ele)
            if (start != 0) {
                onesCount -= nums[start-1];
            }

            // Sliding the window and update onesCount
            while (end - start + 1 < totalOnes) {
                ++end;
                // This end % N for circle index
                onesCount += nums[end % N];
            }

            // Update ans
            ans = min(ans, totalOnes - onesCount);
        }
        return ans;
    }
};
