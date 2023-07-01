/*
https://leetcode.com/problems/intersection-of-two-arrays-ii/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        if (nums1.size() > nums2.size())
            return intersect(nums2, nums1);

        int ca[1001] = {};
        for (auto a: nums1) ca[a]++;
        vector<int> ans;
        for (auto b: nums2)
            if (ca[b]-- > 0) ans.push_back(b);

        return ans;
    }
};
