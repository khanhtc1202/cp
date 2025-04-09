/*
https://leetcode.com/problems/minimum-operations-to-make-array-values-equal-to-k/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        unordered_set<int> s;
        for (int x: nums) {
            if (x < k) return -1;
            else if (x > k) s.insert(x);
        }
        return s.size();
    }
};
