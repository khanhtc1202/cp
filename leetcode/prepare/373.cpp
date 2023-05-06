/*
https://leetcode.com/problems/find-k-pairs-with-smallest-sums/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        int m = nums1.size(), n = nums2.size();
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> heap;
        for (int i = 0; i < m; i++) {
            heap.push({nums1[i] + nums2[0], i, 0});
        }

        vector<vector<int>> ans;
        while (k > 0 && !heap.empty()) {
            auto [s, i1, i2] = heap.top(); heap.pop();
            ans.push_back({nums1[i1], nums2[i2]});
            
            if (i2+1 < n) heap.push({nums1[i1] + nums2[i2+1], i1, i2+1});
            
            k--;
        }
        return ans;
    }
};
