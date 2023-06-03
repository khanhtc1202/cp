/*
https://leetcode.com/problems/time-needed-to-inform-all-employees/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<vector<int>> adj(n);
        for (int i = 0; i < n; i++) {
            if (i == headID) continue;
            adj[manager[i]].push_back(i);
        }

        queue<pair<int,int>> q;
        q.push({headID, 0});
        int ans = 0;
        while (!q.empty()) {
            auto [u, t] = q.front(); q.pop();
            for (auto v: adj[u]) {
                int _t = t + informTime[u];
                q.push({v, _t});
                ans = max(ans, _t);
            }
        }
        return ans;
    }
};
