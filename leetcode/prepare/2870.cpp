/*
https://leetcode.com/problems/minimum-number-of-operations-to-make-array-empty/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int, int> mp;
        for (auto x: nums) mp[x]++;
        int ans = 0;
        for (auto it: mp) {
            if (it.second == 1) return -1;
            ans += ceil(it.second/3.0);
        }
        return ans;
    }
};
