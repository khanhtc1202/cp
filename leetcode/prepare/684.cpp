#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findRedundantConnectionVector(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<vector<int>> graph(n+1);
        bool seen[10001];

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
            memset(seen, false, 10001);
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

        function<bool(int, int)> dfs2 = [&](int src, int target) -> bool {
            if (src == target) return true;
            if (seen.count(src)) return false; // you can't reach the target if you're in a cycle.

            seen.insert(src);
            for (auto nei: graph[src])
                if (dfs(nei, target)) return true;

            return false;
        };

        // The original version of DFS, we only check whether we touch a vertice (node) on call DFS
        // If we saw that before, don't call DFS.
        function<bool(int, int)> dfsOriginal = [&](int src, int target) -> bool {
            if (src == target) return true;

            seen.insert(src);
            for (auto nei: graph[src])
                if (!seen.count(nei) && dfs(nei, target)) return true;

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
