/*
https://leetcode.com/problems/longest-subarray-with-maximum-bitwise-and/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxVal = 0, ans = 0, currentStreak = 0;
        
        for (int x: nums) {
            if (maxVal < x) {
                maxVal = x;
                ans = currentStreak = 0;
            }
            if (maxVal == x) {
                currentStreak++;
            } else {
                currentStreak = 0;
            }
            
            ans = max(ans, currentStreak);
        }
        return ans;
    }
};
