/*
https://leetcode.com/problems/is-graph-bipartite/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, 0);

        for (int i = 0; i < n; i++) {
            if (color[i] != 0) continue;

            vector<int> stk;
            stk.push_back(i);
            color[i] = 1;
            while (!stk.empty()) {
                int u = stk.back(); stk.pop_back();
                for (auto v: graph[u]) {
                    if (color[v] == 0) {
                        stk.push_back(v);
                        color[v] = -color[u];
                    }
                    if (color[v] == color[u]) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};
