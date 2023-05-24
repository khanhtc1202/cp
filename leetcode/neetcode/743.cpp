/*
https://leetcode.com/problems/network-delay-time/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
    const int INF = 1e4+1;
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {        
        vector<int> dist(n, INF); dist[k-1] = 0;

        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, k-1});

        vector<vector<pair<int, int>>> adj(n);
        for (auto edge: times) {
            adj[edge[0] - 1].push_back({edge[1] - 1, edge[2]});
        }

        while (!pq.empty()) {
            int d = pq.top().first;
            int u = pq.top().second;
            pq.pop();

            if (dist[u] < d) {
                continue;
            }

            for (auto nei: adj[u]) {
                int v = nei.first, w = nei.second;

                if (dist[v] <= w+d) continue;

                dist[v] = w+d;
                pq.push({dist[v], v});
            }
        }

        int ans = *max_element(dist.begin(), dist.end());
        return ans == INF ? -1 : ans;
    }
};
