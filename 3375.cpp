/*
https://leetcode.com/problems/minimum-operations-to-make-array-values-equal-to-k/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int min_e = *min_element(nums.begin(), nums.end());
        if (min_e < k) return -1;
        unordered_set<int> s(nums.begin(), nums.end());
        return min_e == k ? s.size() - 1 : s.size();
    }
};
