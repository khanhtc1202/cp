/*
https://leetcode.com/problems/sort-array-by-increasing-frequency/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> frequencySort(vector<int>& nums) {
        unordered_map<int,int> mp_count;
        for(size_t i = 0; i < nums.size(); ++i) {
            ++mp_count[nums[i]];
        }

        sort(nums.begin(), nums.end(), [&](int a, int b) {
            if (mp_count[a] == mp_count[b]) return a > b;
            return mp_count[a] < mp_count[b];
        });
        return nums;
    }
};
