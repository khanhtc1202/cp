/*
https://leetcode.com/problems/minimum-time-to-make-rope-colorful/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int n = colors.size();
        int l = 0, r = 1;
        int ans = 0;
        while (r < n) {
            int remain = neededTime[l], sum = neededTime[l];
            bool removed = false;
            while (colors[r] == colors[l]) {
                removed = true;
                remain = max(remain, neededTime[r]);
                sum += neededTime[r];
                r++;
            }
            if (removed) ans += (sum - remain);
            l = r;
            r++;
        }
        return ans;
    }

    int minCost_Rewrite(string colors, vector<int>& neededTime) {
        int n = colors.size();
        int l = 0;
        int remove = 0, localMax = 0;
        for (int r = 0; r < n;) {
            while (r < n && colors[r] == colors[l]) {
                localMax = max(localMax, neededTime[r]);
                remove += neededTime[r];
                r++;
            }
            remove -= localMax;
            localMax = 0; // reset
            l = r;
        }
        return remove;
    }
};