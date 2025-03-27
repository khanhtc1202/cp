/*
https://leetcode.com/problems/minimum-index-of-a-valid-split/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumIndex(vector<int>& nums) {
        unordered_map<int,int> first, second;
        int n = nums.size();

        for (auto x: nums) second[x]++;

        for (int i = 0; i < n; ++i) {
            int x = nums[i];
            second[x]--; first[x]++;

            if (first[x] * 2 > i+1 &&
                second[x] * 2 > n-i-1) {
                    return i; // minimum possible
                }
        }
        return -1;
    }
};
