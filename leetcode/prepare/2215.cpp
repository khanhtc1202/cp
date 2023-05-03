/*
https://leetcode.com/problems/find-the-difference-of-two-arrays/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> n1, n2;
        vector<int> ex1, ex2;

        for (int i = 0; i < nums1.size(); i++)
            n1.insert(nums1[i]);

        for (int i = 0; i < nums2.size(); i++) {
            if (n2.find(nums2[i]) != n2.end()) continue;

            n2.insert(nums2[i]);
            if (n1.find(nums2[i]) == n1.end())
                ex2.push_back(nums2[i]);
            else
                n1.erase(nums2[i]);
        }

        ex1.assign(n1.begin(), n1.end());
        return {ex1, ex2};
    }
};
