/*
https://leetcode.com/problems/minimum-height-trees/description/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        unordered_map<int, vector<int>> adj;
        for (auto edge: edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> degree(n);
        vector<int> leaves;
        for (int i = 0; i < n; i++) {
            degree[i] = adj[i].size();
            if (degree[i] < 2) leaves.push_back(i);
        }

        int done = leaves.size();
        while (done < n) {
            vector<int> layer;
            for (auto leaf: leaves) {
                for (auto parent: adj[leaf]) {
                    degree[parent]--;

                    if (degree[parent] == 1) layer.push_back(parent);
                }
            }
            done += layer.size();
            leaves = layer;
        }
        return leaves;
    }
};
