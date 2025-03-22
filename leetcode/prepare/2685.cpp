/*
https://leetcode.com/problems/count-the-number-of-complete-components/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countCompleteComponents(int n, vector<vector<int>>& edges) {
        vector<vector<int>> graph(n);
        for (const auto& e: edges) {
            graph[e[0]].push_back(e[1]);
            graph[e[1]].push_back(e[0]);
        }

        int ans = 0;
        unordered_set<int> visited;

        for (int v = 0; v < n; ++v) {
            if (visited.count(v)) continue; // skip visited

            int componentInfo[2] = {0, 0}; // 0 verties, 0 edges (directed)
            dfs(v, graph, visited, componentInfo);

            int vertiesCount = componentInfo[0];
            int edgesCount = componentInfo[1];
            if (vertiesCount * (vertiesCount - 1) == edgesCount) {
                ans++;
            }
        }
        return ans;
    }
private:
    void dfs(int v, vector<vector<int>>& graph, unordered_set<int>& visited, int componentInfo[2]) {
        visited.insert(v);
        componentInfo[0]++;
        componentInfo[1] += graph[v].size();

        // explore neighbor
        for (auto nei: graph[v]) {
            if (!visited.count(nei)) {
                dfs(nei, graph, visited, componentInfo);
            }
        }
    }
};
