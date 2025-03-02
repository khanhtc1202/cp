/*
https://leetcode.com/problems/merge-two-2d-arrays-by-summing-values/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> mergeArrays(vector<vector<int>>& nums1, vector<vector<int>>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<vector<int>> ans = {};
        int i = 0, j = 0;
        while (i < n && j < m) {
            int idi = nums1[i][0], idj = nums2[j][0];
            if (idi == idj) {
                ans.push_back({idi, nums1[i][1]+nums2[j][1]});
                ++i; ++j;
            } else if (idi > idj) {
                ans.push_back(nums2[j]);
                ++j;
            } else {
                ans.push_back(nums1[i]);
                ++i;
            }
        }
        while (i < n) {
            ans.push_back(nums1[i]);
            ++i;
        }
        while (j < m) {
            ans.push_back(nums2[j]);
            ++j;
        }
        return ans;
    }
};
