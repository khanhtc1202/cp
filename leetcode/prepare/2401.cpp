/*
https://leetcode.com/problems/longest-nice-subarray/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // O(n^2) solution
    int longestNiceSubarray(vector<int>& nums) {
        int s = 0, e = 0;
        int n = nums.size(), ans = 1;
        while (e < n) {
            int x = nums[e];
            int flag = s-1;
            for (int i = s; i < e; ++i) {
                if ((nums[i]&x) != 0) flag = i;
            }
            ans = max(ans, e-flag);
            s = flag+1;
            e++;
        }
        return ans;
    }

    // O(n) solution
    int longestNiceSubarray_Bit(vector<int>& nums) {
        int s = 0, e = 0;
        int n = nums.size(), ans = 1;
        int usedBits = 0;
        while (e < n) {
            int x = nums[e];
            while ((usedBits & x) != 0) {
                usedBits ^= nums[s]; // remove left most number from range
                s++;
            }
            // Add x to usedBits accumulate (using or ope)
            usedBits |= x;
            ans = max(ans, e-s+1);
            e++;
        }
        return ans;
    }
};
