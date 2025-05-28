/*
https://leetcode.com/problems/maximize-the-number-of-target-nodes-after-connecting-trees-i/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    // Count number of node that distance at most k from node
    int dfs(int node, int parent, const vector<vector<int>>& neigh, int k) {
        if (k < 0) {
            return 0;
        }
        int res = 1;
        for (int next: neigh[node]) {
            if (next == parent) continue;
            res += dfs(next, node, neigh, k-1);
        }
        return res;
    }

    // Build array of node count, for each node of given tree
    vector<int> build(const vector<vector<int>>& edges, int k) {
        int n = edges.size() + 1;
        vector<vector<int>> neigh(n);
        for (const auto& e: edges) {
            neigh[e[0]].push_back(e[1]);
            neigh[e[1]].push_back(e[0]);
        }

        vector<int> res(n);
        for (int i = 0; i < n; ++i) {
            res[i] = dfs(i, -1, neigh, k);
        }
        return res;
    }

    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        // Find the best node in tree2 which has the most target node
        // aka. nodes that distance at most k-1 from a given node in tree 2
        // -> all node in tree 1 just need to connect to that node
        vector<int> count2 = build(edges2, k-1);
        int maxCount2 = *max_element(count2.begin(), count2.end());

        // ans first contains all count for number of nodes in tree 1
        // that distance at most k from a given node
        vector<int> ans = build(edges1, k);
        int n = edges1.size()+1;
        for (int i = 0; i < n; ++i) {
            ans[i] += maxCount2;
        }
        return ans;
    }
};
