/*
https://leetcode.com/problems/sort-even-and-odd-indices-independently/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> sortEvenOdd(vector<int>& nums) {
        priority_queue<int> pq1;
        priority_queue<int, vector<int>, greater<int>> pq2;
        for (int i = 0; i < nums.size(); ++i) {
            if (i % 2) pq1.push(nums[i]);
            else pq2.push(nums[i]);
        }

        vector<int> ans;
        for (int i = 0; i < nums.size(); ++i) {
            if (i % 2) {
                ans.push_back(pq1.top());
                pq1.pop();
            } else {
                ans.push_back(pq2.top());
                pq2.pop();
            }
        }
        return ans;
    }
};
