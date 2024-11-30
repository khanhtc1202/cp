/*
https://leetcode.com/problems/valid-arrangement-of-pairs/
*/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int, queue<int>> adj;
        unordered_map<int, int> inDegree, outDegree;

        for (const auto& p: pairs) {
            int start = p[0], end = p[1];
            adj[start].push(end);
            inDegree[end]++;
            outDegree[start]++;
        }

        vector<int> res;
        int startNode = -1;
        // find start node (outDegree = inDegree+1)
        for (const auto& e: outDegree) {
            int node = e.first;
            if (outDegree[node] == inDegree[node]+1) {
                startNode = node;
                break;
            }
        }
        // if not that condition, then every node can be start node, it's a cycle
        if (startNode == -1) {
            startNode = pairs[0][0];
        }

        vector<int> nodeStk;
        nodeStk.push_back(startNode);
        // Iterative DFS
        while (!nodeStk.empty()) {
            int node = nodeStk.back();
            if (!adj[node].empty()) {
                int nextNode = adj[node].front();
                adj[node].pop();
                nodeStk.push_back(nextNode);
            } else { // No more neighbor to visit
                // This node must be in the res since no way to go from this node
                res.push_back(node);
                nodeStk.pop_back();
            }
        }

        // collected node in reverse order (prev: res.push_back), so need to reverse
        reverse(res.begin(), res.end());
        vector<vector<int>> ans;
        for (int i = 1; i < res.size(); ++i) {
            ans.push_back({res[i-1], res[i]});
        }
        return ans;
    }
};
