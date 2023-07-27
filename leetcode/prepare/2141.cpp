/*
https://leetcode.com/problems/maximum-running-time-of-n-computers/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxRunTime(int n, vector<int>& batteries) {
        int sz = batteries.size();
        sort(batteries.begin(), batteries.end());
        long extra = 0;
        for (int i = 0; i < sz - n; ++i) {
            extra += batteries[i];
        }

        // Iterate through last n largest batteries
        for (int i = sz - n, cnt = 0; cnt < n - 1; ++i, ++cnt) {
            // Extra can't add more (cnt+1) the sub live[i+1] - live[i]
            int requiredPower = (long)(cnt+1) * (batteries[i+1] - batteries[i]);
            if (extra < requiredPower) {
                return batteries[i] + extra / long(cnt+1);
            }

            // Subtract the added power, and keep going
            extra -= requiredPower;
        }

        // Still extra left
        return batteries[sz-1] + extra / n;
    }
};
