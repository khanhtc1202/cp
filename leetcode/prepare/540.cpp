/*
https://leetcode.com/problems/single-element-in-a-sorted-array/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n = nums.size();
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = l + (r-l)/2;
            if (mid % 2 == 0) {
                if (mid+1 < n && nums[mid] == nums[mid+1]) {
                    l = mid+2;
                } else if (mid-1 >= 0 && nums[mid] == nums[mid-1]) {
                    r = mid-2;
                } else {
                    return nums[mid];
                }
            } else {
                if (mid-1 >= 0 && nums[mid] == nums[mid-1]) {
                    l = mid+1;
                } else if (mid+1 < n && nums[mid] == nums[mid+1]) {
                    r = mid-1;
                } else {
                    return nums[mid];
                }
            }
        }
        return nums[l];
    }
};
