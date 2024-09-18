/*
https://leetcode.com/problems/largest-number/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string largestNumber(vector<int>& nums) {
        int sz = nums.size();
        vector<string> tmp(sz);
        for (int i = 0; i < sz; i++) {
            tmp[i] = to_string(nums[i]);
        }
        sort(tmp.begin(), tmp.end(), [] (string& s1, string& s2) {
            return s1 + s2 > s2 + s1;
        });
        string out = "";
        if (tmp[0] == "0") return "0";
        for (int i = 0; i < sz; i++) {
            out += tmp[i];
        }
        return out;
    }
};
