/*
https://leetcode.com/problems/subarrays-with-k-different-integers/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarrayAtmostK(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        int cnt = 0;
        for (int l = 0, r = 0; r < nums.size(); ++r) {
            ++freq[nums[r]];
            while (freq.size() > k) {
                --freq[nums[l]];
                if (freq[nums[l]] == 0) freq.erase(nums[l]);
                ++l;
            }
            cnt += (r-l+1);
        }
        return cnt;
    }

    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return subarrayAtmostK(nums, k) - subarrayAtmostK(nums, k-1);
    }
};
