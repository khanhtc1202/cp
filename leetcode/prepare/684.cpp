#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findRedundantConnectionVector(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> graph(n+1);
        vector<bool> seen(n+1, false);

        function<bool(int, int)> dfs = [&](int src, int target) -> bool {
            if (!seen[src]) {
                seen[src] = true;
                if (src == target) return true;
                for (auto nei: graph[src])
                    if (dfs(nei, target)) return true;
            }
            return false;
        };

        for (auto edge: edges) {
            int u = edge[0], v = edge[1];
            memset(&seen[0], 0, sizeof(seen[0]) * seen.size());
            if (!graph[u].empty() && !graph[v].empty() && dfs(u, v))
                return edge;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        return {};
    }

    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> graph(n+1);
        unordered_set<int> seen;

        function<bool(int, int)> dfs = [&](int src, int target) -> bool {
            if (seen.find(src) == seen.end()) {
                seen.insert(src);
                if (src == target) return true;
                for (auto nei: graph[src])
                    if (dfs(nei, target)) return true;
            }
            return false;
        };

        for (auto edge: edges) {
            int u = edge[0], v = edge[1]; seen.clear();
            if (!graph[u].empty() && !graph[v].empty() && dfs(u, v))
                return edge;
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        return {};
    }
};
