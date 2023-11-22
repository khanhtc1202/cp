/*
https://leetcode.com/problems/diagonal-traverse-ii/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        unordered_map<int,vector<int>> group;
        for (int row = nums.size() - 1; row >= 0; --row) {
            for (int col = 0; col < nums[row].size(); ++col) {
                int diag = row+col;
                // bigger row come first
                // same diag sum grouped
                group[diag].push_back(nums[row][col]);
            }
        }

        vector<int> ans;
        int curr = 0;
        while (group.find(curr) != group.end()) {
            for (int num: group[curr]) {
                ans.push_back(num);
            }
            curr++;
        }
        return ans;
    }

    vector<int> findDiagonalOrder_BFS(vector<vector<int>>& nums) {
        queue<pair<int, int>> queue;
        queue.push({0, 0});
        vector<int> ans;
        
        while (!queue.empty()) {
            auto [row, col] = queue.front();
            queue.pop();
            ans.push_back(nums[row][col]);
            
            if (col == 0 && row + 1 < nums.size()) {
                queue.push({row + 1, col});
            }
            
            if (col + 1 < nums[row].size()) {
                queue.push({row, col + 1});
            }
        }
        
        return ans;
    }
};
