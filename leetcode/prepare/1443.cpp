/*
https://leetcode.com/problems/minimum-time-to-collect-all-apples-in-a-tree/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adj(n);
        for (auto e: edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int ans = 0;
        vector<bool> visited(n, false);
        function<bool(int)> dfs = [&](int v) -> bool {
            visited[v] = true;
            if (adj[v].empty()) return hasApple[v];

            bool path = false;
            for (int nei: adj[v]) {
                if (visited[nei]) continue;

                if (dfs(nei) || hasApple[nei]) {
                    path = true;
                    ans += 2;
                }
            }
            return path;
        };

        dfs(0);
        return ans;
    }
};
