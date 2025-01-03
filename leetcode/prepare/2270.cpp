/*
https://leetcode.com/problems/number-of-ways-to-split-array/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        long long acc = 0;
        for (int x: nums) acc += x;
        int ans = 0; long long l = 0, r = acc;
        for (int i = 0; i < nums.size()-1; ++i) {
            int x = nums[i];
            l += x; r -= x;
            if (l >= r) ans++;
        }
        return ans;
    }
};
