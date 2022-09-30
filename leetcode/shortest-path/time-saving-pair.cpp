#include <bits/stdc++.h>
using namespace std;


int main() {
    int n; cin >> n;
    int k; cin >> k;
    int m; cin >> m;
    vector<vector<pair<int, int>>> graph(n+1);
    while (m--) {
        int u, v, w;
        cin >> u >> v >> w;
        graph[u].push_back({v, w});
        graph[v].push_back({u, w});
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
    heap.push({0, 1});

    vector<int> dist(n+1, 1e9+1);
    dist[1] = 0;
    
    while (!heap.empty()) {
        int u = heap.top().second;
        int w = heap.top().first;
        heap.pop();
        
        if (w > dist[u]) continue;

        for (auto nei: graph[u]) {
            int v = nei.first;
            int wv = nei.second;
            if ((dist[u] / k) % 2) {
                wv += k - (dist[u] % k);
            }
            if (dist[u]+wv >= dist[v]) {
                continue;
            }
            dist[v] = dist[u]+wv;
            heap.push({dist[v], v});
        }
    }

    cout << dist[n] << "\n";

    return 0;
}
