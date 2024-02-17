/*
https://leetcode.com/problems/furthest-building-you-can-reach/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>> pq;
        int acc_b = 0;
        for (int i = 1; i < heights.size(); ++i) {
            int x = heights[i] - heights[i-1];
            if (x < 0) continue;

            if (pq.size() < ladders) {
                pq.push(x);
            } else {
                if (!pq.empty() && pq.top() < x) {
                    pq.push(x);
                    x = pq.top(); pq.pop();
                }
                acc_b += x;
                if (acc_b > bricks) return i-1;
            }
        }
        return heights.size()-1;
    }
};
