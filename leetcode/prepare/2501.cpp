/*
https://leetcode.com/problems/longest-square-streak-in-an-array/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int ans = 0;
        unordered_set<int> unique(nums.begin(), nums.end());

        for (int x: nums) {
            int currentStreak = 0;
            long long current = x;
            // Found the next until there is not found
            while (unique.find((int) current) != unique.end()) {
                currentStreak++;
                if (current * current > 1e5) break;
                current *= current;
            }

            ans = max(ans, currentStreak);
            // Cheating
            if (ans == 5) return 5;
        }
        return ans < 2 ? -1 : ans;
    }
};
