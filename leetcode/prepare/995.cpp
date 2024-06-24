/*
https://leetcode.com/problems/minimum-number-of-k-consecutive-bit-flips/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size();

        vector<int> cnt(n + 1, 0);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            cnt[i] += (i ? cnt[i - 1] : 0);
            if ((nums[i] + cnt[i] + 1) & 1) {
                if (i + k <= n) {
                    ans++;
                    cnt[i]++; cnt[i + k]--;
                }
                else return -1;
            }
        }
        return ans;
    }
};
