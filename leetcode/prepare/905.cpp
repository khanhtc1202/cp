/*
https://leetcode.com/problems/sort-array-by-parity/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n-1;
        while (l <= r) {
            if (nums[l] % 2 == 0) { l++; continue; }
            if (nums[r] % 2 == 1) { r--; continue; }
            // l odd, r even
            swap(nums[l], nums[r]);
            l++; r--;
        }
        return nums;
    }
};
