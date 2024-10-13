/*
https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        // {value, list index, element index}
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<>> minHeap;
        int maxVal = INT_MIN, rangeStart = 0, rangeEnd = INT_MAX;
        
        for (int i = 0; i < nums.size(); ++i) {
            minHeap.push({nums[i][0], {i, 0}});
            maxVal = max(maxVal, nums[i][0]);
        }
        
        while (minHeap.size() == nums.size()) {
            auto [minVal, indices] = minHeap.top();
            minHeap.pop();
            int row = indices.first, col = indices.second;
            // Update the smallest range
            if (maxVal - minVal < rangeEnd - rangeStart) {
                rangeStart = minVal;
                rangeEnd = maxVal;
            }
            // If possible, add the next element from the same row to the heap
            if (col + 1 < nums[row].size()) {
                int nextVal = nums[row][col+1];
                minHeap.push({nextVal, {row, col+1}});
                maxVal = max(maxVal, nextVal);
            }
        }
        return {rangeStart, rangeEnd};
    }
};
