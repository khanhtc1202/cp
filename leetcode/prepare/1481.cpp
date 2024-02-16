/*
https://leetcode.com/problems/least-number-of-unique-integers-after-k-removals/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findLeastNumOfUniqueInts(vector<int>& arr, int k) {
        unordered_map<int,int> freq;
        for (auto x: arr) freq[x]++;
        priority_queue<int, vector<int>, greater<int>> pq;
        for (const auto& e : freq) pq.push(e.second);
        while (k > 0 && !pq.empty()) {
            k -= pq.top();
            pq.pop();
        }
        return k == 0 ? pq.size() : pq.size() + 1;
    }
};
