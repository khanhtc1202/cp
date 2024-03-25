/*
https://leetcode.com/problems/find-all-duplicates-in-an-array/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> ans;
        for (int i = 0; i < nums.size(); ++i) {
            // get the index as value of the current num
            // aka. it's real index if in array of [1..n]
            int idx = abs(nums[i]) - 1;
            if (nums[idx] < 0) { // seen
                ans.push_back(idx+1);
            } else { // not seen, mark the number at index = num as negative
                nums[idx] = -nums[idx];
            }
        }
        return ans;
    }
};
