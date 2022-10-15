#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int> count(graph.size(), 0);
        vector<int> visited(graph.size(), 0);
        
        function<bool(int)> dfs = [&](int u) -> bool {
            visited[u] = 1;
            if (graph[u].size() == 0) count[u] = 1;
            if (count[u]) return true;
            for (int i = 0; i < graph[u].size(); i++) {
                int v = graph[u][i];
                if (visited[v]) {
                    if (!count[v]) return false;
                }
                if (!dfs(v)) return false;
            }
            count[u] = 1;
            return true;
        };
        
        for (int i = 0; i < graph.size(); i++) {
            
            if (!count[i]) dfs(i);
        }
        
        vector<int> res;
        for (int i = 0; i < count.size(); i++) {
            if (count[i]) res.push_back(i);
        }
        return res;
    }

    vector<int> eventualSafeNodesTopo(vector<vector<int>>& graph) {
        int sz = graph.size();
        vector<vector<int>> r_graph(sz);
        vector<int> indegree(sz, 0);
        for (int i = 0; i < sz; i++) {
            for (auto j: graph[i]) {
                r_graph[j].push_back(i);
                indegree[i]++;
            }
        }
        
        queue<int> zero_indegree;
        for (int i = 0; i < indegree.size(); i++) {
            if (!indegree[i]) zero_indegree.push(i);
        }
        
        vector<int> res;
        while (!zero_indegree.empty()) {
            int u = zero_indegree.front();
            zero_indegree.pop();
            res.push_back(u);
            
            for (auto v: r_graph[u]) {
                indegree[v]--;
                if (!indegree[v]) zero_indegree.push(v);
            }
        }
        
        sort(res.begin(), res.end());
        return res;
    }
};
