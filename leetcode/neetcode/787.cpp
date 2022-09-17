#include <bits/stdc++.h>
using namespace std;

class Solution {
    const int INF = 1e9;
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto f: flights) {
            adj[f[0]].push_back({f[1], f[2]});
        }
        
        if (adj[src].size() == 0) return -1;
        
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        pq.push({0, 0, src});
        
        vector<int> stops(n, INF); stops[src] = 0;
        vector<int> dist(n, INF); dist[src] = 0;
        
        while (!pq.empty()) {
            int w = pq.top()[0];
            int d = pq.top()[1];
            int u = pq.top()[2];
            pq.pop();
            // reach the destination
            if (dst == u) return w;
            // over stopped
            if (d == k+1) continue;
            
            for (auto nei: adj[u]) {
                int v = nei.first, wv = nei.second;
                // better distance to reach v
                if (w + wv < dist[v]) {
                    dist[v] = w+wv;
                    stops[v] = d;
                    pq.push({dist[v], stops[v]+1, v});
                } else if (d < stops[v]) {
                    pq.push({w+wv, d+1, v});
                }
            }
        }
        return dist[dst] == INF ? -1 : dist[dst];
    }
};
