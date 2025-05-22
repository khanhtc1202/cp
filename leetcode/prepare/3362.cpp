/*
https://leetcode.com/problems/zero-array-transformation-iii/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxRemoval(vector<int>& nums, vector<vector<int>>& queries) {
        sort(queries.begin(), queries.end(),
             [](const vector<int>& a, const vector<int>& b) {
                 return a[0] < b[0];
             });

        priority_queue<int> heap; // max heap of farest right
        vector<int> deltaArray(nums.size()+1, 0); // diff array
        int ope = 0;

        for (int i = 0, j = 0; i < nums.size(); ++i) {
            ope += deltaArray[i];
            // Find all queries with left == i
            while (j < queries.size() && queries[j][0] == i) {
                heap.push(queries[j][1]);
                ++j;
            }
            // Use all possible queries with farest right first
            // to substract nums[i] -> greedy
            while (ope < nums[i] && !heap.empty() && heap.top() >= i) {
                ope += 1;
                // apply the query with diff array approach
                deltaArray[heap.top()+1] -= 1;
                heap.pop();
            }
            // all queries applied, but ope still not be zero
            if (ope < nums[i]) {
                return -1;
            }
        }
        return heap.size();
    }
};
