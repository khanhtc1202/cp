/*
https://leetcode.com/problems/sort-an-array/description/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Counting sort.
    vector<int> sortArray(vector<int>& nums) {
        int minVal = *min_element(nums.begin(), nums.end());
        int maxVal = *max_element(nums.begin(), nums.end());

        unordered_map<int, int> count;
        for (auto e: nums) {
            count[e]++;
        }

        int idx = 0;
        for (int val = minVal; val <= maxVal; val++) {
            if (count.find(val) == count.end())
                continue;

            while (count[val]) {
                nums[idx] = val;
                count[val]--;
                idx++;
            }
        }
        return nums;
    }
};
