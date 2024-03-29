/*
https://leetcode.com/problems/sort-colors/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int p0 = 0, curr = 0, p2 = n-1;
        while (curr <= p2) {
            if (nums[curr] == 0) {
                swap(nums[curr++], nums[p0++]);
            } else if (nums[curr] == 2) {
                swap(nums[curr], nums[p2--]);
            } else curr++;
        }
    }
};
