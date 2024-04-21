/*
https://leetcode.com/problems/find-if-path-exists-in-graph/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        if (source == destination) return true;

        vector<vector<int>> graph(n, vector<int>());
        for (auto e: edges) {
            int u = e[0], v = e[1];
            graph[u].push_back(v);
            graph[v].push_back(u);
        }
        vector<int> stk;
        vector<bool> visited(n, false);
        stk.push_back(source);
        while (!stk.empty()) {
            int u = stk.back(); stk.pop_back();
            visited[u] = true;
            for (int v: graph[u]) {
                if (v == destination) return true;
                if (visited[v]) continue;
                stk.push_back(v);
            }
        }
        return false;
    }
};
