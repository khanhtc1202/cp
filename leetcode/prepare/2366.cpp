/*
https://leetcode.com/problems/minimum-replacements-to-sort-the-array/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long minimumReplacement(vector<int>& nums) {
        long long ops = 0;
        int last = nums.back();
        for (int i = nums.size() - 2; i >= 0; --i) {
            int op = (nums[i] - 1) / last;
            ops += op;

            last = nums[i] / (op+1);
        }
        return ops;
    }
};
