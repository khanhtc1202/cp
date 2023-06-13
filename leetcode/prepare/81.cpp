/*
https://leetcode.com/problems/search-in-rotated-sorted-array-ii/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = l + (r-l)/2;
            if (nums[mid] == target) return true;

            if (nums[l] == nums[mid]) {
                l++; continue;
            }

            if (nums[r] == nums[mid]) {
                r--; continue;
            }

            if (nums[l] < nums[mid]) {
                if (nums[l] <= target && nums[mid] > target) {
                    r = mid-1;
                } else {
                    l = mid+1;
                }
            } else {
                if (nums[mid] < target && nums[r] >= target) {
                    l = mid+1;
                } else {
                    r = mid-1;
                }
            }
        }
        return false;
    }
};
