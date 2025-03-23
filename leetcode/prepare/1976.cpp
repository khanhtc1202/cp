/*
https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int mod = 1e9+7;

        vector<vector<pair<int, int>>> graph(n);
        for (auto r: roads) {
            int u = r[0], v = r[1], w = r[2];
            graph[u].push_back({v,w});
            graph[v].push_back({u,w});
        }

        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long,int>>> heap;
        heap.push({0, 0});
        
        vector<long long> dist(n, 2e11+1); dist[0] = 0;
        vector<int> count(n, 0); count[0] = 1;
        
        while (!heap.empty()) {
            auto [du, u] = heap.top(); heap.pop();
            if (du != dist[u]) continue;
            
            for (auto [v, wv]: graph[u]) {
                if (du+wv > dist[v]) continue;
                if (du+wv == dist[v]) {
                    count[v] = (count[v] + count[u]) % mod;
                    continue;
                }
                count[v] = count[u];
                dist[v] = du+wv;
                heap.push({dist[v], v});
            }
        }
        // for (auto c: count) cout << c << "\n";
        return count[n-1];
    }
};
