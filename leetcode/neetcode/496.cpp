/*
Problem desc: https://leetcode.com/problems/next-greater-element-i/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> stk;
        unordered_map<int, int> mem;
        for (int i = 0; i < nums2.size(); i++) {
            while (!stk.empty() && nums2[i] > stk.top()) {
                mem[stk.top()] = nums2[i];
                stk.pop();
            }
            stk.push(nums2[i]);
        }

        while (!stk.empty()) {
            mem[stk.top()] = -1;
            stk.pop();
        }

        vector<int> ans(nums1.size());
        for (int i = 0; i < nums1.size(); i++) {
            ans[i] = mem[nums1[i]];
        }
        return ans;
    }
};
