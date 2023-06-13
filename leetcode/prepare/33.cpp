/*
https://leetcode.com/problems/search-in-rotated-sorted-array/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int binarySearch(vector<int>& nums, int left, int right, int target) {
        while (left <= right) {
            int mid = (left+right)/2;
            if (nums[mid] == target) return mid;
            if (nums[mid] < target) left = mid+1;
            else right = mid-1;
        }
        return -1;
    }
    
    int rotateIndex(vector<int>& nums) {
        int n = nums.size();
        if (nums[0] < nums[n-1]) return 0;
        
        int left = 0, right = n-1; int pos = 0;
        while (left <= right) {
            int pivot = (right+left)/2;
            if (nums[pivot] > nums[pivot+1]) return pivot+1;
            else {
                if (nums[pivot] < nums[left]) right = pivot - 1;
                else left = pivot + 1;
            }
        }
        return 0;
    }

    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 1) return target == nums[0] ? 0 : -1;

        int pivot = rotateIndex(nums);
        
        if (pivot == 0)
            return binarySearch(nums, 0, n-1, target);
        else {
            if (target < nums[0]) return binarySearch(nums, pivot, n-1, target);
            else return binarySearch(nums, 0, pivot-1, target);
        }
    }

    int searchOpt(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        while (l <= r) {
            int mid = l + (r-l)/2;
            if (nums[mid] == target) return mid;

            if (nums[l] <= nums[mid]) {
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
        return -1;
    }
};
