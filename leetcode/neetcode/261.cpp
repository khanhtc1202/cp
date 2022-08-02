#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        // n vertices full connected graph with exactly n-1 edges is a tree!
        if (edges.size() != n-1) return false;

        vector<vector<int>> graph(n);
        for (auto edge: edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        unordered_set<int> seen;
        function<void(int)> dfs = [&](int u) -> void {
            if (seen.count(u)) return;
            seen.insert(u);
            for (auto v: graph[u])
                dfs(v);
        };

        dfs(0);
        return seen.size() == n;
    }

    bool validTreeSimple(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for (auto edge: edges) {
            graph[edge[0]].push_back(edge[1]);
            graph[edge[1]].push_back(edge[0]);
        }

        unordered_set<int> seen;
        function<bool(int, int)> dfs = [&](int u, int parent) -> bool {
            if (seen.count(u)) return false;
            seen.insert(u);
            for (auto v: graph[u]) {
                if (v == parent) continue;
                if (!dfs(v, u)) return false;
            }
            return true;
        };

        dfs(0, -1);
        return seen.size() == n;
    }
};
