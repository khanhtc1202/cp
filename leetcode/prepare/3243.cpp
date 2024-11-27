/*
https://leetcode.com/problems/shortest-distance-after-road-addition-queries-i/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int bfs(int n, vector<vector<int>>& adj) {
        vector<bool> visited(n, false);
        queue<int> q;
        q.push(0); visited[0] = true;

        int jump = 0;
        int currLayerCount = 1;
        int nextLayerCount = 0;

        while (!q.empty()) {
            for (int i = 0; i < currLayerCount; ++i) {
                int node = q.front(); q.pop();
                if (node == n-1) return jump;

                for (auto nei: adj[node]) {
                    if (visited[nei]) continue;
                    q.push(nei);
                    visited[nei] = true;
                    nextLayerCount++;
                }
            }
            currLayerCount = nextLayerCount;
            nextLayerCount = 0;
            jump++;
        }
        return -1;
    }

    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<int> ans;
        vector<vector<int>> adj(n, vector<int>(0));
        for (int i = 0; i < n-1; ++i) {
            adj[i].push_back(i+1);
        }
        for (auto& road: queries) {
            int u = road[0], v = road[1];
            adj[u].push_back(v);
            ans.push_back(bfs(n, adj));
        }
        return ans;
    }
};
