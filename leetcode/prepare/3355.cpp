/*
https://leetcode.com/problems/zero-array-transformation-i/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> del(n+1, 0);

        // difference array approach to store the state
        for (const auto& q: queries) {
            int left = q[0], right = q[1];
            del[left] += 1;
            del[right+1] -= 1;
        }

        // Count all possible operations on each element
        vector<int> operations;
        int current = 0;
        for (int d: del) {
            current += d;
            operations.push_back(current);
        }

        // check possible
        for (int i = 0; i < n; ++i) {
            if (operations[i] < nums[i])
                return false;
        }
        return true;
    }
};
