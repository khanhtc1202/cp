/*
https://leetcode.com/problems/intersection-of-two-arrays/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> appear(1001);
        for (int x: nums1) appear[x] = 1;
        vector<int> ans;
        for (int x: nums2) {
            if (appear[x] == 1) {
                ans.push_back(x);
                appear[x] = 2;
            }
        }
        return ans;
    }
};
