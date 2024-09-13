/*
https://leetcode.com/problems/xor-queries-of-a-subarray/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> res;

        // Build prefix XOR array
        for (int i = 1; i < arr.size(); ++i) {
            arr[i] ^= arr[i-1];
        }

        // Cal res
        for (const auto& q: queries) {
            if (q[0] > 0) {
                // ans = [0..q0-1] ^ [0..q1]
                res.push_back(arr[q[0]-1] ^ arr[q[1]]);
            } else res.push_back(arr[q[1]]);
        }
        return res;
    }
};
