/*
https://leetcode.com/problems/final-array-state-after-k-multiplication-operations-i/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> getFinalState(vector<int>& nums, int k, int mul) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<>> heap;
        for (int i = 0; i < nums.size(); ++i) {
            heap.push({nums[i], i});
        }
        while (k--) {
            auto [x, i] = heap.top(); heap.pop();
            nums[i] = x * mul;
            heap.push({nums[i], i});
        }
        return nums;
    }
};
