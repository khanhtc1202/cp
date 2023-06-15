/*
https://leetcode.com/problems/number-of-nodes-in-the-sub-tree-with-the-same-label/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<int> ans(n, 0);
        vector<vector<int>> adj(n);
        for (auto e: edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        
        function<unordered_map<char,int>(int, int)> dfs = [&](int u, int v) -> unordered_map<char,int> {
            unordered_map<char, int> res;
            res[labels[v]]++;

            for (int nei: adj[v]) {
                if (u == nei) continue;

                auto childs = dfs(v, nei);
                for (auto kv: childs) {
                    res[kv.first] += kv.second;
                }
            }
            ans[v] = res[labels[v]];
            return res;
        };

        dfs(-1, 0);
        return ans;
    }
};
