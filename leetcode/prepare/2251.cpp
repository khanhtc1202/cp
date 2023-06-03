/*
https://leetcode.com/problems/number-of-flowers-in-full-bloom/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> fullBloomFlowers(vector<vector<int>>& flowers, vector<int>& people) {
        sort(flowers.begin(), flowers.end());
        int n = people.size();
        vector<int> idx(n);
        for (int i = 0; i < n; i++) idx[i] = i;
        sort(idx.begin(), idx.end(), [&](int i, int j) {
            return people[i] < people[j];
        });

        priority_queue<int, vector<int>, greater<int>> bucket;
        int f_idx = 0;
        vector<int> ans(n);
        for (int i: idx) {
            while (f_idx < flowers.size() && flowers[f_idx][0] <= people[i]) {
                bucket.push(flowers[f_idx++][1]);
            }
            while (!bucket.empty() && bucket.top() < people[i]) {
                bucket.pop();
            }
            ans[i] = bucket.size();
        }
        return ans;
    }
};
