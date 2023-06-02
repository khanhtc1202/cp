/*
https://leetcode.com/problems/detonate-the-maximum-bombs/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumDetonation(vector<vector<int>>& bombs) {
        int n = bombs.size();
        vector<vector<int>> graph(n);

        for (int i = 0; i < n; i++) {
            int xi = bombs[i][0], yi = bombs[i][1], ri = bombs[i][2];
            for (int j = 0; j < n; j++) {
                int xj = bombs[j][0], yj = bombs[j][1];
                if ((long)ri * ri >= (long)(xi - xj)*(xi - xj) + (long)(yi - yj)*(yi - yj)) {
                    graph[i].push_back(j);
                }
            }
        }

        auto bfs = [&](int p) -> int {
            unordered_set<int> visited;
            queue<int> q;
            q.push(p);
            visited.insert(p);

            while (!q.empty()) {
                int u = q.front(); q.pop();
                for (int v: graph[u]) {
                    if (visited.find(v) != visited.end()) continue;

                    visited.insert(v);
                    q.push(v);
                }
            }
            return visited.size();
        };

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans = max(ans, bfs(i));
        }
        return ans;
    }
};
