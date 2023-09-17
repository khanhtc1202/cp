/*
https://leetcode.com/problems/shortest-path-visiting-all-nodes/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    using iii = tuple<int,int,int>;
    using ii = pair<int,int>;

    int shortestPathLength(vector<vector<int>>& graph) {
        const int n = graph.size();
        const int allMask = (1<<n) - 1; // 11...1 <- n digit
        vector<vector<bool>> path(1<<n, vector<bool>(n, 0)); // path[mask][vertex] <- visit mask by visit vertex

        if (n == 1) return 0;

        queue<iii> q;
        for (int i = 0; i < n; ++i) {
            int mask = 1<<i;
            q.emplace(0, i, mask); // distance | vertex | visited
            path[mask][i] = 1;
        }

        while (!q.empty()) {
            auto [dis, u, mask] = q.front(); q.pop();
            if (mask == allMask) return dis;

            for (auto v: graph[u]) {
                int vMask = mask | (1<<v); // visit v;
                if (path[vMask][v] == 0) { // never reach all vMask by visit v before
                    path[vMask][v] = 1;
                    q.emplace(dis+1, v, vMask);
                }
            }
        }
        return -1;
    }
};
