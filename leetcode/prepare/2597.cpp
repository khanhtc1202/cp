/*
https://leetcode.com/problems/the-number-of-beautiful-subsets/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int beautifulSubsets(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        sort(nums.begin(), nums.end());
        int n = nums.size();

        function<int(int)> backtrack = [&] (int i) -> int {
            if (i == n) return 1;

            int total = backtrack(i+1); // no take
            
            // In case nums[i]-k does not existed in selected
            if (!freq[nums[i]-k]) {
                freq[nums[i]]++; // take nums[i]
                total += backtrack(i+1);
                freq[nums[i]]--; // un-take nums[i] - backtrack
            }
            return total;
        };

        return backtrack(0)-1;
    }
};
