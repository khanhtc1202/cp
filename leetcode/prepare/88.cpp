/*
https://leetcode.com/problems/merge-sorted-array/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        if (n == 0) return;
        if (m == 0) {
            nums1 = nums2;
            return;
        }
        vector<int> tmp;
        int i1 = 0, i2 = 0;
        while (i1 < m && i2 < n) {
            if (nums1[i1] <= nums2[i2]) {
                tmp.push_back(nums1[i1]);
                i1++;
            } else {
                tmp.push_back(nums2[i2]);
                i2++;
            }
        }
        
        while (i1 < m) {
            tmp.push_back(nums1[i1]);
            i1++;
        }
        
        while (i2 < n) {
            tmp.push_back(nums2[i2]);
            i2++;
        }
        nums1 = tmp;
        return;
    }
};
