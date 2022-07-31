#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for (auto edge: edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        vector<bool> visited(n, false);
        function<void(int)> dfs = [&](int u) -> void {
            visited[u] = true;
            for (auto v: graph[u])
                if (!visited[v]) dfs(v);
        };

        int count = 0;
        for (int i = 0; i < n; i++) {
            if (visited[i]) continue;
            count++; dfs(i);
        }
        return count;
    }
};
