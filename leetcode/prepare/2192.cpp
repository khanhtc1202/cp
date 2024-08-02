/*
https://leetcode.com/problems/all-ancestors-of-a-node-in-a-directed-acyclic-graph/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
    void dfs(int curr, vector<vector<int>>& adj, unordered_set<int>& visited) {
        visited.insert(curr);
        for (int nei: adj[curr]) {
            if (visited.find(nei) == visited.end()) {
                dfs(nei, adj, visited);
            }
        }
    }
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adj(n);
        // build adjacency list in revert edges
        for (auto& edge: edges) {
            int from = edge[0];
            int to = edge[1];
            adj[to].push_back(from);
        }

        vector<vector<int>> ans;
        for (int i = 0; i < n; ++i) {
            vector<int> ancestors;
            unordered_set<int> visited;
            dfs(i, adj, visited);
            // add all visited (aka ancestors) to ans[i]
            for (int node = 0; node < n; ++node) {
                if (node == i) continue;
                if (visited.find(node) != visited.end()) {
                    ancestors.push_back(node);
                }
            }
            ans.push_back(ancestors);
        }
        return ans;
    }
};
